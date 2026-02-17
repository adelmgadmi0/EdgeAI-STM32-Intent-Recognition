/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include <string.h>
#include <ctype.h>
#include "ai_datatypes_defines.h"
#include "ai_platform.h"
#include "commands_model.h"
#include "commands_model_data.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim14;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM14_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define VOCAB_SIZE 33

// Define a struct to map a word to its array index
typedef struct {
    const char* word;
    int index;
} VocabEntry;

// Your exact vocabulary mapped to C
const VocabEntry vocabulary[VOCAB_SIZE] = {
    {"7ell", 0},
    {"activate", 1},
    {"can", 2},
    {"cha3el", 3},
    {"check", 4},
    {"chnowa", 5},
    {"current", 6},
    {"deactivate", 7},
    {"disable", 8},
    {"el", 9},
    {"enable", 10},
    {"give", 11},
    {"info", 12},
    {"is", 13},
    {"led", 14},
    {"light", 15},
    {"off", 16},
    {"on", 17},
    {"please", 18},
    {"power", 19},
    {"running", 20},
    {"sakker", 21},
    {"start", 22},
    {"state", 23},
    {"status", 24},
    {"stop", 25},
    {"switch", 26},
    {"system", 27},
    {"taffi", 28},
    {"the", 29},
    {"turn", 30},
    {"what", 31},
    {"you", 32}
};

// Converts the raw string into a tensor array for X-Cube-AI
void count_vectorizer(char *input_string, ai_float *tensor_out, int vocab_size) {
    // 1. Initialize the entire input tensor to 0.0
    for(int i = 0; i < vocab_size; i++) {
        tensor_out[i] = 0.0f;
    }

    // 2. Convert string to lowercase
    for(int i = 0; input_string[i]; i++) {
        input_string[i] = tolower((unsigned char)input_string[i]);
    }

    // 3. Tokenize (split by spaces and punctuation)
    const char *delimiters = " \t\n\r.,;:!?()\"{}";
    char *token = strtok(input_string, delimiters);

    // 4. Count words and map to tensor
    while(token != NULL) {
        // Look up the word in our vocabulary dictionary
        for(int i = 0; i < vocab_size; i++) {
            if(strcmp(token, vocabulary[i].word) == 0) {
                // Increment the count at the correct index
                tensor_out[vocabulary[i].index] += 1.0f;
                break; // Word found, stop searching the dictionary
            }
        }
        // Get the next word
        token = strtok(NULL, delimiters);
    }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
	char buf[150];
	int buf_len = 0;
	ai_error ai_err;
	ai_i32 nbatch;

	// UART receiving variables
	char rx_buf[100];
	uint8_t rx_idx = 0;
	uint8_t rx_byte;
	uint8_t cmd_ready = 0;

	// Chunk of memory used to hold intermediate values for neural network
	AI_ALIGNED(4) ai_u8 activations[AI_COMMANDS_MODEL_DATA_ACTIVATIONS_SIZE];

	// Buffers used to store input and output tensors
	AI_ALIGNED(4) ai_i8 in_data[AI_COMMANDS_MODEL_IN_1_SIZE_BYTES];
	AI_ALIGNED(4) ai_i8 out_data[AI_COMMANDS_MODEL_OUT_1_SIZE_BYTES];

	// Pointer to our model
	ai_handle commands_model = AI_HANDLE_NULL;

	// Initialize wrapper structs that hold pointers to data and info about the data
	ai_buffer *ai_input;
	ai_buffer *ai_output;

	// Set working memory and get weights/biases from model
	ai_network_params ai_params = {
	AI_COMMANDS_MODEL_DATA_WEIGHTS(ai_commands_model_data_weights_get()),
	AI_COMMANDS_MODEL_DATA_ACTIVATIONS(activations)
	};


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM14_Init();
  /* USER CODE BEGIN 2 */
  buf_len = sprintf(buf, "\r\n\r\nSTM32 Command Model Initializing...\r\n");
  HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);

	// Create instance of neural network
	ai_err = ai_commands_model_create(&commands_model, AI_COMMANDS_MODEL_DATA_CONFIG);
	if (ai_err.type != AI_ERROR_NONE)
	{
	  buf_len = sprintf(buf, "Error: could not create NN instance\r\n");
	  HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);
	  while(1);
	}

	// Initialize neural network
	if (!ai_commands_model_init(commands_model, &ai_params))
	{
	buf_len = sprintf(buf, "Error: could not initialize NN\r\n");
	HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);
	while(1);
	}
	ai_input = ai_commands_model_inputs_get(commands_model, NULL);
	ai_output = ai_commands_model_outputs_get(commands_model, NULL);

	// Tell the model to use our allocated in_data and out_data arrays
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	buf_len = sprintf(buf, "Model Ready. Send a command...\r\n");
	HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	if (HAL_UART_Receive(&huart2, &rx_byte, 1, 0) == HAL_OK)
	  {
		// If we receive a carriage return or newline, the command is finished
		if (rx_byte == '\r' || rx_byte == '\n')
		{
		  if (rx_idx > 0)
		  {
			rx_buf[rx_idx] = '\0'; // Null-terminate the string
			cmd_ready = 1;         // Flag that we are ready to process
		  }
		}
		else
		{
		  // Add character to buffer if there is space
		  if (rx_idx < sizeof(rx_buf) - 1)
		  {
			HAL_UART_Transmit(&huart2, &rx_byte, 1, 100);
			rx_buf[rx_idx++] = rx_byte;
		  }
		}
	  }
	if (cmd_ready){
		buf_len = sprintf(buf, "\r\nProcessing: '%s'\r\n", rx_buf);
		HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);

		// Convert the string into the 33-number float array
		count_vectorizer(rx_buf, (ai_float *)in_data, VOCAB_SIZE);

		// Perform inference
		nbatch = ai_commands_model_run(commands_model, ai_input, ai_output);
		if (nbatch != 1) {
			buf_len = sprintf(buf, "Error: could not run inference\r\n");
			HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);
		}
		float prob_on  = ((ai_float *)out_data)[0];   //  Index 0 is "ON"
		float prob_off = ((ai_float *)out_data)[1];   // Index 1 is "OFF"
		float prob_stat = ((ai_float *)out_data)[2]; // Index 2 is "Status"

		if(prob_on > 0.70f){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		}
		else if(prob_off > 0.70f){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		}
		else if(prob_stat >0.70f){
			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_SET){
				buf_len = sprintf(buf, "LED is ON\r\n");
				HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);
			}
			else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_RESET){
				buf_len = sprintf(buf, "LED is OFF\r\n");
				HAL_UART_Transmit(&huart2, (uint8_t *)buf, buf_len, 100);
			}

		}
		memset(rx_buf, 0, sizeof(rx_buf));
		rx_idx = 0;
		cmd_ready = 0;
	}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM14 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM14_Init(void)
{

  /* USER CODE BEGIN TIM14_Init 0 */

  /* USER CODE END TIM14_Init 0 */

  /* USER CODE BEGIN TIM14_Init 1 */

  /* USER CODE END TIM14_Init 1 */
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 180-1;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 65535;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM14_Init 2 */

  /* USER CODE END TIM14_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

# EdgeAI-STM32-Intent-Recognition
TinyML-based command intent recognition running on an STM32F446RE microcontroller.  This project demonstrates how natural language commands (English + Tunisian dialect) can be classified on-device using TensorFlow Lite for Microcontrollers — without cloud processing.
# STM32 TinyML Intent Recognition

> A TinyML-based UART command classifier running on an STM32F446RE. This project demonstrates how a small neural network can classify text commands (English + Tunisian dialect) directly on a microcontroller using **STM32Cube.AI**.

## 🚀 Overview

Instead of relying on traditional string matching (e.g., `strcmp`), this project leverages a trained neural network to classify incoming text commands into predefined intents. The model is deployed as Edge AI, meaning it runs entirely on the microcontroller with **zero cloud processing or internet connectivity required**. 

## 📦 Features

* **Runs Fully Offline (Edge AI):** All processing happens locally on the MCU.
* **Bilingual Support:** Understands intents in both English and Tunisian dialect.
* **Highly Optimized:** Uses X-CUBE-AI to generate memory-efficient C code tailored for STM32, minimizing RAM/Flash usage.
* **No External Sensors Required:** Operates strictly via UART text streams.

## 🎯 Supported Intents

| Intent | Expected Action | Example Triggers (English & Tunisian) |
| :--- | :--- | :--- |
| **`LED_ON`** | Turns the LED ON | *turn on led, activate, cha3el, 7ell* |
| **`LED_OFF`** | Turns the LED OFF | *turn off led, sakker, taffi* |
| **`STATUS`** | Returns system state | *status, state, chnowa status* |

## 🧠 Machine Learning Pipeline

* **Model Architecture:** Small Dense Neural Network
* **Data Input:** Bag-of-Words (BoW) vectorization
* **Model Output:** 3-class Softmax activation
* **Framework:** TensorFlow ➔ TensorFlow Lite (`.tflite`) ➔ STM32Cube.AI (X-CUBE-AI)
* **Deployment:** STM32Cube.AI compiles the `.tflite` model into an optimized C library integrated directly into the STM32 firmware.

## 🛠 Hardware Requirements

* **Development Board:** STM32F446RE Nucleo
* **Communication Protocol:** UART configured at **115200 baud**
* **Peripherals:** Onboard User LED (Pin PA5)


## 🧪 Example Usage

Send a command via your preferred serial terminal:
<img width="691" height="747" alt="screenshot intent recognition model" src="https://github.com/user-attachments/assets/30760777-b2a5-4165-b602-5fe6f85f83f0" />

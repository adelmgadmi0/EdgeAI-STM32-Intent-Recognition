import tensorflow as tf
import numpy as np
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.model_selection import train_test_split
import pickle

sentences = [
    # LED ON
    "turn on led", "turn on light", "activate led", "start light",
    "power on", "enable led", "switch on", "led on",
    "please turn on", "can you activate", "start the led",
    "light on", "enable the light", "switch the led on",
    "cha3el led", "cha3el", "7ell led", "7ell",
    "cha3el el led", "7ell el light",

    # LED OFF
    "turn off led", "turn off light", "stop led", "deactivate led",
    "power off", "disable led", "switch off", "led off",
    "please turn off", "can you stop", "stop the led",
    "light off", "disable the light", "switch the led off",
    "sakker led", "sakker", "taffi led", "taffi",
    "sakker el led", "taffi el light",

    # STATUS
    "status", "state", "what is state", "led status",
    "system status", "info", "give status", "check state",
    "what is the status", "current state",
    "is led on", "is system running",
    "chnowa status", "chnowa state", "chnowa info"
]

labels = (
    [0]*20 +
    [1]*20 +
    [2]*15
)

vectorizer = CountVectorizer(
    lowercase=True,
    stop_words=None,
    max_features=40  # keep small!
)

X = vectorizer.fit_transform(sentences).toarray()
y = np.array(labels)

print("Vocabulary:", vectorizer.vocabulary_)
print("Input shape:", X.shape)

print(vectorizer.vocabulary_)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

model = tf.keras.Sequential([
    tf.keras.layers.Dense(16, activation='relu', input_shape=(X.shape[1],)),
    tf.keras.layers.Dense(3, activation='softmax')
])

model.compile(
    optimizer='adam',
    loss='sparse_categorical_crossentropy',
    metrics=['accuracy']
)

model.summary()

model.fit(
    X_train, y_train,
    epochs=150,
    batch_size=4,
    verbose=1
)

loss, acc = model.evaluate(X_test, y_test)
print("Test Accuracy:", acc)

def predict(text):
    vec = vectorizer.transform([text]).toarray()
    pred = model.predict(vec)
    return np.argmax(pred)

print(predict("can you taffi led"))  # expect 0
print(predict("can you  led"))   # expect 1
print(predict("status"))         # expect 2

converter = tf.lite.TFLiteConverter.from_keras_model(model)
converter.optimizations = [tf.lite.Optimize.DEFAULT]

tflite_model = converter.convert()

with open("model.tflite", "wb") as f:
    f.write(tflite_model)

from google.colab import drive
drive.mount('/content/drive')

!xxd -i model.tflite > model_data.cc

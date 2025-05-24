# 🧠 Simple Neural Network in C++

Это простая библиотека на C++, реализующая конструктор нейронной сети с нуля. В основе лежит собственная реализация матричной арифметики без сторонних библиотек.

## 🔧 Особенности

- Собственная реализация матрицы и основных операций над матрицами
- Поддержка многослойных полносвязных сетей
- Forward и backpropagation
- Функция активации: tanh
- Функция потерь: MSE
- Реализован стохастический градиентный спуск

## 📁 Структура проекта

```
SimpleDeepLearn/
├───DeepLearn/
│   │   Model.cpp
│   │   Model.h
│   │
│   ├───Functions/
│   │       Activations.cpp
│   │       LossFun.cpp
│   │
│   └───Layers/
│           Activation.cpp
│           Activation.h
│           Input.cpp
│           Input.h
│           Layer.cpp
│           Layer.h
│           Neuron.cpp
│           Neuron.h
│
└───Matrix/
|   │   Matrix.cpp
|   │   Matrix.h
|   │   test_mat.cpp
|    main.cpp
````

## 🚀 Сборка

### Требования

- Компилятор с поддержкой C++11 или выше
- g++

### Команды

```bash
git clone https://github.com/Vasteri/SimpleDeepLearn
g++ .\main.cpp -o .\build\Debug\outDebug.exe
.\build\Debug\outDebug.exe
````

## 📜 Лицензия

MIT License

## ✍️ Автор

Валерий — \[https://github.com/Vasteri]

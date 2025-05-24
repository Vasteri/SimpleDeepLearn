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
│   │   Model.hpp
│   │
│   ├───Functions/
│   │       Activations.cpp
│   │       LossFun.cpp
│   │
│   └───Layers/
│           Activation.cpp
│           Activation.hpp
│           Input.cpp
│           Input.hpp
│           Layer.cpp
│           Layer.hpp
│           Neuron.cpp
│           Neuron.hpp
│
└───Matrix/
|   │   Matrix.cpp
|   │   Matrix.hpp
|   │   test_mat.cpp
|    main.cpp
````

## 🚀 Сборка

### Требования

- Компилятор с поддержкой C++11 
- g++

### Команды установки и запуска примера

```bash
git clone https://github.com/Vasteri/SimpleDeepLearn
cd SimpleDeepLearn
mkdir build\Debug
g++ .\main.cpp -o .\build\Debug\outDebug.exe
.\build\Debug\outDebug.exe
````

## 📜 Лицензия

MIT License

## ✍️ Автор

Валерий — \[https://github.com/Vasteri]

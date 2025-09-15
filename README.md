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
SimpleDeepLearn/src/
├───DeepLearn/
│   │   Model.cpp
│   │   Model.hpp
│   │
│   ├───Functions/
│   │       Activations.cpp
│   │       Activations.hpp
│   │       LossFun.cpp
│   │       LossFun.hpp
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
|    Makefile
````

## 🚀 Сборка

### Требования

- Компилятор с поддержкой C++17 
- g++
- Утилита make

### Команды установки и запуска примера

```bash
git clone https://github.com/Vasteri/SimpleDeepLearn
cd SimpleDeepLearn/src
make
````

## 📜 Лицензия

MIT License

## ✍️ Автор

Валерий — \[https://github.com/Vasteri]

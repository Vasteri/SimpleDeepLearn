
#include <iostream>

// Шаблонный класс Matrix
template <typename T>
class Matrix {
private:

public:
    T value;
    // Конструктор для инициализации value
    Matrix(T val);

    // Метод для получения значения
    T getValue() const;

    // Объявление оператора + как дружественной функции
    template <typename T1> friend Matrix<T1> operator+(const Matrix<T1>& lhs, T1 rhs);
};

// Объявление дружественной функции
//template <typename T>
//Matrix<T> operator+(const Matrix<T>& lhs, T rhs);







// Конструктор для инициализации value
template <typename T>
Matrix<T>::Matrix(T val) : value(val) {}

// Метод для получения значения
template <typename T>
T Matrix<T>::getValue() const {
    return value;
}

// Определение дружественной функции оператора +
template <typename T>
Matrix<T> operator+(const Matrix<T>& lhs, T rhs) {
    return Matrix<T>(lhs.value + rhs);  // Теперь доступ к lhs.value разрешён
}



// Явное инстанциирование для типа Matrix<double>
//template class Matrix<double>;                  // Инстанциируем шаблон Matrix<double>
//template Matrix<double> operator+(const Matrix<double>& lhs, double rhs); // Инстанциируем оператор +




int main() {
    Matrix<double> a(5.5);   // Первый объект - типа Matrix<double>
    double b = 10.0;         // Второй операнд - тип T (в данном случае double)

    // Ожидается результат 15.5 (5.5 + 10.0)
    Matrix<double> c = a + b;  // b передается как значение типа T (double)

    std::cout << "Результат сложения: " << c.getValue() << std::endl;

    return 0;
}

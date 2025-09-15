#ifndef MATRIX_HPP
#define MATRIX_HPP
//#pragma once
#include <iostream>

template <typename Type>
class Matrix {
    private:
        Type* mat;
        int dim;
        int* dims;
        int memory;
    public:
        Matrix();
        Matrix(int argc, int argv[]);
        Matrix(int argc, int argv[], Type elem);

        ~Matrix();
        Matrix(const Matrix& mat2);    // copy
        Matrix(Matrix&& mat2);         // move
        Matrix<Type> operator =(const Matrix& mat2); // copy assignment
        Matrix<Type> operator =(Matrix&& mat2);      // move assignment

        int  GetDim()              const;
        int  GetDims(const int id) const;
        int  GetMemory()           const;
        void print_mat(const char* out = "");
        void print_info();

        Type Mean();
        Matrix<Type> T();
        Matrix<Type> ApplyFunctionForEach(Type (*function)(Type));
        template <typename Type2> friend Matrix<Type2> ElementWiseMultiplication(const Matrix<Type2>& mat1, const Matrix<Type2>& mat2);

        Matrix<Type> operator - ();
        Type&        operator [](const int id) const;
        template <typename Type2> friend std::ostream &operator<<(std::ostream& os, const Matrix<Type2>& mat);
        template <typename Type2> friend Matrix<Type2> operator + (const Matrix<Type2>& mat1, const Matrix<Type2>& mat2);
        template <typename Type2> friend Matrix<Type2> operator - (const Matrix<Type2>& mat1, const Matrix<Type2>& mat2);
        template <typename Type2> friend Matrix<Type2> operator * (const Matrix<Type2>& mat1, const Matrix<Type2>& mat2);
        template <typename Type2> friend Matrix<Type2> operator + (const Matrix<Type2>& mat2, const Type2 element);
        template <typename Type2> friend Matrix<Type2> operator - (const Matrix<Type2>& mat2, const Type2 element);
        template <typename Type2> friend Matrix<Type2> operator * (const Matrix<Type2>& mat2, const Type2 element);
        template <typename Type2> friend Matrix<Type2> operator / (const Matrix<Type2>& mat2, const Type2 element);
        template <typename Type2> friend Matrix<Type2> operator + (const Type2 element, const Matrix<Type2>& mat2);
        template <typename Type2> friend Matrix<Type2> operator - (const Type2 element, const Matrix<Type2>& mat2);
        template <typename Type2> friend Matrix<Type2> operator * (const Type2 element, const Matrix<Type2>& mat2);
        template <typename Type2> friend Matrix<Type2> operator / (const Matrix<Type2>& mat2, const Type2 element);
        /*
        Matrix<Type>& operator += (const Matrix<Type> mat2);
        Matrix<Type>& operator -= (const Matrix<Type> mat2);
        Matrix<Type>& operator *= (const Matrix<Type> mat2);
        Matrix<Type>& operator += (const Type element);
        Matrix<Type>& operator -= (const Type element);
        Matrix<Type>& operator *= (const Type element);
        */
};



class MatrixException
{
    private:
        std::string message;
    public: 
        MatrixException(std::string input_message): message{input_message}{}
        std::string getMessage() const {return message;}
};

//template class Matrix<double>;

#include "Matrix.tpp"

#endif
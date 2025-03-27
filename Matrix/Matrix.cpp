#pragma once
#include <iostream>
#include "Matrix.h"


template <typename Type>
Matrix<Type>::Matrix(int argc, int argv[]) {
    //std::printf("New\n");
    int i;
    dim = argc;
    memory = 1;
    dims = new int[dim];
    for (i = 0; i < dim; i++) {
        dims[i] = argv[i];
        memory *= argv[i];
    }

    mat = new Type[memory];
    for (i = 0; i < memory; i++) {
        { mat[i] = 0; }  //i * n + j
    }
}



template <typename Type>
Matrix<Type>::~Matrix(){
    //std::printf("Delete\n");
    delete[] dims; 
    delete[] mat; 
}


template <typename Type>
Matrix<Type>::Matrix(const Matrix& mat2){
    //std::printf("Copy\n");
    int i;
    dim = mat2.dim;
    memory = mat2.memory;
    dims = new int[dim];
    for (i = 0; i < dim; i++)
        dims[i] = mat2.dims[i];

    mat = new Type[memory]; 
    for (i = 0; i < memory; i++) {
        { mat[i] = mat2.mat[i]; }  
    }
}


template <typename Type>
Matrix<Type>::Matrix(Matrix&& mat2){
    //std::printf("Move\n");
    mat    = mat2.mat;
    dims   = mat2.dims;
    dim    = mat2.dim;
    memory = mat2.memory;

    mat2.mat    = nullptr;
    mat2.dims   = nullptr;
    mat2.dim    = 0;
    mat2.memory = 0;
}


template <typename Type>
Matrix<Type> Matrix<Type>::operator =(const Matrix& mat2){
    if (this == &mat2)
        return *this;
    delete[] this->mat;
    delete[] this->dims;
    this->memory = mat2.memory;
    this->dim = mat2.dim;

    this->dims = new int[this->dim];
    for (int i = 0; i < this->dim; i++)
        { this->dims[i]  = mat2.dims[i]; }

    this->mat = new Type[this->memory];
    for (int i = 0; i < this->memory; i++)
        { this->mat[i]  = mat2.mat[i]; }
    return *this;
}


template <typename Type>
Matrix<Type> Matrix<Type>::operator =(Matrix&& mat2){
    if (this == &mat2)
        return *this;
    delete[] this->mat;
    delete[] this->dims;

    this->memory = mat2.memory;
    this->dim = mat2.dim;
    this->mat = mat2.mat;
    this->dims = mat2.dims;
    
    mat2.dims = nullptr;
    mat2.mat = nullptr;
    mat2.dim = 0;
    mat2.memory = 0;
    return *this;
}


template <typename Type>
int Matrix<Type>::GetDim() const{
    return dim;
}


template <typename Type>
int Matrix<Type>::GetDims(const int id) const{
    return dims[id];
}


template <typename Type>
int Matrix<Type>::GetMemory() const{
    return memory;
}


template <typename Type>
void Matrix<Type>::print_info() {
    printf("Memory: %d\n", memory);
    printf("Dim: %d\n", dim);
    printf("Dims:");
    for (int i = 0; i < dim; i++){
        printf("%d ", dims[i]);
    }
    printf("\n\n");
}


template <typename Type>
Matrix<Type> Matrix<Type>::T(){
    if (dim == 1){
        int A1[] = {1, dims[0]};
        Matrix<Type> res = *this;
        res.dim = 2;
        res.dims = A1;
        return res;
    }
    else if (dim == 2){
        int A1[] = {dims[1], dims[0]};
        Matrix<Type> res(2, A1);
        int i, j;
        for (i = 0; i < dims[1]; i++){
            for (j = 0; j < dims[0]; j++){
                res[i * dims[0] + j] = mat[j * dims[0] + i];
            }
        }
        return res;
    }
    else throw MatrixException("Much more dims");
}


template <typename Type>
void Matrix<Type>::print_mat(const char* out) {
    printf(out);
    if (dim == 1){
        for (int i = 0; i < memory; i++)
            { printf("%f\n", mat[i]); }
        printf("\n");
    }
    else if (dim == 2){
        for (int i = 0; i < dims[0]; i++){
            for (int j = 0; j < dims[1]; j++)
                { printf("%f ", mat[i * dims[1] + j]); }
            printf("\n");
        }
        printf("\n");
    }
    else throw MatrixException("Much more dims\n");
}


template <typename Type>
Matrix<Type> Matrix<Type>::operator - (){
    Matrix<Type> res = *this;
    for (int i = 0; i < memory; i++){
        res[i] = -mat[i];
    }
    return res;
}

template <typename Type>
Type& Matrix<Type>::operator[](const int id) const{
    return *(mat + id);
}


template <typename Type>
Matrix<Type> Matrix<Type>::operator+(const Matrix<Type>& mat2){
    if (dim != mat2.dim)
        throw MatrixException("Dims are not equal");
    
    Matrix<Type> res(dim, dims);
    for (int i = 0; i < memory; i++)
        res[i] = mat[i] + mat2[i];
    return res;
}


template <typename Type>
Matrix<Type> Matrix<Type>::operator-(const Matrix<Type>& mat2){
    if (dim != mat2.dim)
        throw MatrixException("Dims are not equal");
    
    Matrix<Type> res(dim, dims);
    for (int i = 0; i < memory; i++)
        res[i] = mat[i] - mat2[i];
    return res;
}


template <typename Type>
Matrix<Type> Matrix<Type>::operator*(const Matrix<Type>& mat2){
    if ((this->dim > 2) | (mat2.dim > 2))
        throw MatrixException("Much more dims");
    if (this->dim == 1){
        if (1 != mat2.dims[0]) 
            throw MatrixException("Incorrect dims");
    }
    else {
        if (this->dims[1] != mat2.dims[0]) 
            throw MatrixException("Incorrect dims");
    }
    int m = dims[0];
    int s = mat2.dims[0];
    int n, dims_res;
    if (mat2.dim == 1) {
        n = 1;
        dims_res = 1;
    }
    else {
        n = mat2.dims[1];
        dims_res = 2;
    }
    int A1[] = {m, n};
    Matrix<Type> res(dims_res, A1);
    
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            res[i * n + j] = 0;
            for (k = 0; k < s; k++) {
                res[i * n + j] += mat[i * s + k] * mat2[k * n + j];
            }
        }
    }
    return res;
}


template <typename Type>
Matrix<Type> operator +(Matrix<Type>& mat2, Type element){
    Matrix<Type> res(mat2);
    for (int i = 0; i < res.GetMemory(); i++)
        res[i] += element;
    return res;
}


template <typename Type>
Matrix<Type> operator -(Matrix<Type>& mat2, Type element){
    Matrix<Type> res(mat2);
    for (int i = 0; i < res.GetMemory(); i++)
        res[i] -= element;
    return res;
}


template <typename Type>
Matrix<Type> operator *(Matrix<Type>& mat2, Type element){
    Matrix<Type> res(mat2);
    for (int i = 0; i < res.GetMemory(); i++)
        res[i] *= element;
    return res;
}


template <typename Type>
Matrix<Type> operator +(Type element, Matrix<Type>& mat2){
    return mat2 + element; 
}


template <typename Type>
Matrix<Type> operator -(Type element, Matrix<Type>& mat2){
    return -(mat2 - element);
}


template <typename Type>
Matrix<Type> operator *(Type element, Matrix<Type>& mat2){
    return mat2 * element;
}


/*
template <typename Type>
Matrix<Type>& Matrix<Type>::operator += (const Matrix<Type> mat2);


template <typename Type>
Matrix<Type>& Matrix<Type>::operator -= (const Matrix<Type> mat2);


template <typename Type>
Matrix<Type>& Matrix<Type>::operator *= (const Matrix<Type> mat2);


template <typename Type>
Matrix<Type>& Matrix<Type>::operator += (const Type element);


template <typename Type>
Matrix<Type>& Matrix<Type>::operator -= (const Type element);


template <typename Type>
Matrix<Type>& Matrix<Type>::operator *= (const Type element);
*/


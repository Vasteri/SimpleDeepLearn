#include <malloc.h>
#include <iostream>

double** new_matrix(int m, int n) {
    double** A = (double**)malloc(sizeof(double*) * m);
    int i, j;
    for (i = 0; i < m; i++) {
        A[i] = (double*)malloc(sizeof(double) * n);
        for (j = 0; j < n; j++)
            { A[i][j] = 0; }
    }
    return A;
}

double** delete_matrix(double** A, int m, int n) {
    for (int i = 0; i < m; i++)
        free(A[i]);
    free(A);
}

void print_matrix(double** A, int m, int n){
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            std::printf("%f ", A[i][j]);
        }
        std::printf("\n");
    }
}

double** matmul(double** A, double** B, int m, int n, int s){
    int i, j, k;
    double** C = new_matrix(m, s);
    for (i = 0; i < m; i++)
        for (j = 0; j < s; j++){
            C[i][j] = 0.0;
            for (k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

double** transpose_matrix(double** A, int m, int n) {
    double** B = new_matrix(n, m);
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            B[j][i] = A[i][j];
    return B;
}
#include "low_matrix.cpp"

int main() {
    std::printf("Start\n");

    int m = 3, n = 3, s = 3;
    double** A = new_matrix(m, n);
    double** B = new_matrix(n, s);

    std::printf("After malloc\n");

    int i, j;
    int mi;
    if (m > n) 
        mi = n;
    else 
        mi = m;
    for (i = 0; i < mi; i++)
        A[i][i] = 1; 
     /*
    for (i = 0; i < m; i++) 
        for (j = 0; j < n; j++) 
            A[i][j] = 0.0; //(double)(i + j);
    */
    for (i = 0; i < n; i++)
        for (j = 0; j < s; j++)
            B[i][j] = 1; //(double)(m * s - (i * s + j));

    std::printf("After initialization\n");

    double** C = matmul(A, B, m, n, s);

    std::printf("After matmul\n");

    std::printf("A:\n");
    print_matrix(A, m, n);
    std::printf("\nB:\n");
    print_matrix(B, n, s);
    std::printf("\nC:\n");
    print_matrix(C, m, s);

    std::printf("After output\n");

    delete_matrix(A, m, n);
    delete_matrix(B, n, s);
    delete_matrix(C, m, s);

    std::printf("End\n");
    return 0;
}
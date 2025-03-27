#include "matrix.cpp"

int main() {
    std::printf("Start\n");

    int m = 3, n = 3, s = 3;
    int A1[] = {m, n};
    int A2[] = {n, s};
    Matrix<double> A(2, A1);
    Matrix<double> B(2, A2);
    Matrix<double> X(1, &n);
    Matrix<double> E(2, A1);

    std::printf("After malloc\n");


    
                        // A = E
    int i, j;   
    int mi;
    if (m > n) 
        mi = n;
    else 
        mi = m;
    for (i = 0; i < mi; i++){
        A[i * mi + i] = 2;
        E[i * mi + i] = 1;
    }


    for (i = 0; i < n; i++){
        X[i] = i + 1;
    }
    


     /*
    for (i = 0; i < m; i++) 
        for (j = 0; j < n; j++) 
            A[i][j] = 0.0; //(double)(i + j);
    */

    
    for (i = 0; i < n; i++)
        for (j = 0; j < s; j++)
            B[i * s + j] = i * s + j; //(double)(m * s - (i * s + j));
    

    std::printf("After initialization\n");

    std::printf("%f\n", A[1]);
    
    Matrix<double> C = A + B;
    Matrix<double> D = A * B;
    Matrix<double> G = (A + B).T();

    A.print_mat("A:\n");
    B.print_mat("B:\n");
    C.print_mat("A + B:\n");
    D.print_mat("A * B:\n");
    G.print_mat("(A + B)^T:\n");

    X.print_mat("X:\n");

    (X.T() * A).print_mat("X^T * A:\n");
    (A * X).print_mat("A * X:\n");
    (A * (A * X)).print_mat("A * (A * X):\n");
    (-A).print_mat("-A:\n");

    std::printf("Final\n");
    int B1[] = {3, 2};
    int B2[] = {2, 3};
    Matrix<double> M(2, B1);
    Matrix<double> N(2, B2);
    for (i = 0; i < 6; i++){
        M[i] = i + 1.5;
        N[i] = i + -6.3;
    }
    M.print_mat("M:\n");
    N.print_mat("N:\n");
    (M * N).print_mat("M * N:\n");
    

    std::printf("Test dims\n");
    A.print_info();
    int dims = A.GetDims(0);
    dims = 0;
    A.print_info();
    (A + B + C * D - M).print_mat("Hard:\n");
    /*
    std::printf("Test +=\n");
    A.print_mat("A:\n");
    A += A;
    A.print_mat("A+=A:\n");
    (A+=B).print_mat("2A += B:\n");

    
    std::printf("Test *=\n");
    E.print_mat("E:\n");
    E *= E;
    E.print_mat("E*=E:\n");
    (E*=A).print_mat("E *= A:\n");
    */
    (E + 5.0).print_mat("E + 5\n");
    (5.0 + E * E).print_mat("6 + E\n");
    (E - 5.0).print_mat("E - 5\n");
    (6.0 - E).print_mat("6 - E\n");
    (10.0 * E).print_mat("10 * E\n");
    (E * 11.0).print_mat("E * 11\n");
    //(5 + E).print_mat("5 + E\n");
    std::printf("End\n");
    return 0;
}
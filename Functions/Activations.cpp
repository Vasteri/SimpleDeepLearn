#include <cmath>

Matrix<double>              tanh(Matrix<double> x);
Matrix<double> differential_tanh(Matrix<double> x);

double pow2(double x);


Matrix<double> tanh(Matrix<double>& x) {
    return x.ApplyFunctionForEach(tanh);
}


Matrix<double> differential_tanh(Matrix<double>& x) {
    return 1.0 / (x.ApplyFunctionForEach(cosh)).ApplyFunctionForEach(pow2);
}


double pow2(double x){
    return x * x;
}
#include "Activations.hpp"

Matrix<double> tanh(const Matrix<double>& x) { return x.ApplyFunctionForEach(tanh); }

Matrix<double> differential_tanh(const Matrix<double>& x) {
    return 1.0 / ((x.ApplyFunctionForEach(cosh)).ApplyFunctionForEach(pow2));
}

double pow2(const double x) { return x * x; }
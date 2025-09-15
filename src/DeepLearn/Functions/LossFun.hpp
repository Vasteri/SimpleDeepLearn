#include "../../Matrix/Matrix.hpp"

Matrix<double> MSE(const Matrix<double>& y_pred, const Matrix<double>& y_true);
Matrix<double> grad_MSE(const Matrix<double>& y_pred, const Matrix<double>& y_true);
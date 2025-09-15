#include "../../Matrix/Matrix.hpp"

Matrix<double> MSE(Matrix<double> y_pred, Matrix<double> y_true);
Matrix<double> grad_MSE(Matrix<double>& y_pred, Matrix<double>& y_true);
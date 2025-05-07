

Matrix<double> MSE(Matrix<double> y_pred, Matrix<double> y_true){
    int A1[] = {y_pred.GetDims(1)};
    Matrix<double> ones = Matrix<double>(1, A1, 1);
    return (y_pred - y_true) * ones;
}


Matrix<double> grad_MSE(Matrix<double>& y_pred, Matrix<double>& y_true){
    return (2.0 / y_pred.GetDims(1)) * (y_pred - y_true);
}

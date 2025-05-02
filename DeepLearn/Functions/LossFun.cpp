

double MSE(Matrix<double> y_pred, Matrix<double> y_true){
    Matrix<double> temp = y_pred - y_true;
    double result = 0;
    for (int i = 0; i < temp.GetDims(1); i++)
        result += (temp[i] * temp[i]);
    return result / temp.GetDims(1);
}


Matrix<double> grad_MSE(Matrix<double>& y_pred, Matrix<double>& y_true){
    return (2.0 / y_pred.GetDims(1)) * (y_pred - y_true);
}

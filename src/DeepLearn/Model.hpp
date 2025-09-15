#pragma once

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#include "../Matrix/Matrix.hpp"
#include "Functions/LossFun.hpp"
#include "Layers/Activation.hpp"
#include "Layers/Input.hpp"
#include "Layers/Layer.hpp"
#include "Layers/Neuron.hpp"

class Model {
   private:
    Input* input_layer;
    Layer* output_layer;
    bool compiled;
    bool forward_prop;
    Matrix<double> (*loss_function)(const Matrix<double>& y_pred, const Matrix<double>& y_true);
    Matrix<double> (*grad_loss_function)(const Matrix<double>& y_pred, const Matrix<double>& y_true);

   public:
    class Exception {};
    explicit Model(Input* input_outside, Layer* output_outside);
    ~Model();
    void compile(const char* loss = "mse");
    void summary();
    Matrix<double> vector_to_matrix(const vector<double>& input_vector);
    Matrix<double> prepare_batch(const vector<vector<double>>& x, int batch_size, int start);
    Matrix<double> forward_propagation(Matrix<double> input_matrix);
    vector<double> matrix_to_vector(const Matrix<double>& input_matrix);
    vector<double> forward_propagation(const vector<double>& input_vector);
    void backward_propagation(Matrix<double> y_pred, Matrix<double> y_true);
    void backward_propagation(const vector<double>& y_pred_vector, const vector<double>& y_true_vector);
    vector<double> fit_chaotic(const vector<vector<double>>& x, const vector<vector<double>>& y_true,
                               int batch_size = 20, int n = 0);

    void view_weigth();
};

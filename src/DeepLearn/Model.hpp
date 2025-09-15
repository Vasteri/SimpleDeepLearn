#pragma once

#include <vector>
#include <iostream>
#include <cstring>

#include "../Matrix/Matrix.hpp"

#include "Functions/LossFun.hpp"
#include "Layers/Layer.hpp"
#include "Layers/Input.hpp"
#include "Layers/Neuron.hpp"
#include "Layers/Activation.hpp"

class Model {
    private:
        Input* input_layer;
        Layer* output_layer;
        bool compiled;
        bool forward_prop;
        Matrix<double> (*loss_function)(Matrix<double> y_pred, Matrix<double> y_true);
        Matrix<double> (*grad_loss_function)(Matrix<double>& y_pred, Matrix<double>& y_true);
    public:
        class Exception{};
        Model(Input* input_outside, Layer* output_outside);
        ~Model();
        void compile(const char* loss = "mse");
        void summary();
        Matrix<double>      vector_to_matrix(const std::vector<double>& input_vector);
        std::vector<double> matrix_to_vector(const Matrix<double>& input_matrix);
        Matrix<double>      prepare_batch(std::vector<std::vector<double>>& x, int batch_size, int start);
        Matrix<double>      forward_propagation(Matrix<double> input_matrix);
        std::vector<double> forward_propagation(std::vector<double> input_vector);
        void backward_propagation(Matrix<double> y_pred, Matrix<double> y_true);
        void backward_propagation(std::vector<double> y_pred_vector, std::vector<double> y_true_vector);
        std::vector<double> fit_chaotic(std::vector<std::vector<double>>& x, std::vector<std::vector<double>>& y_true, int batch_size = 20, int n = 0);

        void view_weigth();
};

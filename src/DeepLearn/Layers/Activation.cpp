#include "Activation.hpp"

Activation::Activation(const char* type_function, Layer* prev_layer_outside) : Layer() {
    this->trainable = false;
    this->input_shape = prev_layer_outside->get_output_shape();
    this->output_shape = this->input_shape;
    this->prev_layer = prev_layer_outside;
    this->next_layer = nullptr;
    prev_layer_outside->next_layer = this;
    name_function = type_function;

    if (strcmp(type_function, "tanh") == 0) {
        function_activation = tanh;
        differential_function_activation = differential_tanh;
    } else {
        throw Exception();
    }
}

void Activation::summary() {
    std::cout << "Activation: " << name_function << std::endl;
    if (next_layer != nullptr) {
        next_layer->summary();
    }
}

Matrix<double> Activation::forward_propagation(Matrix<double>& input_outside) {
    this->input = input_outside;
    Matrix<double> result = function_activation(input);

    if (next_layer != nullptr)
        return next_layer->forward_propagation(result);
    else
        return result;
}

void Activation::backward_propagation(Matrix<double>& input_outside) {
    if (prev_layer != nullptr) {
        Matrix<double> result = ElementWiseMultiplication(differential_function_activation(input), input_outside);
        prev_layer->backward_propagation(result);
    }
}

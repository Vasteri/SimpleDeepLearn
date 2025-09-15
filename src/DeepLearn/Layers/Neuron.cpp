#include "Neuron.hpp"

void Neuron::init_weights() {
    for (int i = 0; i < (input_shape); i++) {
        for (int j = 0; j < output_shape; j++) {
            weights[i * (output_shape) + j] = (std::rand() % 100 + 1) / 101.;
        }
    }
    for (int i = 0; i < output_shape; i++) {
        displacement[i] = (std::rand() % 100 + 1) / 101.;
    }
}

Neuron::Neuron(int count_neurons, Layer* prev_layer_outside, bool trainable_outside) : Layer() {
    this->trainable = trainable_outside;
    this->input_shape = prev_layer_outside->get_output_shape();
    this->output_shape = count_neurons;
    this->prev_layer = prev_layer_outside;
    this->next_layer = nullptr;
    prev_layer_outside->next_layer = this;
    int size[] = {input_shape, output_shape};
    this->weights = Matrix<double>(2, size);
    size[0] = 1;
    this->displacement = Matrix<double>(2, size);
    this->ones = Matrix<double>();
    this->ones[0] = 1;
    init_weights();
}

void Neuron::summary() {
    std::cout << "Neuron: " << input_shape << " -> " << output_shape << "\n";
    if (next_layer != nullptr) {
        next_layer->summary();
    }
}

void Neuron::view_weigth() {
    std::cout << "Neuron:" << std::endl << weights << displacement;
    if (next_layer != nullptr) next_layer->view_weigth();
}

Matrix<double> Neuron::forward_propagation(Matrix<double>& input_outside) {
    // std::cout << "Neuron:forward\n";
    this->input = input_outside;
    if (ones.GetDims(0) != input.GetDims(0)) {
        int dims[] = {input.GetDims(0), 1};
        this->ones = Matrix<double>(2, dims, 1);
    }
    Matrix<double> result = input * weights + ones * displacement;

    if (next_layer != nullptr)
        return next_layer->forward_propagation(result);
    else
        return result;
}

void Neuron::backward_propagation(Matrix<double>& input_outside) {
    // std::cout << "Neuron:backward\n";

    if (prev_layer != nullptr) {
        Matrix<double> result = input_outside * weights.T();
        prev_layer->backward_propagation(result);
    }

    // std::cout << "Before:\n" << weights << displacement << std::endl;
    weights = weights - speed_learn * ((this->input).T() * input_outside) / (double)(this->input).GetDims(0);
    displacement = displacement - speed_learn * ones.T() * input_outside / (double)(this->input).GetDims(0);
    // std::cout << "After:\n" << weights << displacement << std::endl;
}

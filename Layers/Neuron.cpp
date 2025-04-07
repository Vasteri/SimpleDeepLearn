#include "Neuron.h"

void Neuron::init_weights(){
    for (int i = 0; i < (input_shape); i++){
        for (int j = 0; j < output_shape; j++){
            weights[i * (output_shape) + j] = 0.5;
        }
    }
    /*
    for (int i = 0; i < (input_shape + 1); i++){
        weights[i * (output_shape + 1) + output_shape] = 0.0;
    }
    weights[(output_shape + 1) * (input_shape + 1) - 1] = 1.0;
    */
}


Neuron::Neuron(int count_neurons, Layer* prev_layer_outside, bool trainable_outside){
    Layer();
    this->trainable = trainable_outside;
    this->input_shape = prev_layer_outside->get_output_shape();
    this->output_shape = count_neurons;
    this->prev_layer = prev_layer_outside;
    this->next_layer = nullptr;
    prev_layer_outside->next_layer = this;
    int size[] = {input_shape, output_shape};
    this->weights = Matrix<double>(2, size);
    init_weights();
}


void Neuron::summary(){
    std::cout << "Neuron: " << input_shape << " -> " << output_shape << "\n";
    if (next_layer != nullptr) {
        next_layer->summary();
    }
}


Matrix<double>  Neuron::forward_propagation(Matrix<double>& input_outside){
    //std::cout << "Neuron:forward\n";
    this->input = input_outside;
    Matrix<double> result = input * weights;
    if (next_layer != nullptr)
        return next_layer->forward_propagation(result);
    else    
        return result;
}


void Neuron::backward_propagation(Matrix<double>& input_outside){
    //std::cout << "Neuron:backward\n";
    Matrix<double> result = input_outside * weights.T();
    //std::cout << "result: " << result << "input_outside: " << input_outside << "weigth: " << weights << weights.T();

    if (prev_layer != nullptr)
        prev_layer->backward_propagation(result);
    
    //std::cout << "weigth 1: " << weights;
    weights = weights - speed_learn * ((this->input).T() * input_outside);
    //std::cout << "weigth 2: " << weights;
    //std::cout << input_outside;
    //std::cout << speed_learn * ((this->input).T() * input_outside);
}

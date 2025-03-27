#include "Neuron.h"

void Neuron::init_weights(){
    for (int i = 0; i < input_shape; i++){
        for (int j = 0; j < output_shape; j++){
            weights[i * output_shape + j] = 0.5;
        }
    }
}


Neuron::Neuron(int count_neurons, Layer* prev_layer, bool trainable = true){
    this->trainable = trainable;
    this->input_shape = prev_layer->output_shape;
    this->output_shape = count_neurons;
    this->prev_layer = prev_layer;
    prev_layer->next_layer = this;
    int size[] = {input_shape, output_shape};
    this->weights = Matrix<double>(2, size);
    init_weights();
}


Matrix<double>&  Neuron::forward_propagation(Matrix<double>& input){
    this->input = input;
    return next_layer->forward_propagation(input * weights);
}


void Neuron::backward_propagation(Matrix<double>& input){
    prev_layer->backward_propagation(input * weights.T());
    weights = weights - speed_learn * ((this->input).T() * input);
}

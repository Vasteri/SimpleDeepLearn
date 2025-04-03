#include "Input.h"

Input::Input(int input_shape_neurons): Layer(){
    this->input_shape  = input_shape_neurons;
    this->output_shape = input_shape_neurons;
    this->next_layer = nullptr;
}


void Input::summary(){
    std::cout << "Input: " << input_shape << "\n";
    if (next_layer != nullptr) {
        next_layer->summary();
    }
}


Matrix<double>  Input::forward_propagation(Matrix<double>& input_neurons){
    std::cout << "Input:forward\n";
    return next_layer->forward_propagation(input_neurons);
}


void Input::backward_propagation(Matrix<double>& input_neurons){
    std::cout << "Input:backward\n";
    return;
}

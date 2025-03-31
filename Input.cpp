#include "Input.h"

Input::Input(int input_shape_neurons): Layer(){
    this->input_shape = input_shape_neurons;
    this->next_layer = nullptr;
}


void Input::summary(){
    std::cout << "Input\n";
    if (next_layer != nullptr) {
        next_layer->summary();
    }
}


Matrix<double>&  Input::forward_propagation(Matrix<double>& input_neurons){
    return next_layer->forward_propagation(input_neurons);
}


void Input::backward_propagation(Matrix<double>& input_neurons){
    return;
}

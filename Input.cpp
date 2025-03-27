#include "Input.h"

Input::Input(int input_shape){
    this->input_shape = input_shape;
}


Matrix<double>&  Input::forward_propagation(Matrix<double>& input){
    return next_layer->forward_propagation(input);
}


void Input::backward_propagation(Matrix<double>& input){
}

#include "Model.h"

Model::Model(Input* input_outside, Layer* output_outside){
    this->input_layer = input_outside;
    this->output_layer = output_outside;
    compiled = false;
}


Model::~Model(){
    std::cout << "delete Model\n";
    delete input_layer;
}


void Model::summary(){
    std::cout << "Model\n";
    if (input_layer != nullptr) {
        input_layer->summary();
    }
}


void Model::compile(){
    compiled = true;
}


Matrix<double> Model::forward_propagation(Matrix<double> input_x){
    return input_layer->forward_propagation(input_x);
}
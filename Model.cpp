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


Matrix<double> Model::forward_propagation(Matrix<double> input_matrix){
    std::cout << "Model:forward\n";
    if (input_matrix.GetMemory() != input_layer->get_input_shape())
        throw Model::Exception();
    return input_layer->forward_propagation(input_matrix);
}


std::vector<double> Model::forward_propagation(std::vector<double> input_vector){
    unsigned int n = input_vector.size();
    int A1[] = {1, n};

    Matrix<double> input_matrix(2, A1);
    for (unsigned int i = 0; i < n; i++)
        input_matrix[i] = input_vector[i];
    Matrix<double> result_matrix = this->forward_propagation(input_matrix);

    std::vector<double> result_vector;
    for (int i = 0; i < result_matrix.GetMemory(); i++)
        result_vector.push_back(result_matrix[i]);
    return result_vector;
}
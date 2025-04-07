#include "Model.h"

Model::Model(Input* input_outside, Layer* output_outside){
    this->input_layer = input_outside;
    this->output_layer = output_outside;
    compiled = false;
    forward_prop = false;
}


Model::~Model(){
    std::cout << "delete Model\n";
    delete input_layer;
}


void Model::summary(){
    std::cout << "Model" << std::endl;
    if (input_layer != nullptr) {
        input_layer->summary();
    }
    std::cout << "Output: " << output_layer->get_output_shape() << std::endl;
}


void Model::compile(const char* loss){

    if      (strcmp(loss, "mse" ) == 0) {
        loss_function = MSE;
        grad_loss_function = grad_MSE;
    }
    else if (strcmp(loss, "mae" ) == 0) {

    }
    else if (strcmp(loss, "mape") == 0) {

    }
    else {
        throw Model::Exception();
    }
    compiled = true;
}


Matrix<double> Model::forward_propagation(Matrix<double> input_matrix){
    //std::cout << "Model:forward\n";
    if (!compiled)
        throw Model::Exception();
    if (input_matrix.GetMemory() != input_layer->get_input_shape())
        throw Model::Exception();
    
    forward_prop = true;

    return input_layer->forward_propagation(input_matrix);
}


std::vector<double> Model::forward_propagation(std::vector<double> input_vector){
    unsigned int n = input_vector.size();
    int A1[] = {1, (int)(n)};

    Matrix<double> input_matrix(2, A1);
    for (unsigned int i = 0; i < n; i++)
        input_matrix[(int)(i)] = input_vector[i];
    Matrix<double> result_matrix = this->forward_propagation(input_matrix);

    std::vector<double> result_vector;
    for (int i = 0; i < result_matrix.GetMemory(); i++)
        result_vector.push_back(result_matrix[i]);
    return result_vector;
}


void Model::backward_propagation(Matrix<double> y_pred, Matrix<double> y_true){
    if (y_pred.GetMemory() != y_true.GetMemory())
        throw Model::Exception();
    if (!compiled)
        throw Model::Exception();
    if (!forward_prop)
        throw Model::Exception();

    forward_prop = false;
    Matrix<double> grad_loss = grad_loss_function(y_pred, y_true);
    output_layer->backward_propagation(grad_loss);
}


void Model::backward_propagation(std::vector<double> y_pred_vector, std::vector<double> y_true_vector){
    unsigned int n = y_pred_vector.size();
    int A1[] = {1, (int)(n)};

    Matrix<double> y_pred_matrix(2, A1);
    Matrix<double> y_true_matrix(2, A1);
    for (unsigned int i = 0; i < n; i++) {
        y_pred_matrix[(int)(i)] = y_pred_vector[i];
        y_true_matrix[(int)(i)] = y_true_vector[i];
    }
    
    this->backward_propagation(y_pred_matrix, y_true_matrix);
}


#include "Model.hpp"

Model::Model(Input* input_outside, Layer* output_outside) {
    this->input_layer = input_outside;
    this->output_layer = output_outside;
    compiled = false;
    forward_prop = false;
}

Model::~Model() {
    // std::cout << "delete Model\n";
    delete input_layer;
}

void Model::compile(const char* loss) {
    if (strcmp(loss, "mse") == 0) {
        loss_function = MSE;
        grad_loss_function = grad_MSE;
    } else if (strcmp(loss, "mae") == 0) {
    } else if (strcmp(loss, "mape") == 0) {
    } else {
        throw Model::Exception();
    }
    compiled = true;
}

void Model::summary() {
    std::cout << "Model" << std::endl;
    if (input_layer != nullptr) {
        input_layer->summary();
    }
    std::cout << "Output: " << output_layer->get_output_shape() << std::endl;
}

Matrix<double> Model::vector_to_matrix(const std::vector<double>& input_vector) {
    unsigned int n = input_vector.size();
    int A1[] = {1, (int)(n)};

    Matrix<double> result(2, A1);
    for (unsigned int i = 0; i < n; i++) result[(int)(i)] = input_vector[i];
    return result;
}

std::vector<double> Model::matrix_to_vector(const Matrix<double>& input_matrix) {
    std::vector<double> result_vector;
    for (int i = 0; i < input_matrix.GetMemory(); i++) result_vector.push_back(input_matrix[i]);
    return result_vector;
}

Matrix<double> Model::prepare_batch(std::vector<std::vector<double>>& x, int batch_size, int start) {
    int n = (int)(x[0].size());
    int A1[] = {batch_size, n};
    Matrix<double> res(2, A1);
    for (int i = 0; i < batch_size; i++) {
        for (int j = 0; j < n; j++) {
            res[i * n + j] = x[(unsigned int)(start + i)][(unsigned int)(j)];
        }
    }
    return res;
}

Matrix<double> Model::forward_propagation(Matrix<double> input_matrix) {
    // std::cout << "Model:forward\n";
    if (!compiled) throw Model::Exception();
    if ((input_matrix.GetMemory() % input_layer->get_input_shape()) != 0) throw Model::Exception();

    forward_prop = true;

    return input_layer->forward_propagation(input_matrix);
}

std::vector<double> Model::forward_propagation(std::vector<double> input_vector) {
    Matrix<double> result_matrix = this->forward_propagation(vector_to_matrix(input_vector));
    return matrix_to_vector(result_matrix);
}

void Model::backward_propagation(Matrix<double> y_pred, Matrix<double> y_true) {
    if (y_pred.GetMemory() != y_true.GetMemory()) throw Model::Exception();
    if (!compiled) throw Model::Exception();
    if (!forward_prop) throw Model::Exception();

    forward_prop = false;
    Matrix<double> grad_loss = grad_loss_function(y_pred, y_true);
    output_layer->backward_propagation(grad_loss);
}

void Model::backward_propagation(std::vector<double> y_pred_vector, std::vector<double> y_true_vector) {
    this->backward_propagation(vector_to_matrix(y_pred_vector), vector_to_matrix(y_true_vector));
}

std::vector<double> Model::fit_chaotic(std::vector<std::vector<double>>& x, std::vector<std::vector<double>>& y_true,
                                       int batch_size, int n) {
    if (x.size() < (unsigned int)n)
        throw Model::Exception();
    else if (x.size() != y_true.size())
        throw Model::Exception();
    else if (n == 0 || n > (int)(x.size()))
        n = (int)x.size();
    const int batch_count = n / batch_size;

    std::vector<double> history;
    Matrix<double> x_batch, y_pred_batch, y_true_batch;
    for (int i = 0; i < batch_count; i++) {
        x_batch = prepare_batch(x, batch_size, i * batch_size);
        y_true_batch = prepare_batch(y_true, batch_size, i * batch_size);
        y_pred_batch = forward_propagation(x_batch);
        backward_propagation(y_pred_batch, y_true_batch);

        history.push_back(loss_function(y_pred_batch, y_true_batch).Mean());

        if (((i * batch_size) % 1000) == 0 || (i / 10 == 0)) {
            std::cout << i << ": " << history[(unsigned int)(i)] << "                   \r";
            // std::cout << " -> " << (forward_propagation(x[i]))[0] << std::endl;
        }
    }
    std::cout << std::endl << "End fit\n";
    return history;
}

void Model::view_weigth() {
    std::cout << "Weigth:" << std::endl;
    input_layer->view_weigth();
}

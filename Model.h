#include <vector>
#include <string.h>
#include "Matrix/Matrix.cpp"
#include "Layers/Input.cpp"
#include "Layers/Neuron.cpp"
#include "LossFun.cpp"

class Model {
    private:
        Input* input_layer;
        Layer* output_layer;
        bool compiled;
        bool forward_prop;
        double (*loss_function)(Matrix<double>& y_pred, Matrix<double>& y_true);
        Matrix<double> (*grad_loss_function)(Matrix<double>& y_pred, Matrix<double>& y_true);
    public:
        class Exception{};
        Model(Input* input_outside, Layer* output_outside);
        ~Model();
        void compile(const char* loss = "mse");
        void summary();
        Matrix<double>      forward_propagation(Matrix<double> input_matrix);
        std::vector<double> forward_propagation(std::vector<double> input_vector);
        void backward_propagation(Matrix<double> y_pred, Matrix<double> y_true);
        void backward_propagation(std::vector<double> y_pred_vector, std::vector<double> y_true_vector);
};

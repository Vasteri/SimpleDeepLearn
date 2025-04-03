#include <vector>
#include "Matrix/Matrix.cpp"
#include "Layers/Neuron.cpp"
#include "Layers/Input.cpp"

class Model {
    private:
        Input* input_layer;
        Layer* output_layer;
        bool compiled;
        //loss_function;
    public:
        class Exception{};
        Model(Input* input_outside, Layer* output_outside);
        ~Model();
        void compile();
        void summary();
        std::vector<double> forward_propagation(std::vector<double> input_vector);
        Matrix<double>      forward_propagation(Matrix<double> input_matrix);
        void backward_propagation(std::vector<double> input_vector);
        void backward_propagation(Matrix<double> input_matrix);
};

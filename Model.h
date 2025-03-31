#include <vector>
#include "Neuron.cpp"
#include "Input.cpp"

class Model {
    private:
        Input* input_layer;
        Layer* output_layer;
        bool compiled;
        //loss_function;
    public:
        class Exception;
        Model(Input* input_outside, Layer* output_outside);
        ~Model();
        void compile();
        void summary();
        std::vector<double> forward_propagation(std::vector<double> input_x);
        Matrix<double>      forward_propagation(Matrix<double> input_x);
        void backward_propagation(std::vector<double> input_x);
        void backward_propagation(Matrix<double> input_x);
};

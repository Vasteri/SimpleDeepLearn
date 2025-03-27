#include <vector>
#include "Neuron.cpp"
#include "Input.cpp"

class Model {
    private:
        Input input;
        //output;
        bool compiled;
        //loss_function;
    public:
        Model(Input input, Layer output);
        void compile();
        char* summary();
        std::vector<double> forward_propagation(std::vector<double>);
        void backward_propagation(std::vector<double>);
}
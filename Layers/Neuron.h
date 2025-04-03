#include "Layer.cpp"

class Neuron: public Layer {
    private:
        void init_weights();
    public:
        Neuron(int count_neurons, Layer* prev_layer_outside, bool trainable_outside = true);
        virtual void summary();
        virtual Matrix<double>  forward_propagation(Matrix<double>& input_outside) override;
        virtual void backward_propagation(Matrix<double>& input_outside) override;
};

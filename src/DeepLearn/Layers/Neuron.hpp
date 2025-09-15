#include "Layer.hpp"

class Neuron: public Layer {
    private:
        void init_weights();
        Matrix<double> weights;
        Matrix<double> displacement;
        Matrix<double> ones;
    public:
        Neuron(int count_neurons, Layer* prev_layer_outside, bool trainable_outside = true);
        virtual void summary() override;
        virtual void view_weigth() override;
        virtual Matrix<double> forward_propagation(Matrix<double>& input_outside) override;
        virtual void backward_propagation(Matrix<double>& input_outside) override;
};

#include "Layer.h"

class Neuron: public Layer {
    private:
        void init_weights();
    public:
        Neuron(int count, Layer* prev_layer, bool trainable = true);
        virtual Matrix<double>&  forward_propagation(Matrix<double>& input) override;
        virtual void backward_propagation(Matrix<double>& input) override;
};

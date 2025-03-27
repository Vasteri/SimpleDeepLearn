#include "Layer.h"

class Input: public Layer {
    public:
        Input(int input_shape);
        virtual Matrix<double>&  forward_propagation(Matrix<double>& input) override;
        virtual void backward_propagation(Matrix<double>& input) override;
};

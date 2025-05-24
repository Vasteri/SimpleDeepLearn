#include "Layer.cpp"

class Input: public Layer {
    public:
        Input(int input_shape_outside);
        virtual void summary() override;
        virtual void view_weigth() override;
        virtual Matrix<double>  forward_propagation(Matrix<double>& input_outside) override;
        virtual void backward_propagation(Matrix<double>& input_outside) override;
};

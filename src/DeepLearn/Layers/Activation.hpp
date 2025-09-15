#include <cstring>

#include "../Functions/Activations.hpp"
#include "Layer.hpp"

class Activation : public Layer {
   private:
    Matrix<double> (*function_activation)(const Matrix<double>&);
    Matrix<double> (*differential_function_activation)(const Matrix<double>&);
    const char* name_function;

   public:
    class Exception {};
    explicit Activation(const char* type_function, Layer* prev_layer_outside);
    virtual void summary() override;
    virtual Matrix<double> forward_propagation(Matrix<double>& input_outside) override;
    virtual void backward_propagation(Matrix<double>& input_outside) override;
};

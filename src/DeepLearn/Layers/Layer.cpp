#include "Layer.hpp"


double Layer::speed_learn = 0.5;


Layer::~Layer(){
    //std::cout << "delete Layer\n";
    delete next_layer;
}


int Layer::get_input_shape() {
    return input_shape;
}


int Layer::get_output_shape() {
    return output_shape;
}


void Layer::summary() {
    std::cout << "Layer\n";
    if (next_layer != nullptr) {
        next_layer->summary();
    }
}


void Layer::view_weigth(){
    std::cout << "Layer" << std::endl;
    if (next_layer != nullptr)
        next_layer->view_weigth();
}


Matrix<double> Layer::forward_propagation(Matrix<double>& input_outside){
    if (next_layer != nullptr)
        return next_layer->forward_propagation(input_outside);
    else
        return input_outside;
}


void Layer::backward_propagation(Matrix<double>& input_outside){
    if (prev_layer != nullptr)
        prev_layer->backward_propagation(input_outside);
}

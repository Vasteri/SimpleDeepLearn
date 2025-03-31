#pragma once
#include "Layer.h"


double Layer::speed_learn = 0.5;


Layer::~Layer(){
    std::cout << "delete Layer\n";
    delete next_layer;
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
#pragma once
#include "Model.cpp"

Model& make_model() {
    Input input(2);
    Neuron x1(4, &input);
    Neuron x2(4, &x1);
    Model model(input, x2);
    model.compile();
    return model;
}


int main(){ 
    Model model = make_model();

    return 0;
}

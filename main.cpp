#include "Model.cpp"

Model* make_model() {
    std::cout << "Begin\n";
    Input* input = new Input(2);
    std::cout << "Begin\n";
    Neuron* x1 = new Neuron(4, input);
    std::cout << "Begin\n";
    Neuron* x2 = new Neuron(1, x1);
    std::cout << "Begin\n";
    Model* model = new Model(input, x2);
    std::cout << "4\n";
    model->compile();
    return model;
}


int main(){ 
    Model* model = make_model();
    model->summary();




    int A1[] = {1, 2};
    Matrix<double> A(2, A1);
    A[0] = 1;
    A[1] = 5;
    try{
        (model->forward_propagation(A)).print_mat();
    }
    catch(MatrixException &e){
        std::cout << e.getMessage();
    }

    delete model;
    return 0;
}

#include "Model.cpp"

std::ostream &operator<<(std::ostream& os, const std::vector<double>& mas){
    for (unsigned int i = 0; i < mas.size(); i++)
        { os << mas[i] << " "; }
    os << std::endl;
    return os;
}


Model* make_model() {
    Input* input = new Input(2);
    Neuron* x1 = new Neuron(4, input);
    Neuron* x2 = new Neuron(1, x1);
    Model* model = new Model(input, x2);
    model->compile();
    return model;
}


int main(){ 
    Model* model = make_model();
    model->summary();

    std::vector<double> input_vector;
    input_vector.push_back(1);
    input_vector.push_back(5);

    std::vector<double> result_vector = model->forward_propagation(input_vector);
    std::cout << "Input vec: \n" << input_vector << "Result:\n" << result_vector;

    /*
    int A1[] = {1, 2};
    Matrix<double> result, input(2, A1);
    input[0] = 1;
    input[1] = 5;
    try{
        result = model->forward_propagation(input);
    }
    catch(MatrixException &e){
        std::cout << e.getMessage();
    }

    std::cout << "Input mat: \n" << input << "Result:\n" << result;
    */

    delete model;
    return 0;
}

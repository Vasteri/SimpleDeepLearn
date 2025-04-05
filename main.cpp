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
    Layer::speed_learn = 0.1;
    Model* model = make_model();
    model->summary();

    std::vector<double> input_vector;
    input_vector.push_back(1);
    input_vector.push_back(5);

    std::vector<double> result_vector = model->forward_propagation(input_vector);
    std::cout << "Input vec: \n" << input_vector << "Result:\n" << result_vector << std::endl;


    const int n = 100;
    std::vector<std::vector<double>> x(n), y_true(n);
    int a, b, r;
    for (unsigned int i = 0; i < n; i++){
        a = std::rand() % 2;
        b = std::rand() % 2;
        x[i].push_back(a);
        x[i].push_back(b);
        if (a != b)
            r = 1;
        else
            r = 0;
        y_true[i].push_back(r);
    }

    std::vector<double> y_pred;
    for (unsigned int i = 0; i < n; i++){
        y_pred = model->forward_propagation(x[i]);
        std::cout << i << ": " << y_pred[0] - y_true[i][0] << " " << y_true[i][0] << " " << y_pred[0] << std::endl;
        model->backward_propagation(y_pred, y_true[i]);
    }


    std::cout << std::rand() % 2 << std::rand() % 2 << std::endl;

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

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
    Layer::speed_learn = 0.003;
    Model* model = make_model();
    model->summary();

    std::vector<double> input_vector;
    input_vector.push_back(1);
    input_vector.push_back(5);

    std::vector<double> result_vector = model->forward_propagation(input_vector);
    std::cout << "Input vec: \n" << input_vector << "Result:\n" << result_vector << std::endl;


    const int n = 1000;
    std::vector<std::vector<double>> x(n), y_true(n);
    int a, b;
    double r;
    for (unsigned int i = 0; i < n; i++){
        a = std::rand() % 6;
        b = std::rand() % 6;
        x[i].push_back(a);
        x[i].push_back(b);
        r = 7.0 * a - 2.0 * (double)(b) + 7.0;
        y_true[i].push_back(r);
    }

    std::vector<double> y_pred;
    for (unsigned int i = 0; i < n; i++){
        //if (!(x[i][0] == 0 && x[i][1] == 1)) {
        y_pred = model->forward_propagation(x[i]);
        std::cout << i << ": x:";
        std::cout << i << ": " << y_pred[0] - y_true[i][0] << " " << y_true[i][0] << " " << y_pred[0];
        model->backward_propagation(y_pred, y_true[i]);
        std::cout << " -> " << (model->forward_propagation(x[i]))[0] << std::endl;
        //}
    }

    std::cout << "Test:" << std::endl;
    std::vector<std::vector<double>> test(4);
    test[0].push_back(0);
    test[0].push_back(0);
    test[1].push_back(1);
    test[1].push_back(0);
    test[2].push_back(0);
    test[2].push_back(1);
    test[3].push_back(1);
    test[3].push_back(1);
    for (unsigned int i = 0; i < 4; i++){
        std::cout << i << ": " << model->forward_propagation(test[i]) << std::endl;
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

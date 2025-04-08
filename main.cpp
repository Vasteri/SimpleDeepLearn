#include "Model.cpp"

std::ostream &operator<<(std::ostream& os, const std::vector<double>& mas){
    for (unsigned int i = 0; i < mas.size(); i++)
        { os << mas[i] << " "; }
    os << std::endl;
    return os;
}


Model* make_model() {
    Layer* x;
    Input* input = new Input(2);
    x = new Neuron(4, input);
    x = new Neuron(1, x);
    Model* model = new Model(input, x);
    model->compile();
    return model;
}

Model* make_model2() {
    Layer* x;
    Input* input = new Input(2);
    x = new Neuron(10, input);
    x = new Activation("tanh", x);
    x = new Neuron(1, x);
    Model* model = new Model(input, x);
    model->compile();
    return model;
}


void fit(Model* model, unsigned int n, std::vector<std::vector<double>>& x, std::vector<std::vector<double>>& y_true){
    std::vector<double> y_pred;
    for (unsigned int i = 0; i < n; i++){
        y_pred = model->forward_propagation(x[i]);
        if ((i % 100) == 0)
            std::cout << i << ": " << y_pred[0] - y_true[i][0] << " " << y_true[i][0] << " " << y_pred[0];
        model->backward_propagation(y_pred, y_true[i]);
        if ((i % 100) == 0)
           std::cout << " -> " << (model->forward_propagation(x[i]))[0] << std::endl;
    }
    std::cout << "End fit\n";
}


int main(){
    // prepare data
    const int n = 10000;
    std::vector<std::vector<double>> x(n), y_true(n);
    int a, b;
    double r;
    for (unsigned int i = 0; i < n; i++){
        a = std::rand() % 6;
        b = std::rand() % 6;
        x[i].push_back(a);
        x[i].push_back(b);
        r = -7.0 * a - 2.0 * (double)(b) + 7.0;
        y_true[i].push_back(r);
    }
    std::vector<std::vector<double>> test(4);
    test[0].push_back(0);
    test[0].push_back(0);
    test[1].push_back(1);
    test[1].push_back(0);
    test[2].push_back(0);
    test[2].push_back(1);
    test[3].push_back(1);
    test[3].push_back(1);


    Model* model  = make_model();
    Model* model2 = make_model2();
    model->summary();

    // test forward propagation
    std::vector<double> input_vector;
    input_vector.push_back(1);
    input_vector.push_back(5);
    std::vector<double> result_vector = model->forward_propagation(input_vector);
    std::cout << "Input vec: \n" << input_vector << "Result:\n" << result_vector << std::endl;

    
    try {
    Layer::speed_learn = 0.003;
    fit(model, 1000, x, y_true);
    //Layer::speed_learn = 0.01;
    fit(model2, 1000000, x, y_true);
    }
    catch(std::bad_alloc &e){
        std::cout << "-------"  << "++++";
    }

    std::cout << "Test1:" << std::endl;
    for (unsigned int i = 0; i < 4; i++){
        std::cout << i << ": " << model->forward_propagation(test[i]);
    }
    std::cout << "Test2:" << std::endl;
    for (unsigned int i = 0; i < 4; i++){
        std::cout << i << ": " << model2->forward_propagation(test[i]);
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
    delete model2;
    return 0;
}

#include "Matrix/Matrix.cpp"
#include "DeepLearn/Model.cpp"



std::ostream &operator<<(std::ostream& os, const std::vector<double>& mas){
    for (unsigned int i = 0; i < mas.size(); i++)
        { os << mas[i] << " "; }
    os << std::endl;
    return os;
}


Model* make_model0() {
    Layer* x;
    Input* input = new Input(2);
    x = new Neuron(1, input);
    Model* model = new Model(input, x);
    model->compile();
    return model;
}


Model* make_model() {
    Layer* x;
    Input* input = new Input(2);
    x = new Neuron(10, input);
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
    x = new Neuron(1,  x);
    Model* model = new Model(input, x);
    model->compile();
    return model;
}

Model* make_model3() {
    Layer* x;
    Input* input = new Input(2);
    x = new Neuron(10, input);
    x = new Activation("tanh", x);
    x = new Neuron(10, x);
    x = new Activation("tanh", x);
    x = new Neuron(1, x);
    Model* model = new Model(input, x);
    model->compile();
    return model;
}


void grapf(){

}


int main(){
    // prepare learning data
    const int n = 100000;
    std::vector<std::vector<double>> x(n), y_true(n);
    int a, b;
    double r;
    for (unsigned int i = 0; i < n; i++){
        a = std::rand() % 5;
        b = std::rand() % 5;
        x[i].push_back(a);
        x[i].push_back(b);
        r = -7.0 * a - 2.0 * (double)(b) + 7.0;
        y_true[i].push_back(r);
    }

    
    // prepate test data
    std::vector<std::vector<double>> test(4);
    test[0].push_back(0);
    test[0].push_back(0);
    test[1].push_back(1);
    test[1].push_back(0);
    test[2].push_back(0);
    test[2].push_back(1);
    test[3].push_back(1);
    test[3].push_back(1);


    Model* model0 = make_model0();
    Model* model  = make_model();
    Model* model2 = make_model2();
    Model* model3 = make_model3();
    model->summary();

    // test forward propagation
    std::vector<double> input_vector;
    input_vector.push_back(1);
    input_vector.push_back(5);
    std::vector<double> result_vector = model->forward_propagation(input_vector);
    std::cout << "Input vec: \n" << input_vector << "Result:\n" << result_vector << std::endl;

    
    Layer::speed_learn = 0.005; //0.003
    model0 ->fit_chaotic(x, y_true);
    model  ->fit_chaotic(x, y_true);
    Layer::speed_learn = 0.005;
    model2 ->fit_chaotic(x, y_true);
    model3 ->fit_chaotic(x, y_true);


    std::cout << "Test0:" << std::endl;
    for (unsigned int i = 0; i < 4; i++){
        std::cout << i << ": " << model0->forward_propagation(test[i]);
    }
    std::cout << "Test1:" << std::endl;
    for (unsigned int i = 0; i < 4; i++){
        std::cout << i << ": " << model->forward_propagation(test[i]);
    }
    std::cout << "Test2:" << std::endl;
    for (unsigned int i = 0; i < 4; i++){
        std::cout << i << ": " << model2->forward_propagation(test[i]);
    }
    std::cout << "Test3:" << std::endl;
    for (unsigned int i = 0; i < 4; i++){
        std::cout << i << ": " << model3->forward_propagation(test[i]);
    }


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
    model0->view_weigth();
    std::cout << "True weigth: -7, -2, 7" << std::endl;
    delete model0;
    delete model;
    delete model2;
    delete model3;
    return 0;
}

#include <vector>

class Net {
    private:

    public:
        std::vector<double> forward_propagation(std::vector<double>);
        void backward_propagation(std::vector<double>);
}
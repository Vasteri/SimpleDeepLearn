class Layer {
    protected:
        int   input_shape;
        int  output_shape;
        Matrix<double>  input;
    public:
        Layer* prev_layer;
        Layer* next_layer;
        static double speed_learn;
        bool trainable;
        
        virtual ~Layer();

        int get_input_shape();
        int get_output_shape();

        virtual void summary();
        virtual void view_weigth();
        virtual Matrix<double>  forward_propagation(Matrix<double>& input_outside);
        virtual void backward_propagation(Matrix<double>& input_outside);
};

template <typename Type>
class Matrix {
    private:
        Type* mat;
        int dim;
        int* dims;
        int memory;
    public:
        Matrix(int argc, int argv[]);

        ~Matrix();
        Matrix(const Matrix& mat2);    // copy
        Matrix(Matrix&& mat2);         // move
        Matrix<Type> operator =(const Matrix& mat2); // copy assignment
        Matrix<Type> operator =(Matrix&& mat2);      // move assignment

        int  GetDim()    const;
        int GetDims(const int id)   const;
        int  GetMemory() const;
        void print_mat(const char* out = "");
        void print_info();

        Matrix<Type> T();

        Matrix<Type> operator - ();
        Type&        operator [](const int id) const;
        Matrix<Type> operator + (const Matrix<Type>& mat2);
        Matrix<Type> operator - (const Matrix<Type>& mat2);
        Matrix<Type> operator * (const Matrix<Type>& mat2);
        template <typename Type2> friend Matrix<Type2> operator+(Matrix<Type2>& mat2, Type2 element);
        template <typename Type2> friend Matrix<Type2> operator-(Matrix<Type2>& mat2, Type2 element);
        template <typename Type2> friend Matrix<Type2> operator*(Matrix<Type2>& mat2, Type2 element);
        template <typename Type2> friend Matrix<Type2> operator+(Type2 element, Matrix<Type2>& mat2);
        template <typename Type2> friend Matrix<Type2> operator-(Type2 element, Matrix<Type2>& mat2);
        template <typename Type2> friend Matrix<Type2> operator*(Type2 element, Matrix<Type2>& mat2);
        /*
        Matrix<Type>& operator += (const Matrix<Type> mat2);
        Matrix<Type>& operator -= (const Matrix<Type> mat2);
        Matrix<Type>& operator *= (const Matrix<Type> mat2);
        Matrix<Type>& operator += (const Type element);
        Matrix<Type>& operator -= (const Type element);
        Matrix<Type>& operator *= (const Type element);
        */
};



class MatrixException
{
public: 
    MatrixException(std::string message): message{message}{}
    std::string getMessage() const {return message;}
private:
    std::string message;
};
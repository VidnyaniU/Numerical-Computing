// header class for complex number
class Complex
{
public:
    double real;
    double imag;
    Complex();
    void printComplex();
    void add(Complex, Complex);
    void sub(Complex, Complex);
    void mul(Complex, Complex);
    void div(Complex, Complex);
    double norm(Complex);
    void conjugate();
};

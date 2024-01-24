#include <iostream>
#include <math.h>
#include "MyComplex.hpp" //header file we created

using namespace std;

Complex::Complex()
{
    real = 0;
    imag = 0;
}

void Complex::printComplex()
{
    cout << real << " + " << imag << "i" << endl;
}

void Complex::add(Complex c1, Complex c2)
{
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
    cout << real << " + " << imag << " i " << endl;
}

void Complex::sub(Complex c1, Complex c2)
{
    real = c1.real - c2.real;
    imag = c1.imag - c2.imag;
    cout << real << " - " << imag << " i " << endl;
}

// (a + ib) (c + id) = (ac - bd) + i(ad + bc)

void Complex::mul(Complex c1, Complex c2)
{
    real = (c1.real * c2.real - c1.imag * c2.imag);
    imag = (c1.real * c2.imag + c2.real * c1.imag);
    cout << real << " + " << imag << " i " << endl;
}

void Complex::div(Complex c1, Complex c2)
{
    real = (c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    imag = (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    cout << real << " + " << imag << " i " << endl;
}

void Complex ::norm(Complex c1)
{
    double r = sqrt(real * real + imag * imag);
    cout << "Norm is " << r << endl;
}

void Complex ::conjugate()
{
    if (imag < 0)
        cout << real << " + " << imag << " i " << endl;

    else
        cout << real << " - " << imag << " i " << endl;
}

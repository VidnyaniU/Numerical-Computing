#include <iostream>
#include <math.h>
#include "MyComplex.hpp" //header file we created

using namespace std;

// default constructor
Complex::Complex()
{
    real = 0;
    imag = 0;
}

// to print the complex number
void Complex::printComplex()
{
    if (imag >= 0)
    {
        cout << real << " + " << imag << "i" << endl;
    }
    else
    {
        cout << real << " " << imag << "i" << endl;
    }
}

// to add two complex numbers
void Complex::add(Complex c1, Complex c2)
{
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
}

// to subtract two complex numbers
void Complex::sub(Complex c1, Complex c2)
{
    real = c1.real - c2.real;
    imag = c1.imag - c2.imag;
}

// to multiply two complex numbers
// (a + ib) (c + id) = (ac - bd) + i(ad + bc)

void Complex::mul(Complex c1, Complex c2)
{
    real = (c1.real * c2.real - c1.imag * c2.imag);
    imag = (c1.real * c2.imag + c2.real * c1.imag);
}

// to divide two complex numbers
void Complex::div(Complex c1, Complex c2)
{
    real = (c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    imag = (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
}

// to find norm of a complex number
double Complex ::norm(Complex c1)
{
    return sqrt(real * real + imag * imag);
}

// to find conjugate of a complex number
void Complex ::conjugate()
{
    imag = -imag;
}

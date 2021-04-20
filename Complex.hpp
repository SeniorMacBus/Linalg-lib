#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <iostream>


#define PI 3.14159265358979

class Complex
{
    public:
        Complex();
        Complex(double a, double b, bool alg);
        ~Complex();

        void print_alg();
        void print_trig();
        void print_euler();

        Complex operator+ (const Complex &other) const;
        Complex operator- (const Complex &other) const;
        Complex operator+= (const Complex &other);
        Complex operator-= (const Complex &other);

    private:
        double _re; //real part
        double _im; //imaginary part
        double _r; //radius, or magnitude of complex number
        double _phi; //phase of the complex number
};

#endif //COMPLEX_H

/*
LEARN PREPROCESSORS AND TEMPLATE CLASSES
*/
#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <iostream>

class Complex
{
    public:
        Complex();
        Complex(double a, double b, bool alg = true);
        ~Complex();

        inline double get_re() const {return _re;}; //returns real part
        inline double get_im() const {return _im;}; //returns imaginary part
        inline double get_r() const {return _r;}; //returns the lenght
        inline double get_phi() const {return _phi;}; //returns the angle
        void set_re(double re); //sets the real part
        void set_im(double im); //sets the imaginary part
        void set_r(double r); //sets the length
        void set_phi(double phi); //sets the angle

        void print_alg() const; //prints the number in the algebraic form ( a+bi )
        void print_trig() const; //prints the number in the trigonometric form ( r*(cos(phi)+i*sin(phi)) )
        void print_euler() const; //prints the number in the Euler form ( r*exp(i*phi) )

        void conjungate(); //conjugates the number
        double abs_val() const {return _r;}; //returns the manitude of the number

        Complex operator+ (const Complex &other) const;
        Complex operator- (const Complex &other) const;
        Complex operator+= (const Complex &other);
        Complex operator-= (const Complex &other);
        Complex operator* (const Complex &other) const;
        Complex operator*= (const Complex &other);
        Complex operator*= (const double d);
        Complex operator= (const Complex &z);

    private:
        double _re; //real part
        double _im; //imaginary part
        double _r; //radius, or magnitude of complex number
        double _phi; //phase of the complex number
};

Complex operator* (const double d, Complex &z);
Complex operator* (Complex &z, const double d);
bool operator== (const Complex &z1, const Complex &z2);
Complex pow(Complex z, double n);
Complex root(Complex z, double n);

int round_to_zero(double d);

#endif //COMPLEX_H
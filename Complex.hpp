#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <iostream>


#define PI 3.14159265358979

class Complex
{
    public:
        Complex();
        Complex(double a, double b, bool alg = true);
        ~Complex();

        inline double get_re() {return _re;};
        inline double get_im() {return _im;};
        inline double get_r() {return _r;};
        inline double get_phi() {return _phi;};
        void set_re(double re);
        void set_im(double im);

        void print_alg();
        void print_trig();
        void print_euler();

        void adjungate();
        double abs_val() {return _r;};
        Complex pow(double n);

        Complex operator+ (const Complex &other) const;
        Complex operator- (const Complex &other) const;
        Complex operator+= (const Complex &other);
        Complex operator-= (const Complex &other);
        Complex operator* (const Complex &other) const;
        Complex operator*= (const Complex &other);
        Complex operator*= (const double d);

    private:
        double _re; //real part
        double _im; //imaginary part
        double _r; //radius, or magnitude of complex number
        double _phi; //phase of the complex number
};

Complex operator* (const double d, Complex &z);
Complex operator* (Complex &z, const double d);

#endif //COMPLEX_H

//pow() függvény nem működik, javítsd ki!!!!
//vezess be pontosságot!!!!!


/*
LEARN PREPROCESSORS AND TEMPLATE CLASSES
*/
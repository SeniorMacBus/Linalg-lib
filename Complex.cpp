#include "Complex.hpp"

Complex::Complex()
{
    _re = 0;
    _im = 1;
    _r = 1;
    _phi = PI / 2;
}

Complex::Complex(double a, double b, bool alg = true)
{
    if(alg)
    {
        _re = a;
        _im = b;
        _r = _re * _re + _im * _im;
        _phi = atan2(_im, _re);
    }
    else
    {
        _r = a;
        _phi = b;
        _re = _r * cos(_phi);
        _im = _r * sin(_phi);
    }
}

Complex::~Complex()
{

}

void Complex::print_alg()
{
    std::cout << _re << " + " << _im << 'i' << std::endl;
}

void Complex::print_trig()
{
    std::cout << _r << "(cos(" << _phi << ") + sin(" << _phi << ")i)" << std::endl;;
}

void Complex::print_euler()
{
    std::cout << _r << "exp(" << _phi << "i)" << std::endl; 
}

Complex Complex::operator+ (const Complex &other) const
{
    return Complex(_re + other._re, _im + other._im, true);
}

Complex Complex::operator- (const Complex &other) const
{
    return Complex(_re - other._re, _im - other._im);
}

Complex Complex::operator+= (const Complex &other)
{
    *this = *this + other;
    return *this;
}

Complex Complex::operator-= (const Complex &other)
{
    *this = *this - other;
    return *this;
}
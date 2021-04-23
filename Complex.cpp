#include "Complex.hpp"

//Constructors and destructors #######################################

Complex::Complex()
{
    _re = 0;
    _im = 1;
    _r = 1;
    _phi = PI / 2;
}

Complex::Complex(double a, double b, bool alg)
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

//Printers ##############################################################################

void Complex::print_alg()
{
    if(_re != 0.0)
    {
        if(_im > 0)
        {
            std::cout << _re << " + " << _im << 'i' << std::endl;
        }
        else if(_im < 0)
        {
            std::cout << _re << " - " << std::abs(_im) << 'i' << std::endl;
        }
        else if(_im == 0)
        {
            std::cout << _re << std::endl;
        }
    }
    else
    {
        std::cout << _im << 'i' << std::endl;
    }
}

void Complex::print_trig()
{
    std::cout << _r << "(cos(" << _phi << ") + sin(" << _phi << ")i)" << std::endl;;
}

void Complex::print_euler()
{
    std::cout << _r << "exp(" << _phi << "i)" << std::endl; 
}

//Complex operations ##################################################################

void Complex::adjungate()
{
    _im = -_im;
    _phi = atan2(_im, _re);
}

Complex Complex::pow(double n)
{
    return Complex(std::pow(_r, n), _phi * n, false);
}

//Operator overloads ##################################################################

Complex Complex::operator+ (const Complex &other) const
{
    return Complex(_re + other._re, _im + other._im);
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

Complex Complex::operator* (const Complex &other) const
{
    return Complex(_r * other._r, _phi + other._phi, false);
}

Complex Complex::operator*= (const Complex &other)
{
    *this = *this * other;
    return *this;
}

Complex operator* (const double d, Complex &z)
{
    return Complex(d * z.get_re(), d * z.get_im());
}

Complex operator* (Complex &z, const double d)
{
    return Complex(d * z.get_re(), d * z.get_im());
}

Complex Complex::operator*= (const double d)
{
    *this = *this * d;
    return *this;
}
#include "Complex.hpp"

//Constructors and destructors ########################################################

Complex::Complex()
{
    _re = 0;
    _im = 1;
    _r = 1;
    _phi = M_PI / 2;
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
        _re = round_to_zero(_r * cos(_phi));
        _im = round_to_zero(_r * sin(_phi));
    }
}

Complex::~Complex()
{

}

//Printers ##############################################################################

void Complex::print_alg() const
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
        if(_im != 0)
        {
            std::cout << _im << 'i' << std::endl;
        }
        else
        {
            std::cout << 0 << std::endl;
        }
    }
}

void Complex::print_trig() const
{
    if(_r != 0)
    {
        std::cout << _r << "(cos(" << _phi << ") + sin(" << _phi << ")i)" << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
    
}

void Complex::print_euler() const
{
    if(_r != 0)
    {
        if(_phi != 0)
        {
            std::cout << _r << "exp(" << _phi << "i)" << std::endl;
        }
        else
        {
            std::cout << _r << std::endl;
        }
    }
    else
    {
        std::cout << 0 << std::endl;
    }
}

//Complex operations ##################################################################

void Complex::conjungate()
{
    _im = -_im;
    _phi = atan2(_im, _re);
}

Complex pow(Complex z, double n)
{
    return Complex(std::pow(z.get_r(), n), z.get_phi() * n, false);
}

Complex root(Complex z, double n)
{
    return Complex(std::pow(z.get_r(), 1.0 / n), z.get_phi() / n, false);
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

bool operator== (const Complex &z1, const Complex &z2)
{
    if((z1.get_re() == z2.get_re()) && (z1.get_im() == z2.get_im()))
    {
        return true;
    }

    return false;
}

Complex Complex::operator= (const Complex &z)
{
    if(this == &z)
    {
        return *this;
    }

    _re = z._re;
    _im = z._im;
    _r = z._r;
    _phi = z._phi;

    return *this;
}

int round_to_zero(double d)
{
    if(d < 1e-15 && d > 0.0)
    {
        return 0;
    }
    return d;
}
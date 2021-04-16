#include "Vector.h"

//Constructors ############################################################################################################
Vector::Vector()
{
    //creates a 2d unit vector
    _dims = 2;
    _vals.push_back(1);
    _vals.push_back(0);
    _l = 1;
    transposed = false;
}

Vector::Vector(int dims)
{
    //creates a unit vector
    _dims = dims;

    for(int i = 0; i < _dims; ++i)
    {
        _vals.push_back(1 / sqrt(_dims));
    }
    _l = 1;
    transposed = false;
}

Vector::Vector(int dims, double *vals)
{
    _dims = dims;

    for(int i = 0; i < _dims; ++i)
    {
        _vals.push_back(vals[i]);
    }
    _l = len();
    transposed = false;
}

Vector::~Vector()
{
    //dtor
}

//Misc member functions #####################################################################################################
void Vector::print()
{
    std::cout << '[';
    for(int i = 0; i < _dims - 1; ++i)
    {
        std::cout << _vals.at(i) << ", ";
    }
    std::cout << _vals.at(_dims - 1) << ']' << std::endl;
}

void Vector::t()
{
    transposed = transposed ? false : true;
}

//Calculationg member functions #############################################################################################
double Vector::len()
{
    int s = 0;
    for(int i = 0; i < _dims; ++i)
    {
        s += (_vals.at(i) * _vals.at(i));
    }

    return sqrt(s);
}

void Vector::normalize()
{
    for(int i = 0; i < _dims; ++i)
    {
        _vals.at(i) /= _l;
    }

    _l = 1;
}

void Vector::set_values(double *p)
{
    for(int i = 0; i < _dims; ++i)
    {
        _vals.at(i) = p[i];
    }
}

//Calculating global functions ############################################################################################
double dot_prod(const Vector &v1, const Vector &v2)
{
    if(v1.get_dim() == v2.get_dim())
    {
        int dims = v1.get_dim();
        double s = 0;

        for(int i = 0; i < dims; ++i)
        {
            s += v1.get_val(i) * v2.get_val(i);
        }

        return s;
    }
    else
    {
        throw "Dimensions do not match!";
    }
}

Vector cross_prod(const Vector &v1, const Vector &v2)
{
    if(v1.get_dim() != 3 || v2.get_dim() != 3)
    {
        throw "This operation only works in the +D linear space!";
    }
    else
    {
        Vector u(3);

        u.set_val(0, v1.get_val(1) * v2.get_val(2) - v1.get_val(2) * v2.get_val(1));
        u.set_val(1, v1.get_val(2) * v2.get_val(0) - v1.get_val(0) * v2.get_val(2));
        u.set_val(2, v1.get_val(0) * v2.get_val(1) - v1.get_val(1) * v2.get_val(0));

        return u;
    }
}

//Overloaded operators ####################################################################################################
Vector Vector::operator+ (const Vector &v) const
{
    if(_dims == v._dims)
    {
        Vector u(_dims);

        for(int i = 0; i < _dims; ++i)
        {
            u.set_val(i, _vals[i] + v.get_val(i));
        }

        return u;
    }
    else
    {
        throw "Dimensions do not match!";
    }
}

Vector Vector::operator+= (const Vector &v)
{
    *this = *this + v;

    return *this;
}

Vector Vector::operator- (const Vector &v) const
{
    if(_dims == v._dims)
    {
        Vector u(v.get_dim());

        for(int i = 0; i < _dims; ++i)
        {
            u.set_val(i, _vals.at(i) - v.get_val(i));
        }

        return u;
    }
    else
    {
        throw "Dimensions do not match!";
    }
}

Vector Vector::operator-= (const Vector &v)
{
    *this = *this - v;

    return *this;
}

Vector operator* (const Vector &v, const double d)
{
    Vector u(v.get_dim());
    for(int i = 0; i < v.get_dim(); ++i)
    {
        u.set_val(i, v.get_val(i) * d);
    }

    return u;
}

Vector operator* (const double d, const Vector &v)
{
    Vector u(v.get_dim());
    for(int i = 0; i < v.get_dim(); ++i)
    {
        u.set_val(i, v.get_val(i) * d);
    }

    return u;
}

Vector Vector::operator*= (const double d)
{
    *this = *this * d;

    return *this;
}

Vector Vector::operator/ (const double d) const
{
    Vector u(_dims);
    for(int i = 0; i < _dims; ++i)
    {
        u.set_val(i, _vals.at(i) / d);
    }

    return u;
}

Vector Vector::operator/= (const double d)
{
    *this = *this / d;

    return *this;
}

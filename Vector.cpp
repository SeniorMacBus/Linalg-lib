#include "Vector.h"

//Constructors ############################################################################################################
Vector::Vector()
{
    //creates a 2d unit vector
    _dims = 2;
    _vals[0] = 1;
    _vals[1] = 0;
    _l = 1;
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
}

Vector::Vector(int dims, double *vals)
{
    _dims = dims;

    for(int i = 0; i < _dims; ++i)
    {
        _vals.push_back(vals[i]);
    }
    _l = len();
}

Vector::~Vector()
{
    //dtor
}

//Calculationg member functions #############################################################################################
double Vector::len()
{
    int s = 0;
    for(int i = 0; i < _dims; ++i)
    {
        s += (_vals[i] * _vals[i]);
    }

    return sqrt(s);
}

void Vector::normalize()
{
    for(int i = 0; i < _dims; ++i)
    {
        _vals[i] /= sqrt(_l);
    }

    _l = 1;
}

//Calculating global functions ############################################################################################
double dot_prod(const Vector &v1, const Vector &v2)
{
    int dims = v1.get_dim();
    double s = 0;

    for(int i = 0; i < dims; ++i)
    {
        s += v1.get_val(i) * v2.get_val(i);
    }

    return s;
}

Vector cross_prod(const Vector &v1, const Vector &v2)
{
    Vector u(3);

    for(int i = 0; i < 3; ++i)
    {

    }
}

int levi_civita(int i, int j, int k)
{
    if(i == j || j == k || i == k)
    {
        return 0;
    }
}

//Overloaded operators ####################################################################################################
Vector Vector::operator+ (const Vector &v) const
{
    Vector u(v.get_dim());

    for(int i = 0; i < _dims; ++i)
    {
        u.set_val(i, _vals[i] + v.get_val(i));
    }

    return u;
}

Vector Vector::operator+= (const Vector &v)
{
    *this = *this + v;

    return *this;
}

Vector Vector::operator- (const Vector &v) const
{
    Vector u(v.get_dim());

    for(int i = 0; i < _dims; ++i)
    {
        u.set_val(i, _vals[i] - v.get_val(i));
    }

    return u;
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
        u.set_val(i, _vals[i] / d);
    }

    return u;
}

Vector Vector::operator/= (const double d)
{
    *this = *this / d;

    return *this;
}

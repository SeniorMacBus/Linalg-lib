#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

class Vector
{
    public:
        Vector();
        Vector(int dims);
        Vector(int dims, double *vals);
        ~Vector();

        //getters
        inline double get_l() const {return _l;};
        inline double get_val(int i) const {return _vals.at(i);};
        inline int get_dim() const {return _dims;};

        //setters
        void set_val(int i, double val) {_vals.at(i) = val;}; //sets the specific value of a vector
        void set_len(); //sets the length
        void set_values(double *p); //sets the values to a given array

        Vector operator+ (const Vector &v) const;
        Vector operator+= (const Vector &v);
        Vector operator- (const Vector &v) const;
        Vector operator-= (const Vector &v);
        Vector operator*= (const double d);
        Vector operator/ (const double d) const;
        Vector operator/= (const double d);

        void normalize(); //creates a unit vector
        void print(); //prints out the vector
        void t(); //transposes the vector

    private:
        double len(); //calculates the length of the vector

        int _dims;
        double _l;
        std::vector<double> _vals;
        bool transposed;

};

Vector operator* (const Vector &v, const double d);
Vector operator* (const double d, const Vector &v);
double dot_prod(const Vector &v1, const Vector &v2);
Vector cross_prod(const Vector &v1, const Vector &v2);

bool check_cyc(int a, int b, int j);
//NEED TO DO
// diadic_prod() function (global)
#endif // VECTOR_H

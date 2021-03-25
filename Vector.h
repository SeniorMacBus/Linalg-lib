#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cmath>


class Vector
{
    public:
        Vector();
        Vector(int dims);
        Vector(int dims, double *vals);
        ~Vector();

        //getters
        inline double get_l() const {return _l;};
        inline double get_val(int i) const {return _vals[i];};
        inline int get_dim() const {return _dims;};

        //setters
        void set_val(int i, int val) {_vals[i] = val;};
        void set_len();

        Vector operator+ (const Vector &v) const;
        Vector operator+= (const Vector &v);
        Vector operator- (const Vector &v) const;
        Vector operator-= (const Vector &v);
        Vector operator*= (const double d);
        Vector operator/ (const double d) const;
        Vector operator/= (const double d);


        void normalize(); //creates a unit vector
        void print();

    private:
        double len(); //calculates the length of the vector

        int _dims;
        int _l;
        std::vector<double> _vals;

};

Vector operator* (const Vector &v, const double d);
Vector operator* (const double d, const Vector &v);
double dot_prod(const Vector &v1, const Vector &v2);
Vector cross_prod(const Vector &v1, const Vector &v2);
int levi_civita(int i, int j, int k);

bool check_cyc(int a, int b, int j);
//NEED TO DO
//ERROR HANDLING
//How to handle permutations

// dot_prod() function (global)
// cross_prod() function (member)
// diadic_prod() function (global)
// print() function (member)
// set_values() function (member)
#endif // VECTOR_H

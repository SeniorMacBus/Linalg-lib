#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"

class Matrix
{
    public:
        Matrix();
        ~Matrix();

    private:
        int _n;
        int _m;
        int _tr;
        int _det;
        //std::vector<Vector> _m; ?
        //std::vector<std::vector<double>> _m; ?

};

//NEED TO DO
//operator+ (member)
//operator- (member)
//operator+= / operator-=
//operator*
//operator*=
//operator/
//operator/=
//print()
//transpose()
//invert()
//det()
//tr()


#endif // MATRIX_H

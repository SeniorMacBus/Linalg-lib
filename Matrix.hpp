#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.hpp"

template <typename T>
class Matrix
{
    public:
        Matrix();
        ~Matrix()
        {
            delete[] _mx;
        }

    private:
        int _n;
        int _m;
        int _tr;
        int _det;

        T* _mx;



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

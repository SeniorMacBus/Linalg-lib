#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.hpp"

template <typename T>
class Vector
{
    public:
    //ctors and dtor
        Vector()
        {
            //creates a 2d unit vector
            _dims = 2;
            _data = new T[_dims];
            _data[0] = 1;
            _data[1] = 0;
            _l = 1;
            transposed = false;
        }

        Vector(int dims)
        {
            //creates a unit vector
            _dims = dims;
            _data = new T[_dims];

            for(int i = 0; i < _dims; ++i)
            {
                _data[i] = 1 / sqrt(_dims);
            }
            
            _l = 1;
            transposed = false;
        }

        Vector(std::initializer_list<T> lista, int dims)
        {
            _dims = dims;
            _data = new T[_dims];
            int i = 0;

            for(auto element : lista)
            {
                _data[i] = element;
                ++i; 
            }

            _l = len();
            transposed = false;
        }

        ~Vector()
        {
            delete[] _data;
        }

        //getters
        inline double get_l() const {return _l;};
        inline T get_val(int i) const {return _data[i - 1];};
        inline int get_dim() const {return _dims;};

        inline T * at(int i) const {return  &(_data[i - 1]);};
        inline bool get_T() const {return transposed;};

        //setters
        void set_val(int i, T val) {_data[i - 1] = val;};
        
        void set_len(double l); //sets the length
        
        void set_values(std::initializer_list<T> lista)
        {
            int i = 0;
            for(auto element : lista)
            {
                _data[i] = element;
                ++i;
            }
        }

        //operators
        Vector operator+ (const Vector &v) const
        {
            if(_dims == v._dims)
            {
                Vector u(_dims);

                for(int i = 0; i < _dims; ++i)
                {
                    u.at(i) = _data[i] + v._data[i];
                }

                return u;
            }
            else
            {
                throw "Dimensions do not match!";
            }
        }

        Vector operator+= (const Vector &v)
        {
            *this = *this + v;

            return *this;
        }

        Vector operator- (const Vector &v) const
        {
            if(_dims == v._dims)
            {
                Vector u(v._dims);

                for(int i = 0; i < _dims; ++i)
                {
                    u.at(i) = _data[i] - v._data[i];
                }

                return u;
            }
            else
            {
                throw "Dimensions do not match!";
            }
        }

        Vector operator-= (const Vector &v)
        {
            *this = *this - v;

            return *this;
        }

        Vector operator*= (const T d)
        {
            *this = *this * d;

            return *this;
        }

        Vector operator/ (const T d) const
        {
            Vector u(_dims);
            for(int i = 0; i < _dims; ++i)
            {
                u.at(i) = _data[i] / d;
            }

            return u;
        }

        Vector operator/= (const T d)
        {
             *this = *this / d;

            return *this;
        }

        void normalize()
        {
            for(int i = 0; i < _dims; ++i)
            {
                _data[i] /= _l;
            }

            _l = 1;
        }
        
        //other functions
        void print() const
        {
            if(transposed)
            {
                std::cout << '[' << _data[0] << ',' << std::endl;
                for(int j = 1; j < _dims - 1; ++j)
                {
                    std::cout << _data[j] << ',' << std::endl;
                }
                std::cout << _data[_dims - 1] << ']' << std::endl;
            }
            else
            {
                std::cout << '[';
                for(int i = 0; i < _dims - 1; ++i)
                {
                    std::cout << _data[i] << ", ";
                }
                std::cout << _data[_dims - 1] << ']' << std::endl;
            }
        }

        void t()
        {
            transposed = transposed ? false : true;
        }

    private:
        T len()
        {
            T s = 0;
            for(int i = 0; i < _dims; ++i)
            {
                s += (_data[i] * _data[i]);
            }

            return sqrt(s);
        }

        int _dims;
        double _l;
        T *_data;
        bool transposed;

};

//operators as global functions
template <typename T>
Vector<T> operator* (const Vector<T> &v, const T d)
{
    Vector u(v.get_dim());
    for(int i = 0; i < v.get_dim(); ++i)
    {
        u.at(i) = v.get_val(i) * d;
    }

    return u;
}

template <typename T>
Vector<T> operator* (const T d, const Vector<T> &v)
{
    Vector u(v.get_dim());
    for(int i = 0; i < v.get_dim(); ++i)
    {
        u.at(i) = v.get_val(i) * d;
    }

    return u;
}

//vector operations
template <typename T>
T dot_prod(const Vector<T> &v1, const Vector<T> &v2)
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

template <typename T>
Vector<T> cross_prod(const Vector<T> &v1, const Vector<T> &v2)
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

template <typename T>
Matrix<T> diadic_prod(const Vector<T> &v1, const Vector<T> &v2)
{
    Matrix<T> MX(v1.get_dim(), v2.get_dim());

    for(int i = 0; i  < v1.get_dim(); ++i)
    {
        for(int j = 0; j < v2.get_dim(); ++j)
        {
            MX.set_val(i + 1, j + 1, v1.get_val(i + 1) * v2.get_val(j + 1));
        }
    }

    return MX;
}


#endif // VECTOR_H

#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Matrix
{
    public:
	//ctors and dtor
        Matrix(int n=2, int m=2)
		{
			_n = n;
			_m = m;
			n_el = n * m;
			_mx = new T[n_el];

			for(int i = 0; i < _n; ++i)
			{
				for(int j = 0; j < _m; ++j)
				{
					if(i == j)
					{
						_mx[i * m + j] = 1;
					}
					else
					{
						_mx[i * m + j] = 0;
					}
				}
			}
		}

		Matrix(std::initializer_list<T> l, int n, int m)
		{
			if(n * m == l.size())
			{
				_n = n;
				_m = m;
				n_el = n * m;

				_mx = new T[n_el];

				int i = 0;

				for(auto element : l)
				{
					_mx[i] = element;
					++i;
				}
			}
		}

        ~Matrix()
        {
            delete[] _mx;
        }

		//getters
		inline int get_n() const {return _n;}
		inline int get_m() const {return _m;}
		inline T get_val(int i, int j) const {return _data[(i-1) * _m + (j-1)];}
		inline T get_det() const {return _det;}
		inline T get_tr() const {return _tr;}
		inline int get_n_elm() const {return n_el;}

		//setters
		void set_val(int i, int j, T val)
		{
			_data[(i-1) * _m + (j-1)] = val;
		}

		//operators
		Matrix<T> operator+ (const Matrix<T> &MX) const
		{
			if((_n == MX._n) && (_m == MX._m))
			{
				Matrix<T> M_res(_n, _m);

				for(int i = 0; i < _n; ++i)
				{
					for(int j = 0; j < _m; ++j)
					{
						M_res._mx[i * _m + j] = _mx[i * _m + j] + MX._mx[i * _m + j];
					}
				}

				return M_res;
			}
			else
			{
				throw std::logic_error("Dimensions do not match!");
			}
		}

		Matrix<T> operator+= (const Matrix<T> &MX)
		{
			*this = *this + MX;
			return *this;
		}

		Matrix<T> operator- (const Matrix<T> &MX) const
		{
			if((_n == MX._n) && (_m == MX._m))
			{
				Matrix<T> M_res(_n, _m);

				for(int i = 0; i < _n; ++i)
				{
					for(int j = 0; j < _m; ++j)
					{
						M_res._mx[i * _m + j] = _mx[i * _m + j] - MX._mx[i * _m + j];
					}
				}

				return M_res;
			}
			else
			{
				throw std::logic_error("Dimensions do not match!");
			}
		}

		Matrix<T> operator-= (const Matrix<T> &MX)
		{
			*this = *this - MX;
			return *this;
		}

		//other functions
		void print() const
		{
			
		}

    private:
        int _n;
        int _m;
        T _tr;
        T _det;
		int n_el;

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
//inverse()
//adjoint()
//diadic_prod()


#endif // MATRIX_H

#ifndef __COMPLEX__
#define __COMPLEX__
class complex;

class complex
{
public:
    complex(double r = 0, double i = 0) : re(r), im(i) {}
    complex &operator+=(const complex &);
    double real() const { return re; }
    double imag() const { return im; }

private:
    double re, im;

    friend complex &__doapl(complex *, const complex &);
};

inline complex &
__doapl(complex *ths, const complex &r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex
operator+(const complex &x, const complex &y)
{
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator+(const complex &x, const double y)
{
    return complex(real(x) + y, imag(x));
}
inline complex
operator+(const double x, const complex &y)
{
    return complex(x + real(y), imag(y));
}

inline complex &complex::operator+=(const complex &r)
{
    return __doapl(this, r);
}

#include <iostream.h>
inline ostream&
operator <<(ostream& os,const complex&x)
{
   return os<<'('<<real(x)<<','<<imag(x)<<')'
}




inline double
imag(const complex &x)
{
    return x.imag();
}

inline double
real(const complex &x)
{
    return x.real();
}

#endif
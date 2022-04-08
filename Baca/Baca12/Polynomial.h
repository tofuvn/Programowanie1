// Van The Ho

#ifndef BACA12_POLYNOMIAL_H
#define BACA12_POLYNOMIAL_H

#include "Z3.h"
#include <string>

class Polynomial {

public:
    unsigned int degreeOfPolynomial;
    Z3 *coefficients ;

    Polynomial(unsigned int degree, Z3 *coefficients);

    Polynomial();

    //~Polynomial();

    short operator [](unsigned int index);

    unsigned int degree();

    Polynomial &operator+=(Polynomial);
    Polynomial &operator-=(Polynomial);
    Polynomial &operator*=(Polynomial);
    Polynomial &operator*=(Z3);
    Polynomial &operator/=(Z3);

    std::string toString(std::string xVar);

};
std::ostream &operator<<(std::ostream &stream, Polynomial& a);
std::istream &operator>>(std::istream &stream, Polynomial& a);
Polynomial& operator+(const Polynomial &, const Polynomial &);
Polynomial& operator-(const Polynomial &, const Polynomial &);
Polynomial& operator*(const Polynomial &, const Polynomial &);
Polynomial& operator/(const Polynomial &, short);
void mod(const Polynomial &, const Polynomial&, Polynomial&, Polynomial&);




#endif //BACA12_POLYNOMIAL_H

// Van The Ho

#ifndef BACA12_Z3_H
#define BACA12_Z3_H


#include <iostream>
class Z3 {
private:
    short num;
public:

    Z3(short);

    short getNum() const;

    Z3();

    operator short() const;

    Z3 &operator+=(Z3);

    Z3 &operator-=(Z3);

    Z3 &operator*=(Z3);

    Z3 &operator/=(short);

    Z3 &operator/=(Z3);
};

Z3 operator+(const Z3 &, const Z3 &);

Z3 operator-(const Z3 &a, const Z3 &b);

Z3 operator*(const Z3 &a, const Z3 &b);

Z3 operator/(const Z3 &a, const Z3 &b);

Z3 operator*(const Z3 &a, short c);

std::ostream &operator<<(std::ostream &stream, const Z3 &a);

short inversionOfMultiplicationInZ3(short);


#endif //BACA12_Z3_H

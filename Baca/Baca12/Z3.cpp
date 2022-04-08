// Van The Ho
#include "Z3.h"


using namespace std;

Z3::Z3(short num_) {
    num = (3 + (num_%3)) % 3;
}

Z3::Z3() : num(0) {}

Z3::operator short() const {
    return num;
}

Z3 &Z3::operator+=(Z3 otherNum) {
    num = Z3(num + otherNum.num).num;
    return *this;
}

Z3 &Z3::operator-=(Z3 otherNum) {
    num = Z3(num - otherNum.num).num;
    return *this;
}

Z3 &Z3::operator*=(Z3 otherNum) {
    num = (num * otherNum.num) % 3;
    return *this;
}

Z3 &Z3::operator/=(short c) {
    num = (num * c) % 3;
    return *this;
}

Z3 &Z3::operator/=(Z3 otherNum) {
    if (otherNum.num == 0) {
        std::cout << "Dzielenie przez zero\n";
        return *this;
    }
    num = (num * otherNum.num) % 3;
    return *this;
}

short Z3::getNum() const {
    return num;
}

short inversionOfMultiplicationInZ3(short a) {
    return a;
}



Z3 operator+(const Z3 &a, const Z3 &b) {
    return Z3((a.getNum() + b.getNum()));
}

Z3 operator-(const Z3 &a, const Z3 &b) {
    return Z3((a.getNum() - b.getNum()));
}

Z3 operator*(const Z3 &a, const Z3 &b) {
    return Z3((a.getNum() * b.getNum()));
}

Z3 operator*(const Z3 &a, const short c) {
    return Z3(a.getNum() * c);
}



Z3 operator/(const Z3 &a, const Z3 &b) {
    if (b.getNum() == 0) {
        std::cout << "Dzielenie przez zero\n";
        return Z3(b.getNum());
    }
    return Z3((a.getNum() * b.getNum()));
}

std::ostream &operator<<(std::ostream &stream, const Z3 &a) {
    stream << static_cast<short>(a);
    return stream;
}



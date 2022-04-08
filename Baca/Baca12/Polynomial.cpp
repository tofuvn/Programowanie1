// Van The Ho

#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial(unsigned int degree, Z3 *coefficients_ = nullptr) : degreeOfPolynomial(degree) {
    if (degree == 0) {
        this->coefficients = nullptr;
        return;
    }

    this->coefficients = new Z3[degree + 1];
    if (coefficients_ != nullptr) {
        for (int i = 0; i <= degree; ++i) {
            this->coefficients[i] = coefficients_[i];
        }
    }
}

Polynomial::Polynomial() : degreeOfPolynomial(0), coefficients(nullptr) {}

/*Polynomial::~Polynomial() {
    if (coefficients) {
        delete[] coefficients;
    }

}*/

short Polynomial::operator[](unsigned int index) {
    if (index < 0 or index > degreeOfPolynomial) {
        std::cout << "Niepoprawny indeks wielomianu\n";
        return coefficients[0].getNum();
    }
    return coefficients[index].getNum();
}

unsigned int Polynomial::degree() {
    return this->degreeOfPolynomial;
}

short max(short a, short b) {
    return (a > b) ? a : b;
}

Polynomial &Polynomial::operator+=(Polynomial b) {
    short size = max(this->degreeOfPolynomial, b.degreeOfPolynomial);

    auto *result = new Polynomial(size);
    result->coefficients = new Z3[size];
    for (int i = 0; i <= size; ++i) {
        result->coefficients[i] = Z3(0);
    }


    /*if (this->degreeOfPolynomial < size) {
        this->coefficients = (Z3*) realloc(this->coefficients, sizeof(Z3) * size);
    }*/

    for (int i = 0; i <= b.degree(); i++) {
        result->coefficients[i] += b.coefficients[i];
    }
    for (int i = 0; i <= this->degree(); i++) {
        result->coefficients[i] += this->coefficients[i];
    }

    this->degreeOfPolynomial = size;
    this->coefficients = new Z3[size];
    for (int i = 0; i <= size; i++) {
        this->coefficients[i] = result->coefficients[i];
    }

    return *this;
}

Polynomial &Polynomial::operator-=(Polynomial b) {
    short size = max(this->degreeOfPolynomial, b.degreeOfPolynomial);

    auto *result = new Polynomial(size);
    result->coefficients = new Z3[size + 1];
    for (int i = 0; i <= size; ++i) {
        result->coefficients[i] = Z3(0);
    }


    /*if (this->degreeOfPolynomial < size) {
        this->coefficients = (Z3*) realloc(this->coefficients, sizeof(Z3) * size);
    }*/

    for (int i = 0; i <= b.degree(); i++) {
        result->coefficients[i] -= b.coefficients[i];
    }
    for (int i = 0; i <= this->degree(); i++) {
        result->coefficients[i] += this->coefficients[i];
    }

    this->degreeOfPolynomial = size;
    this->coefficients = new Z3[size + 1];
    for (int i = 0; i <= size; i++) {
        this->coefficients[i] = result->coefficients[i];
    }

    return *this;
}

Polynomial &Polynomial::operator*=(Polynomial b) {
    short sizeOfNewPoly = degreeOfPolynomial + b.degree();
    Z3 *prod = new Z3[sizeOfNewPoly + 1];

    // Initialize the product polynomial
    for (int i = 0; i <= sizeOfNewPoly; i++) {
        prod[i] = 0;
    }

    // Multiply two polynomials term by term
    // Take ever term of first polynomial
    for (int i = 0; i <= this->degree(); i++) {
        // Multiply the current term of first polynomial
        // with every term of second polynomial.
        for (int j = 0; j <= b.degree(); j++) {
            prod[i + j] += Z3(this->coefficients[i].getNum() * b.coefficients[j].getNum());
        }
    }

    /*for (int i = 0; i <= sizeOfNewPoly; ++i) {
        std::cout << prod[i] << " ";
    }
    std::cout << std::endl;*/

    this->degreeOfPolynomial = sizeOfNewPoly;
    this->coefficients = new Z3[sizeOfNewPoly];

    for (int i = 0; i <= sizeOfNewPoly; i++) {
        this->coefficients[i] = prod[i];
    }

    return *this;
}

Polynomial &Polynomial::operator*=(Z3 a) {
    if (a.getNum() == 0) {
        this->degreeOfPolynomial = 0;
        this->coefficients = nullptr;
        return *this;
    }
    for (int i = 0; i <= this->degree(); i++) {
        this->coefficients[i] *= a;
    }
    return *this;
}

Polynomial &Polynomial::operator/=(Z3 b) {
    if (b.getNum() == 0) {
        std::cout << "Dzielenie przez zero\n";
        return *this;
    }

    for (int i = 0; i < this->degree(); ++i) {
        this->coefficients[i] *= b;
    }
    return *this;

}

std::string Polynomial::toString(std::string xVar) {
    /*std::string result = "";
    if (degree() != 0) {
        if (coefficients[0] != 0) {
            result += std::to_string(coefficients[0]);
        }

        for (int i = 1; i <= degree(); ++i) {
            if (coefficients[i] != 0)
                result += "+" + std::to_string(coefficients[i]) + "*" + std::string(xVar) + "^" +
                          std::to_string(i);
        }
    } else {
        result += "0";
    }

    return result;*/
    std::string result = "";

    if (degree() == 1) {
        result += this->coefficients[0];
        return  result;
    }

    for (int i = 0; i < degree(); ++i) {
        short coeff = this->coefficients[i].getNum();
        int pow = degree() - i;

        if (coeff == 0 && degree() > 1) {
            continue;
        }

        if (coeff == 1) {
            if (i > 0) {
                if (pow >= 1)
                    result +="+";
                else
                    result += (i > 0 ? "+" : "") +  std::to_string(coeff);
            }
        } else if (coeff == -1.0) {
            if (pow >= 1)
                result += "-";
            else
                result +=  coeff;
        } else if (coeff < 0) {
            result += "-" + std::to_string(coeff) + std::string(pow != 0 ? "*" : "");
        } else {
            result += std::string(i > 0 ? "+" : "")  + std::string(pow != 0 ? "*" : "");
            result += std::to_string(coeff);
        }

        if (pow == 1)
            result += "x";
        else if (pow > 1)
            result += "x^" + std::to_string(pow);
    }
    return result;
}

std::ostream &operator<<(std::ostream &stream, Polynomial &a) {
    stream << "{" << a.coefficients[0];
    for (unsigned int i = 1; i <= a.degree(); ++i) {
        stream << "," << a.coefficients[i];
    }
    stream << "}";
    return stream;
}

std::istream &operator>>(std::istream &stream, Polynomial &a) {
    char c;
    stream >> c;
    while (c != '{') {
        stream >> c;
    }

    int degree = 0;
    a.coefficients = new Z3[1];
    while (c != '}') {
        stream >> c;
        if (isdigit(c)) {
            degree++;
            a.degreeOfPolynomial = degree - 1;
            if (degree > 0) {
                a.coefficients = (Z3 *) (realloc(a.coefficients, degree * sizeof(Z3)));
            }

            Z3 p((short) c);
            a.coefficients[degree - 1] = p;
        }
    }
    return stream;
}

Polynomial &operator+(const Polynomial &a, const Polynomial &b) {
    short size = max(a.degreeOfPolynomial, b.degreeOfPolynomial);

    auto *result = new Polynomial(size);
    result->coefficients = new Z3[size];
    for (int i = 0; i <= size; ++i) {
        result->coefficients[i] = Z3(0);
    }

    for (int i = 0; i <= b.degreeOfPolynomial; i++) {
        result->coefficients[i] += b.coefficients[i];
    }
    for (int i = 0; i <= a.degreeOfPolynomial; i++) {
        result->coefficients[i] += a.coefficients[i];
    }

    result->degreeOfPolynomial = size;

    return *result;
}

Polynomial &operator-(const Polynomial &a, const Polynomial &b) {
    short size = max(a.degreeOfPolynomial, b.degreeOfPolynomial);

    auto *result = new Polynomial(size);
    result->coefficients = new Z3[size];
    for (int i = 0; i <= size; ++i) {
        result->coefficients[i] = Z3(0);
    }

    for (int i = 0; i <= b.degreeOfPolynomial; i++) {
        result->coefficients[i] -= b.coefficients[i];
    }
    for (int i = 0; i <= a.degreeOfPolynomial; i++) {
        result->coefficients[i] += a.coefficients[i];
    }

    result->degreeOfPolynomial = size;

    return *result;
}

Polynomial &operator*(const Polynomial &a, const Polynomial &b) {
    short sizeOfNewPoly = a.degreeOfPolynomial + b.degreeOfPolynomial;
    Z3 *prod = new Z3[sizeOfNewPoly + 1];

    // Initialize the product polynomial
    for (int i = 0; i <= sizeOfNewPoly; i++) {
        prod[i] = 0;
    }

    // Multiply two polynomials term by term
    // Take ever term of first polynomial
    for (int i = 0; i <= a.degreeOfPolynomial; i++) {
        // Multiply the current term of first polynomial
        // with every term of second polynomial.
        for (int j = 0; j <= b.degreeOfPolynomial; j++) {
            prod[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }

    Polynomial *result = new Polynomial(sizeOfNewPoly);
    result->degreeOfPolynomial = sizeOfNewPoly;
    result->coefficients = new Z3[sizeOfNewPoly + 1];

    for (int i = 0; i <= sizeOfNewPoly; i++) {
        result->coefficients[i] = prod[i];
    }

    return *result;
}

Polynomial &operator/(Polynomial &a, short c) {
    if (c == 0) {
        std::cout << "Dzielenie przez zero\n";
        return a;
    }

    Polynomial *result = new Polynomial(a.degree(), a.coefficients);
    for (int i = 0; i < result->degree(); i++) {
        result->coefficients[i] /= c;
    }

    return *result;


};

void mod(const Polynomial &u, const Polynomial &v, Polynomial &q, Polynomial &r) {
/*
    if (v.degreeOfPolynomial == 0 && v.coefficients[0].getNum() == 0) {
        std::cout << "Dzielenie przez zero\n";
        return;
    }
    if (v.degreeOfPolynomial == 0 && v.coefficients[0].getNum() != 0) {
        q = u / v.coefficients[0];
        r = 0;
        return;
    }

    if (u.degreeOfPolynomial < v.degreeOfPolynomial) {
        r.degreeOfPolynomial = u.degreeOfPolynomial;
        r.coefficients = new Z3[r.degreeOfPolynomial + 1];
        for (int i = 0; i <= r.degreeOfPolynomial;++i) {
            r.coefficients[i] = u.coefficients[i];
        }

        return;
    }*/

    short degreeOfQuotient = u.degreeOfPolynomial - v.degreeOfPolynomial;
    q.degreeOfPolynomial = degreeOfQuotient;
    q.coefficients = new Z3[degreeOfQuotient + 1];


    //poly q;
    //int i, j;
    int power = u.degreeOfPolynomial - v.degreeOfPolynomial;
    short ratio;

    //if (power < 0) return 0;

    //q = p_new(-power);
    q.degreeOfPolynomial = power;
    q.coefficients = new Z3[power + 1];


    for (int i = 0; i <= power; ++i) {
        q.coefficients[i] = 0;
    }

    r.degreeOfPolynomial = u.degreeOfPolynomial;
    r.coefficients = new Z3[power + 1];
    for (int i = 0; i <= r.degreeOfPolynomial; i++) {
        r.coefficients[i] = u.coefficients[i];
    }

    /* p: poly;  d: divisor;  r: remainder; returns quotient */
    for (int i = u.degreeOfPolynomial; i >= v.degreeOfPolynomial; i--) {
        q.coefficients[i - v.degreeOfPolynomial] = ratio = r.coefficients[i] / v.coefficients[v.degreeOfPolynomial];
        r.coefficients[i] = 0;

        for (int j = 0; j < v.degreeOfPolynomial; j++)
            r.coefficients[i - v.degreeOfPolynomial + j] -= v.coefficients[j] * ratio;
        // E(*r, i - d->power + j) -= E(d, j) * ratio;
    }
    while(r.coefficients[r.degreeOfPolynomial] == 0) {
        r.degreeOfPolynomial--;
    }
    //while (!r.coefficients[--r.degreeOfPolynomial]){};
    //while (! E(*r, --(*r)->power));

    //return q;

}





/*
Polynomial &Polynomial::operator/=(Polynomial) {
    return <#initializer#>;
}*/


//g++ -g -std=c++17 -c main.cpp
//g++ -g -std=c++17 -c Z3.cpp
//g++ -g -std=c++17 -c Polynomial.cpp
//g++ -g -std=c++17 -o executable main.o Z3.o Polynomial.o
//valgrind ./executable

// Van The Ho
// thehovnpl@gmail.com

// Free to copy or modify but recommend try your approach first, before moving on to the solution.
// I would greatly appreciate it if you kindly give me some feedback
// Self Documenting Code

#include <iostream>
#include <cstdarg>

using namespace std;

double func(double (*f)(const double *, int), ...) {


    va_list arguments;

    va_start(arguments, f);

    int num = va_arg(arguments, int);

    auto *array = new double[num];

    char *type = va_arg(arguments, char*);

    int index = 0;
    char c = type[index];

    while (c != '\0') {
        switch (c) {
            case 'i':
            case 'I':
                array[index] = va_arg(arguments, int);
                break;
            case 'd':
            case 'f':
                array[index] = va_arg(arguments, double);
                break;
            default:
                array[index] = va_arg(arguments, double);
                break;
        }
        c = type[++index];
    }

    va_end(arguments);

    return f(array, num);
}

double sum(const double *array, int n) {
    double result = 0;

    for (int i = 0; i < n; ++i) {
        result += array[i];
    }
    return result;
}

double mean(const double *array, int n) {
    return sum(array, n) / n;
}

double harmonicSum(const double *array, int n) {
    double result = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] != 0) {
            result += 1 / array[i];
        }
    }
    return result;
}

double geometricMean(const double *array, int n) {
    double result = 1;

    for (int i = 0; i < n; i++) {
        result *= array[i];
    }
    result = pow(result, 1.0 / n);
    return result;
}

int main() {
    int n = 5;
    cout << func(sum, 2, "if", 10, 2.f) << endl;
    cout << func(sum, n, "iiifd", 10, 2, 3, 4.0f, 5.0) << endl;
    cout << func(mean, n, "fdddd", 1.f, 2.f, 3.0, 4.0, 5.f) << endl;
    cout << func(harmonicSum, n, "ddddd", 1.0, 2.0, 3.0, 4.0, 5.0) << endl;
    cout << func(geometricMean, 3, "fif", 4.0, 6, 5.0) << endl;
    return 0;
}

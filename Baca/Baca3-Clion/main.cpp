#include "statistix.h"
#include <iostream>
using namespace std;
int main(){
    int t[] = {6,30,12,-81,9,-9,15,6,30,33,21,18};
    unsigned n = sizeof(t)/sizeof(int);
    int *r = new int[n];
    cout << boolalpha;

    cout << "gcd=" << gcd(n,t,r) << endl;

    for (int i = 0; i < n; i++ ) {
        cout << r[i] << " ";
    }

    delete[] r;
}
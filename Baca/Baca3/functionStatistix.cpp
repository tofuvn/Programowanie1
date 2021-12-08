// Van The Ho

#include "statistix.h"
#include <iostream> 

using namespace std;

int f(int x) {
	return x*(x-10); 
}
bool TRUE(int x) { 
	return true; 
} 
bool EVEN(int x) {
	return x%2==0; 
} 
bool ASYMMETRIC_REL(int a, int b) { 
	return 3*a<b; 
} 
double g(double x) { 
	return 7*x-2; 
}

int main() {
	
	double r=0.0; 
	int t[] = {6,30,12,-81,9,-9,15,6,30,33,21,18}; 
	unsigned n = sizeof(t)/sizeof(int);
	
	double x[] = {4,3,2,1}; 
	double p[] = {0.125,0.25,0.125}; 
	cout << expval(3,x,p,g,r) << endl; 
	cout << "expval=" << r << endl;
	
	
	return 0;
}

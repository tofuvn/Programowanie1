// Van The Ho

#include "statistix.h"
#include <iostream> 
#include <chrono>



using namespace std;
using namespace std::chrono;


int findSum(int arr[], int size, int (*f) (int))
{
 int sum = 0;
for(int i=0; i<size; i++)
 {
 sum += f(arr[i]);
 }
return sum;
}

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
int t[] = {6,30,12,-81,9,-9,15,6,30,33,21,18, 0};

unsigned n = sizeof(t)/sizeof(int);

int *r = new int[n];

cout << "gcd=" << gcd(n,t,r) << endl;

for (int i = 0; i < n ;i++) {
	cout << r[i] << " ";
}

cout << endl;


		
}


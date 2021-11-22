#include <iostream>

using namespace std;

void allFactorial(long long* factorial, int const N) {
	*(factorial) = 1;
	
	for (int i = 1; i <= N ; i++) {
		*(factorial + i) = i * *(factorial + i - 1);
	}
} 

int main() {
	
	int const N = 10;
	
	// Could be 
	// long long * factorial = new long long[N + 1]
 	long long* factorial = (long long*) malloc ((N + 1) * sizeof(long long));
	
	// Calculate factorial for N first numbers
	allFactorial(factorial, N);
	
	
	
	int** newton = (int**)malloc(N * sizeof(int*));
	
	for (int i = 0; i < N; i++) {
		newton[i] = (int*)malloc((i + 1)  * sizeof(int));
	}
	
	// C(a, b) = a! / ( b! * (a - b)! )
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			newton[i][j] = factorial[i] / (factorial[j] * factorial[i-j]);
		}
	}
	
	for (int i = 0; i < 10; i++) {
		cout << factorial[i] << " ";
	}
	
	cout << '\n';
	for (int i = 0; i < N; i++) {
		cout << "Degree : " << i << " = " ; 
		for (int j = 0; j < i + 1; j++) {
			cout << newton[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}



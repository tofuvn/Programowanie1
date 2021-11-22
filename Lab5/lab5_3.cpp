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
	
	long long* factorial = (long long*) malloc ((N + 1) * sizeof(long long));
	
	allFactorial(factorial, N);
	
	int** newton = (int**)malloc(N * sizeof(int*));
	
	for (int i = 0; i < N; i++) {
		newton[i] = (int*)malloc((N + 1)  * sizeof(int));
	}
	
	for (int i = 0; i <=N; i++) {
		cout << *(factorial + i) << " ";
	}
	
	
	
	return 0;
}



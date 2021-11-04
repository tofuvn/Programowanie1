
#include <iostream>
#include <cmath>
#include <cstring>
#include <stdlib.h> 



using namespace std;

int main() {
	
	int N = 10;
	
	int tab[N];
	
	for (int i = 0; i < N; i++) {
		*(tab + i) = rand() % 20;
	}
	
	for (int i = 0; i < N; i++) {
		cout << *(tab + i) << " ";
	}
	
	cout << endl;
	
	int sum = 0;
	
	for (int i = 0; i < N; i++) {
		sum += *(tab + i);
	}
	
	cout << "Sum : " << sum << endl;
	
	int max = INT8_MIN;
	
	for (int i = 0; i < N; i++) {
		if (*(tab + i) > max) {
			max = *(tab + i);
		} 
	}
	
	cout << "Max: " << max << endl;
	
	return 0;
}


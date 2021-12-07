#include <iostream>

using namespace std;

typedef bool (*bfi)(const int);

bool evenNumber(const int num) {
	if (num % 2 == 0) {
		return true;
	}
	
	return false;
}

void filtr(int t[], int n, bool (*f)(const int)) {
	for (int i = 0 ; i < n; i++) {
		if (f(t[i])) {
			cout << t[i] << " ";
		}
	}
}



int main() {
	
	bfi ptr;
	
	ptr = evenNumber;
	
	int n = 10;
	
	int *tab = (int*) malloc (n * sizeof(int));
	
	for (int i = 0; i < n; i++) {
		*(tab + i) = i + 1;
	}
	
	filtr(tab, n, ptr);
	
	free(tab);
	
	return 0;
}

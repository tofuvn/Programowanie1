#include <iostream>
#include <stdlib.h>  
#include <cmath>
#include <iomanip>


using namespace std;

int main() {
	int *first, *second;
	int first_N = 3, second_N = 2;
	
	std::setw(50);
	
	first = (int*)malloc(first_N * sizeof(int));
	second = (int*)malloc(second_N * sizeof(int));
	
	for (int i = 0; i < first_N; i++) {
		*(first + i) = rand() % 10;
	}
	
	for (int i = 0; i < second_N; i++) {
		*(second + i) = rand() % 10;
	}
	
	int max_coff_sum = max(first_N, second_N);
	int *sum = (int*)malloc(max_coff_sum * sizeof(int));
	
	
	int diff = abs(first_N - second_N);
	
	for (int i = 0; i < max_coff_sum; i++) {
		if (i < diff) {
			if (first_N < second_N) {
				*(sum + i) = *(second + i);
			} else {
				*(sum + i) = *(first + i);
			}	
		} else {
			if (first_N < second_N) {
				*(sum + i) = *(second + i) + *(first + i - diff);
			} else {
				*(sum + i) = *(second + i - diff) + *(first + i);
			}
			
		}
	}
	
	
	int max_coff_multi = first_N + second_N - 1;
	
	int *mul = (int*)malloc(max_coff_multi * sizeof(int));
	
	for (int i = 0; i< max_coff_multi; i++) {
		*(mul + i) = 0;
	}
	
	for (int i = 0; i < first_N; i++) {
		for(int j = 0; j < second_N; j++) {
			mul[i+j] += (*(first + i) * *(second+j)); 
			}
	}
	
	
	
	
	
	

	// Print
	for (int i = 0; i < first_N; i++) {
		
		cout << *(first + i) << " ";
	}
	cout << '\n';
	
	for (int i = 0; i < second_N; i++) {
		cout<< *(second + i) << " ";
	}
	cout << '\n';
	
	for (int i = 0; i < max_coff_sum; i++) {
		cout<< *(sum + i) << " ";
	}
	cout << '\n';
	for (int i = 0; i < max_coff_multi; i++) {
		cout << *(mul + i) << " ";
	}
	
	return 0;
}

#include <iostream>
#include <stdlib.h>  
#include <cmath>


using namespace std;

int main() {
	int *first, *second;
	int sizeOfFirstArray = 3, sizeOfSecondArray = 2;
	
	/////// a. Wielomiany
	
	// Allocate memory for first and second array
	first = (int*)malloc(sizeOfFirstArray * sizeof(int));
	second = (int*)malloc(sizeOfSecondArray * sizeof(int));
	
	
	// Initialize random coefficients for each polynomial
	for (int i = 0; i < sizeOfFirstArray; i++) {
		*(first + i) = rand() % 10;
	}
	
	for (int i = 0; i < sizeOfSecondArray; i++) {
		*(second + i) = rand() % 10;
	}
	
	// Degree of sum 2 polynomial is equal max value degree of 2 polynomial
	int max_coff_sum = max(sizeOfFirstArray, sizeOfSecondArray);
	int *sum = (int*)malloc(max_coff_sum * sizeof(int));
	
	// Different degree of 2 polynomials
	int diff = abs(sizeOfFirstArray - sizeOfSecondArray);
	
	for (int i = 0; i < max_coff_sum; i++) {
		if (i < diff) {
			if (sizeOfFirstArray < sizeOfSecondArray) {
				*(sum + i) = *(second + i);
			} else {
				*(sum + i) = *(first + i);
			}	
		} else {
			if (sizeOfFirstArray < sizeOfSecondArray) {
				*(sum + i) = *(second + i) + *(first + i - diff);
			} else {
				*(sum + i) = *(second + i - diff) + *(first + i);
			}
			
		}
	}
	
	// Degree of multi 2 polynomial is equal value of first degree + second degree - 1

	int max_coff_multi = sizeOfFirstArray + sizeOfSecondArray - 1;
	
	int *mul = (int*)malloc(max_coff_multi * sizeof(int));
	
	for (int i = 0; i< max_coff_multi; i++) {
		*(mul + i) = 0;
	}
	
	for (int i = 0; i < sizeOfFirstArray; i++) {
		for(int j = 0; j < sizeOfSecondArray; j++) {
			mul[i+j] += (*(first + i) * *(second+j)); 
			}
	}
	
	// Display
	cout << "First: ";
	for (int i = 0; i < sizeOfFirstArray; i++) {
		
		cout << *(first + i) << " ";
	}
	cout << '\n';
	
	
	cout << "Second: ";
	for (int i = 0; i < sizeOfSecondArray; i++) {
		cout<< *(second + i) << " ";
	}
	cout << '\n';
	
	cout << "Sum: " ;
	for (int i = 0; i < max_coff_sum; i++) {
		cout<< *(sum + i) << " ";
	}
	cout << '\n';
	
	cout << "Multi : ";
	for (int i = 0; i < max_coff_multi; i++) {
		cout << *(mul + i) << " ";
	}
	cout << '\n';
	
	/////// b.Filtr 
	int sizeOfArray = 10;
	
	// Allocate memory and initialize values
	int* arrayOfRandomValues = (int*) malloc (sizeof(int) * sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		*(arrayOfRandomValues + i) = rand() % 10;
	}
	
	cout << "Array : ";
	for (int i = 0; i < sizeOfArray; i++) {
		cout << *(arrayOfRandomValues + i) << " ";
	}
	cout << '\n';
	
	
	/////// c.Systemy Pozycyjne
	
	int number = 8;
	int size = 5;
	int *arrayInTernary = new int[size];
	
	int divide = number;
	int count = 0;
	do {
		int remainder = divide % 3;
		divide = divide / 3;
		arrayInTernary[count] = remainder;
		count++;
		
	}while (divide > 0);
	
	cout << "Decimal: " << number << endl;
	cout << "Ternany: ";
	for (int i = count - 1; i >= 0; i-- ) {
		cout << arrayInTernary[i] << " ";
	}
	return 0;
}

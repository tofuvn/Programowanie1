// Van The Ho

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>


using namespace std;

void P(int **array2D, int *sizeOfEachRow, int N);
void R(int **&array2D, int  *&sizeOfEachRow, int &N);
void S(int **array2D, int  *sizeOfEachRow, int N);
void D(int **array2D,int  *sizeOfEachRow,int N);
void A(int **&array2D,int  *&sizeOfEachRow,int &N);
void I(int **&array2D,int  *&sizeOfEachRow,int &N);

int main() {
	
	// number of rows in table
	int N;
	cin >> N;
	
	// keep track number of elements on each row
	int *sizeOfEachRow = (int*) malloc (N * sizeof(int));
		
	int **array2D = (int**) malloc (N * sizeof(int*));
	
	// number of element in each row
	int size;
	for (int i = 0; i < N; i++) {
		cin >> size;
		
		*(sizeOfEachRow + i) = size;
		
		*(array2D + i) = (int*) malloc (size * sizeof(int));
		
		for (int j =0; j < size; j++) {
			cin >> *(*(array2D + i) + j);
		}
	}
	
	bool quit = false;
	
	char key;
	
	while (!quit) {
		
		cin >> key;
		
		switch (key){
			case 'P' :
				P(array2D,sizeOfEachRow, N);
				break;
			case 'R':
				R(array2D,sizeOfEachRow, N);
				break;
			case 'S':
				S(array2D,sizeOfEachRow, N);
				break;
			case 'D':
				D(array2D,sizeOfEachRow, N);		
				break;
			case 'A':
				A(array2D,sizeOfEachRow, N);
				break;
			case 'I':
				I(array2D,sizeOfEachRow, N);
				break;
			case 'E' :
				quit = true;
				for (int i = 0; i < N; i++) {
					free(*(array2D + i));
				}
				free(array2D);
				free(sizeOfEachRow);
				break;
		}	
	}

	return 0;
}

void P(int **array2D,int  *sizeOfEachRow,int N) {
	if (N > 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < *(sizeOfEachRow + i); j++) {
				cout << *(*(array2D + i) + j) << " ";
			}
			cout << endl;
			}
		cout << endl;
	}
}

void R(int **&array2D,int  *&sizeOfEachRow,int &N) {
	int n;
	cin >> n;
	if (N > 0) {
		free(*(array2D + n));
		for (int i = n; i < N - 1; i++) {
			*(array2D + i) = *(array2D + i + 1);
			*(sizeOfEachRow + i) = *(sizeOfEachRow + i + 1);
		}
		
		N--;
		sizeOfEachRow = (int*) realloc (sizeOfEachRow, N * sizeof(int));
	}
	
}

void S(int **array2D,int  *sizeOfEachRow,int N) {
	int n, m;
	cin >> n >> m;
	
	if (n != m) {
		int  *tempArray;
	
		tempArray = *(array2D + m);
		*(array2D + m) = *(array2D + n);
		*(array2D + n) = tempArray;
		
		int temp;
		temp = *(sizeOfEachRow + n);
		*(sizeOfEachRow + n ) = *(sizeOfEachRow + m);
		*(sizeOfEachRow + m) = temp;
	}
	
	
}

void D(int **array2D,int  *sizeOfEachRow,int N) {
	
	if (N > 0) {
		int n;
		cin >> n;
		
		int sizeOfIndexRow = *(sizeOfEachRow + n);

		
		*(array2D + n) = (int*) realloc (*(array2D + n), (sizeOfIndexRow) * 2 * sizeof(int));

		
		for (int i = 0; i < sizeOfIndexRow; i++ ){
			*(*(array2D + n)+ i + sizeOfIndexRow) = *(*(array2D + n)+ i);
		}
		
		*(sizeOfEachRow + n) = sizeOfIndexRow * 2;
	}	
}

void A(int **&array2D,int  *&sizeOfEachRow,int &N) {
	
	if (N > 0) {
		int n;
		cin >> n;
			int sizeOfRow = *(sizeOfEachRow + n);

		N++;
			
		array2D = (int**) realloc (array2D, N * sizeof(int*));
		sizeOfEachRow = (int*) realloc (sizeOfEachRow, N * sizeof(int));

		*(array2D + N - 1) = (int*) calloc (sizeOfRow , sizeof(int));
		*(sizeOfEachRow + N - 1) = sizeOfRow;
		

		for (int i = 0; i < sizeOfRow; i++ ){
			*(*(array2D + N - 1)+ i) = *(*(array2D + n)+ i);
		}
	}
		
	
	
}

void I(int **&array2D,int  *&sizeOfEachRow,int &N) {

	if (N > 0) {
		int n, m, k;
		cin >> n >> m >> k;
		
		if (n != m) {
			int sizeOfFirstRow = *(sizeOfEachRow + n);
			int sizeOfSecondRow = *(sizeOfEachRow + m);
				
			*(array2D + m) = (int*) realloc (*(array2D + m), (sizeOfSecondRow + sizeOfFirstRow) * sizeof(int));
			
			for (int i = 0; i < (sizeOfSecondRow - k); i++) {
				*(*(array2D + m) + k + i + sizeOfFirstRow) = *(*(array2D + m) + k + i);
			}
			for (int i = 0; i < sizeOfFirstRow; i++) {
				*(*(array2D + m) + k + i) = *(*(array2D + n) + i);
			
			*(sizeOfEachRow + m) = sizeOfFirstRow  + sizeOfSecondRow;
		}
			free(*(array2D + n));
			
			for (int i = n; i < N - 1; i++) {
				*(array2D + i) = *(array2D + i + 1);
				*(sizeOfEachRow + i) = *(sizeOfEachRow + i + 1);
			}
			N--;
			sizeOfEachRow = (int*) realloc (sizeOfEachRow, N * sizeof(int));
		} else {
			int sizeOfFirstRow = *(sizeOfEachRow + n);
			int sizeOfSecondRow = *(sizeOfEachRow + m);
				
			*(array2D + m) = (int*) realloc (*(array2D + m), (sizeOfSecondRow + sizeOfFirstRow) * sizeof(int));
			
			for (int i = 0; i < (sizeOfSecondRow - k); i++) {
				*(*(array2D + m) + k + i + sizeOfFirstRow) = *(*(array2D + m) + k + i);
			}
			for (int i = 0; i < sizeOfFirstRow; i++) {
				*(*(array2D + m) + sizeOfFirstRow - i) = *(*(array2D + m) + sizeOfFirstRow - i - 1);
				*(sizeOfEachRow + m) = sizeOfFirstRow  + sizeOfSecondRow;
			}

			sizeOfEachRow = (int*) realloc (sizeOfEachRow, N * sizeof(int));
		}
		
	}
}

// Van The Ho

// Free to copy or modify but recommend try your approach first, read paragraph below before moving on to the solution.

// What we learn from this execies:
// 1. Allocate, Reallocate Memory
// 2. De-allocate Memory (Important)
// 3. How to use Valgrind ( I think it's very important, i cannot finish this without Valgrind )
// 4. How to use Reference in C++, remember C++ pass by value , it make code is more easy to write and read.
// 		4.5 "Use references when you can, and pointers when you have to."
// 5. Remember edge case when N = 0;

#include <iostream>
#include <cstdlib>

using namespace std;

void initializeArray(int **&array2D, int*& sizeOfRows, int N);
void P(int **array2D, int *sizeOfRows, int N);
void R(int **&array2D, int  *&sizeOfRows, int &N);
void S(int **array2D, int  *sizeOfRows, int N);
void D(int **array2D,int  *sizeOfRows,int N);
void A(int **&array2D,int  *&sizeOfRows,int &N);
void I(int **&array2D,int  *&sizeOfRows,int &N);
void E(int **array2D, int* sizeOfRows, int N, bool &quit);

int main() {
	
	int N;
	cin >> N;
		
	// array2D - table 2D 
	// sizeOfRows - array 1D use to keep track the number of element on each row in array2D
	// both dynamic
	int **array2D, *sizeOfRows; 
		
	initializeArray(array2D, sizeOfRows, N);
	
	bool quit = false;
	
	char key;
	
	while (!quit) {
		
		cin >> key;
		
		switch (key){
			case 'P' :
				P(array2D,sizeOfRows, N);
				break;
			case 'R':
				R(array2D,sizeOfRows, N);
				break;
			case 'S':
				S(array2D,sizeOfRows, N);
				break;
			case 'D':
				D(array2D,sizeOfRows, N);		
				break;
			case 'A':
				A(array2D,sizeOfRows, N);
				break;
			case 'I':
				I(array2D,sizeOfRows, N);
				break;
			case 'E' :
				E(array2D, sizeOfRows, N, quit);
				break;
			default:
				cout << "Wrong key.. Try again..";
		}	
	}

	return 0;
}
void E(int **array2D, int* sizeOfRows, int N, bool &quit) {
	quit = true;
	for (int i = 0; i < N; i++) {
		free(*(array2D + i));
	}
	free(array2D);
	free(sizeOfRows);
}

void initializeArray(int **&array2D, int*& sizeOfRows, int N) {
	
	sizeOfRows = (int*) malloc (N * sizeof(int));
	array2D = (int**) malloc (N * sizeof(int*));
	
	int size;
	for (int i = 0; i < N; i++) {
		
		cin >> size;
		
		*(sizeOfRows + i) = size;
		
		*(array2D + i) = (int*) malloc (size * sizeof(int));
		
		for (int j =0; j < size; j++) {
			cin >> *(*(array2D + i) + j);
		}
	}
}

// wypisanie aktualnego układu liczb na standardowe wyjście
void P(int **array2D,int  *sizeOfRows,int N) {
	if (N > 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < *(sizeOfRows + i); j++) {
				cout << *(*(array2D + i) + j) << " ";
			}
			cout << endl;
			}
		cout << endl;
	}
}

// Usunięcie wiersza o numerze n
void R(int **&array2D,int  *&sizeOfRows,int &N) {
	
	if (N > 0) {
		int n;
		cin >> n;
		// memory deallocation for row n;
		free(*(array2D + n));
		// each row after n need to be move forward
		// and update size of each row
		for (int i = n; i < N - 1; i++) {
			*(array2D + i) = *(array2D + i + 1);
			*(sizeOfRows + i) = *(sizeOfRows + i + 1);
		}
		
		// decrease number of row after delete and also update table track number of elements
		N--;
		// array2D = (int**) realloc (array2D, N * sizeof(int*));
		sizeOfRows = (int*) realloc (sizeOfRows, N * sizeof(int));
	}
	
}

// zamiana miejscami wierszy o numerach n i m
void S(int **array2D,int  *sizeOfRows,int N) {
	int n, m;
	cin >> n >> m;
	
	if (N > 0) {
		if (n != m) {
		int  *tempArray;
		
		/*
		 * SWAP(int a, int b) {
		 * 		int temp = a;
		 * 		a = b;
		 * 		b = temp;
		 * }
		 * 
		 * The same as (int *a, int *b)
		 * */
	
		tempArray = *(array2D + m);
		*(array2D + m) = *(array2D + n);
		*(array2D + n) = tempArray;
		
		int temp;
		temp = *(sizeOfRows + n);
		*(sizeOfRows + n ) = *(sizeOfRows + m);
		*(sizeOfRows + m) = temp;
		
		}
	}
}

//  podwojenie wiersza o numerze n
void D(int **array2D,int  *sizeOfRows,int N) {
	
	if (N > 0) {
		int n;
		cin >> n;
		
		// get size of row n
		int size = *(sizeOfRows + n);

		// realloc row n to get more memory.
		*(array2D + n) = (int*) realloc (*(array2D + n), size * 2 * sizeof(int));
		
		for (int i = 0; i < size; i++ ){
			*(*(array2D + n)+ i + size) = *(*(array2D + n)+ i);
		}
		
		// update the number of element in row n
		*(sizeOfRows + n) = size * 2;
	}	
}


// dodanie na końcu tablicy nowego wiersza będącego kopią wiersza o numerze n
void A(int **&array2D,int  *&sizeOfRows,int &N) {
	
	if (N > 0) {
		int n;
		cin >> n;
		
		int sizeOfRow = *(sizeOfRows + n);

		// increase the number of array and allocate momory for new row
		N++;
			
		array2D = (int**) realloc (array2D, N * sizeof(int*));
		sizeOfRows = (int*) realloc (sizeOfRows, N * sizeof(int));

		*(array2D + N - 1) = (int*) calloc (sizeOfRow , sizeof(int));
		*(sizeOfRows + N - 1) = sizeOfRow;
		
		// fill last row
		for (int i = 0; i < sizeOfRow; i++ ){
			*(*(array2D + N - 1)+ i) = *(*(array2D + n)+ i);
		}
	}	
	
}


// wstawienie wiersza o numerze n do wiersza o numerze m na pozycję k
void I(int **&array2D,int  *&sizeOfRows,int &N) {

	if (N > 0) {
		int n, m, k;
		cin >> n >> m >> k;
		
		if (n != m) {
			int sizeOfFirstRow = *(sizeOfRows + n);
			int sizeOfSecondRow = *(sizeOfRows + m);
			int sizeOfNewRow = sizeOfFirstRow + sizeOfSecondRow;
			
			// re-allocate memory for row m ( because it getting bigger )
			*(array2D + m) = (int*) realloc (*(array2D + m), sizeOfNewRow * sizeof(int));
			
			// move element in row M to right in order to make place for row N
			for (int i = 0; i < sizeOfSecondRow - k; i++) {
				*(*(array2D + m) + sizeOfNewRow - i - 1) =*(*(array2D + m) + sizeOfSecondRow - i - 1 );
			}
			
			// fill places in row M with element in row N
			for (int i = 0; i < sizeOfFirstRow; i++) {
				*(*(array2D + m) + k + i) = *(*(array2D + n) + i);
			}
			
			// update size of row M
			*(sizeOfRows + m) = sizeOfNewRow;
		
			// deallocate for row N ( we dont need anymore)
			free(*(array2D + n));
			
			// the same as delete row N
			for (int i = n; i < N - 1; i++) {
				*(array2D + i) = *(array2D + i + 1);
				*(sizeOfRows + i) = *(sizeOfRows + i + 1);
			}
			N--;
			sizeOfRows = (int*) realloc (sizeOfRows, N * sizeof(int));

		}
		// in stuation when n = m , but i think we dont need now
		/* else {
			int sizeOfFirstRow = *(sizeOfRows + n);
			int sizeOfSecondRow = *(sizeOfRows + m);
				
			*(array2D + m) = (int*) realloc (*(array2D + m), (sizeOfSecondRow + sizeOfFirstRow) * sizeof(int));
			
			for (int i = 0; i < (sizeOfSecondRow - k); i++) {
				*(*(array2D + m) + k + i + sizeOfFirstRow) = *(*(array2D + m) + k + i);
			}
			for (int i = 0; i < sizeOfFirstRow; i++) {
				*(*(array2D + m) + sizeOfFirstRow - i) = *(*(array2D + m) + sizeOfFirstRow - i - 1);
				*(sizeOfRows + m) = sizeOfFirstRow  + sizeOfSecondRow;
			}

			sizeOfRows = (int*) realloc (sizeOfRows, N * sizeof(int));
		}*/
		
	}
	
}

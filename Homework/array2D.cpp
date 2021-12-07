// Van The Ho
// thehovnpl@gmail.com

// Free to copy or modify but recommend try your approach first, before moving on to the solution.
// I would greatly appreciate it if you kindly give me some feedback 
// Self Documenting Code

/* Run a C++ program on terminal using gcc compiler 

0. Prepare input file : vi input.txt ( with pwd of file cpp) with this format
	N 	(size = 3)
	5  	(row 0 have 5 els)
	1 2 3 4 5
	3	(row 1 have 3 els)
	6 7 8
	2 	(row 2 have 2 els)
	9 10
	1 1 2 2 (col_min, col_max, row_min, row_max)
	

1. Compile the program using any of the following command:
		g++ array2D.cpp -o array2D
		
2. Run this program with input file type this command:
		./array < in.txt > out.txt

3. See result:
		cat out.txt

4. Check memory leak with Valgrind
		valgrind --leak-check=full ./array2D < in.txt > out.txt (after compile)

*/
 
#include <iostream>

using namespace std;

void initializeArray(int **&array2D, int*& sizeOfRows, int N);
void deallocateArray(int **array2D, int* sizeOfRows, int N);
void printArray(int **array2D, int* sizeOfRows, int N);
void removeFractionOfArray(int **&array2D, int*& sizeOfRows, int &N);


int main() {
	int N;
	cin >> N;
		
	// array2D - table 2D 
	// sizeOfRows - array 1D use to keep track the number of element on each row in array2D
	// both dynamic
	int **array2D, *sizeOfRows; 
		
	initializeArray(array2D, sizeOfRows, N);
	
	printArray(array2D, sizeOfRows, N);
	
	removeFractionOfArray(array2D, sizeOfRows, N);
	
	cout << "Array after excution : " << endl;
	
	printArray(array2D, sizeOfRows, N);
	
	deallocateArray(array2D, sizeOfRows, N);
	
	return 0;
}

void removeFractionOfArray(int **&array2D, int*& sizeOfRows, int &N) {
	int col_min, col_max, row_min, row_max;
	
	cin >> row_min >> col_min >> row_max >> col_max;
	
	// some specific cases
	if (row_max > N - 1) {
		row_max = N - 1;
	}
	if (row_min < 0) {
		row_min = 0;
	}
	if (col_min < 0) {
		col_min = 0;
	}
	
	if (col_min > 0) {
		
		
		
		/* 						Row:
		 * 	0 1 2 3             1
		 *     -----
		 *  0 1|2 3|4			2
		 *  0 1|2 3|4 5			3
		 * 	0 1|2  | 			4
		 *  0  |   |			5
		 *     -----
		 *  0 1 2 3 4 5			6
		 * */
		 
		for (int i = row_min; i <= row_max; ++i) {
				/* 
				 This case we does need to any delete row  
				 
				 2 smaller cases :
					 1. when the number element of row we are working with smaller than the minimum column ( for example Row 5 above) ,we dont have to do anything
					 2. other case , we have to do something
						2.1  the number element of row smaller than or equal the max column ( Row 4), we reallocate the row with the number of element equal the min row
							and change the number of element of row in another table
						2.2  the number element of row larger than the max column ( Row 2,3)
							move all element from element with index col_max to the right to head of array, reallocate and change the number element of row
				*/
				int sizeOfCurrentRow = *(sizeOfRows + i);
				
				if (sizeOfCurrentRow > col_min) {
					if (sizeOfCurrentRow < col_max) {
						*(array2D + i) = (int*) realloc (*(array2D + i), sizeof(int) * col_min);
						*(sizeOfRows + i) = col_min;
					} else {
						for (int j = 0; j < sizeOfCurrentRow - col_max -1; ++j) {
							*(*(array2D + i) + col_min + j) = *(*(array2D + i)  + col_max + 1 + j);
						}
						int newSizeOfRow = sizeOfCurrentRow - col_max + col_min - 1;
						*(array2D + i) = (int*) realloc (*(array2D + i), sizeof(int) * newSizeOfRow);
						*(sizeOfRows + i) = newSizeOfRow;
					}
				}
				
		}
	} else {
		
		
		
		/*					Row:
		 * 	 0 1 2 3        0
		 *   -------		
		 *  |0 1 2 3|4		1
		 *  |0 1 2 3|4 5	2
		 * 	|0 1 2  | 		3
		 *  |0      |		4
		 *   -------
		 *   0 1 2 3 4 5	5
		 * */
		
		bool quit = false;
		
		int i = row_min;
		
		// we check every row within fraction until we have checked last row
		while (!quit) {
			if (i > row_max) {
				quit = true;
			} else {
				
				int sizeOfCurrentRow = *(sizeOfRows + i);
				/*
				 This case we COULD delete rows  
				  
				 2 smaller cases :
					1. when the number element of row we are working with smaller or equal than the max column + 1 ( Row 3, 4)
						remove complete row , deallocate, move all row after that row forward , decrease the number of rows of array (N) alse decrease 1 row_max
					2. other case we move all element from element with index col_max to the right to head of array, reallocate and change the number element of row
						and check another row
				*/
		
				if (sizeOfCurrentRow <= (col_max + 1)) {
					free(*(array2D + i));
					
					for (int j = i; j < N - 1; ++j) {
						*(array2D + j) = *(array2D + j + 1);
						*(sizeOfRows + j) = *(sizeOfRows + j + 1);
					}
					
					N--;
					array2D = (int**) realloc (array2D, sizeof(int*) * N);
					sizeOfRows = (int *) realloc(sizeOfRows, N * sizeof(int));
					row_max--;

				} else {
					for (int j = 0 ; j < sizeOfCurrentRow - col_max - 1; ++j) {
						*(*(array2D + i) + j) = *(*(array2D + i) + j + col_max + 1);
					}
					int newSizeOfRow = sizeOfCurrentRow - col_max - 1;
					*(array2D + i) = (int*) realloc (*(array2D + i), sizeof(int) * newSizeOfRow);
					*(sizeOfRows + i )= newSizeOfRow;
					++i;
				}
			}
		}
		
	}
	
}

void printArray(int **array2D, int* sizeOfRows, int N) {
	if (N == 0) {
		cout << "Array was removed completely !" << endl;
		return;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < *(sizeOfRows + i); ++j) {
			cout << *(*(array2D + i) + j) << " ";
		}
		cout << endl;
	}
}

void initializeArray(int **&array2D, int*& sizeOfRows, int N) {
	
	sizeOfRows = (int*) malloc (N * sizeof(int));
	array2D = (int**) malloc (N * sizeof(int*));
	
	int size;
	for (int i = 0; i < N; ++i) {
		
		cin >> size;
		
		*(sizeOfRows + i) = size;
		
		*(array2D + i) = (int*) malloc (size * sizeof(int));
		
		for (int j =0; j < size; ++j) {
			cin >> *(*(array2D + i) + j);
		}
	}
}

void deallocateArray(int **array2D, int* sizeOfRows, int N) {
	for (int i = 0; i < N; ++i) {
		free(*(array2D + i));
	}
	free(array2D);
	free(sizeOfRows);
}

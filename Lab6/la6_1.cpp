#include <iostream>

using namespace std;

int main() {
	
	/*int n = 10;
	int *ptr = (int*)malloc(n * sizeof(int));
	
	int *ptr2 = (int*)calloc(n ,sizeof(int));
	
	ptr2 = (int*)realloc(ptr2, (n - 7) * sizeof(int));
	
	ptr[2] = 10;
	
	free(ptr);
	free(ptr2);*/
	
	int n = 10;
	
	int imin = 1;
	int jmin = 1;
	
	int imax = 3;
	int jmax = 3;
	
	
	int *randomValues = (int*) malloc (n * sizeof(int));
	
	
	for (int i = 0; i < n; i++) {
		*(randomValues + i) = rand() % 9 + 1;
	}
	
	for (int i = 0; i < n; i++) {
		cout << *(randomValues + i) << " ";
	}
	cout << endl << endl;
	
	//randomValues = (int*) realloc (randomValues, 5 * sizeof(int));
	int* ptr = randomValues;
	while(ptr != NULL) {
		cout << *(ptr);
		ptr += 1;
	}
		
	int **array2D = (int**) malloc (n * sizeof(int*));
	for (int i = 0; i < n ;i++) {
		array2D[i] = (int*) malloc (*(randomValues + i) * sizeof(int));
	}
	
	
	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < *(randomValues + i); j++) {
			array2D[i][j] = rand() % 9 + 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < *(randomValues + i); j++) {
			cout << array2D[i][j] << " ";
		}
		cout << endl;
	}
	
	
	int diff = jmax - jmin;
	for (int i = imin; i < imax; i++) {
		if (imin > 0) {
			if (jmax < *(randomValues + imin) - 1) {
				for (int k = jmax + 1; k < *(randomValues + imin); k++) {
					array2D[i][k] = array2D[i][k - diff -1];
				}
			} else {
				array2D[i] = (int*) realloc (array2D, imin * sizeof(int));
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	for (int i = 0; i < n; i++) {
		cout << *(randomValues + i) << " ";
	}
	cout << endl << endl;
	
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < *(randomValues + i); j++) {
			if (i >= imin and i <= imax ) {
				if (jmax)
			}
		}
		cout << endl;
	}*/
	
	
	free(randomValues);
	for (int i = 0; i < n; i++) {
		free(array2D[i]);
	}
	free(array2D);
	
	return 0;
}

#include <iostream>


using namespace std;

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

bool rosnaco(int a, int b) {
	return a > b;
}

bool malejaco(int a, int b) {
	return a < b;
}

void bubbleSort(int arr[], int n, bool (*f)(int , int) = rosnaco){
    int i, j;
    for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			
				if (f(arr[j], arr[j+1])) {
					swap(&arr[j], &arr[j+1]);
				}			
				
		}			
	}   		
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}



int main() {
	
	int n = 10;
	
	int *tab = (int*) malloc (n * sizeof(int));
	
	for (int i = 0; i < n; i++) {
		*(tab + i) = i + 1;
	}
	
	bubbleSort(tab,n, rosnaco);
	printArray(tab, n);
	
	bubbleSort(tab,n, malejaco);
	printArray(tab, n);
	
	bubbleSort(tab,n);
	printArray(tab, n);
	
	free(tab);
	
	return 0;
}

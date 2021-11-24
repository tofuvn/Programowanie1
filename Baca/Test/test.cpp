#include <iostream>
#include <cmath>

using namespace std;

void reallocMemory(int **test) {
	test = (int**) realloc (test ,5 * sizeof(int*));
	*(test+ 4) = (int*) calloc(2, sizeof(int));
	*(*(test+ 4) + 1) = 2;
	//*(test + 10) = 5;
}

int main() {
	
	int N  = 4;
	
	int **test = (int**) malloc (N * sizeof(int*));
	
	reallocMemory(test);
	
	for (int i = 0;i < N; i++) {
		*(test+i) = (int*) calloc(2,sizeof(int));
	}
	
	reallocMemory(test);

	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++)
		cout << *((*(test + i)) + j)<< " " ; 
	}
	
	return 0;
}

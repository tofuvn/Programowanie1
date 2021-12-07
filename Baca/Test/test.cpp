#include <iostream>
#include <cmath>

using namespace std;

/*void reallocMemory(int **test) {
	test = (int**) realloc (test ,5 * sizeof(int*));
}*/

int main() {
	
	int N  = 4;
	int M = 3;
	
	int **test = (int**) malloc (N * sizeof(int*));
	
	//reallocMemory(test);
	
	for (int i = 0;i < N; i++) {
		*(test+i) = (int*) calloc(M,sizeof(int));
	}
	
	//reallocMemory(test);

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		cout << *((*(test + i)) + j)<< " " ; 
	}
	
	
	N = 5;
	test = (int**) realloc (test ,N * sizeof(int*));
	
	*(test + 4) = (int*) malloc (M  * sizeof(int));

	for (int i = 0;i < N; i++) {
		*(test+i) = (int*) realloc( *(test+i) ,M * sizeof(int));
	}
	
	
	
	
	for (int i = 0; i < N; i++ ){
		free(*(test + i));
	}
	free(test);
	cout << "11" << endl;
	return 0;
}

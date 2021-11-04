#include <cstdlib>
#include <iostream>
#include <math.h>
#include <iomanip>



using namespace std;

int main(){
	
	int N = 8;
	
	int tab[N][N];
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			tab[i][j] = pow(i + 1, j);
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(7) << tab[i][j] << " ";
		}
		
		cout << endl;
	}
	
	
	int  temp;
	for (int i = 1 ; i < N ; i++) 
		for (int j = 0; j < i; j++){
			temp = tab[i][j];
			tab[i][j] = tab[j][i];
			tab[j][i] = temp;
		}
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(7) << tab[i][j] << " ";
		}
		
		cout << endl;
	}
	return 0;
}

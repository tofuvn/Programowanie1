#include <cstdlib>
#include <iostream>
#include <algorithm>



using namespace std;

int main() {
	srand(time(NULL));
	
	int N = 10;
	
	int tab_liczby[N];
	
	for (int i = 0; i < N; i++) {
		tab_liczby[i] = rand() % 100;
	}
	
	for (int i = 0; i < N; i++) {
		cout << tab_liczby[i] << " ";
	}
	cout << endl;
	
	// Odwracanie
	int temp;
	for (int i = 0 ; i < int (N/ 2); i++) {
		temp = tab_liczby[i];
		tab_liczby[i] =  tab_liczby[N - 1 - i];
		tab_liczby[N - 1 - i ] = temp;
	}
	
	for (int i = 0; i < N; i++) {
		cout << tab_liczby[i] << " ";
	}	
	cout << endl;
	
	// Przesuniecie
	
	
	int last = tab_liczby[N - 1];
	for (int i = N - 1 ; i > 0; i-- ) {
		tab_liczby[i] = tab_liczby[i-1]	;
	}
	tab_liczby[0] = last;
	
	for (int i = 0; i < N; i++) {
		cout << tab_liczby[i] << " ";
	}	
	cout << endl;
	 
	// Sortowanie
	
	for (int i = 0; i < N - 1; i++) 
		for (int j = i + 1; j < N; j++ ) {
			if (tab_liczby[j] < tab_liczby[i]) {
				swap(tab_liczby[i], tab_liczby[j]);
			}
		}
	
	
	for (int i = 0; i < N; i++) {
		cout << tab_liczby[i] << " ";
	}	
	cout << endl;
	return 0;
}

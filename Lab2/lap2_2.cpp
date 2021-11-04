#include <iostream>

using namespace std;

int main() {
    int x, y;
	
	cout << "Podaj x, y :  " << endl;
	cin >> x >> y;
	/*
	 * Dzielimy z reszta liczba a przez liczbe b
	 * 		- jesli reszta jest rowna 0 , to NWD(a,b) = b
	 *		- jesli reszta jest rozna od 0, to przepisujemy liczba a wartosc liczby b , liczby b wartosc otrzymanej reszty, a nastepnie wykonujemy ponownie od poczatku	
	 */
	 
	 
	while ( x % y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	
	cout << "Najwiekszy wspolny dzielnik : " << y; 

	return 0;
}

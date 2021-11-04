
#include <iostream>
#include <cmath>


using namespace std;

int main() {
	int a, b, c;
	cout << "Podaj a, b, c : " << endl;
	cin >> a >> b >> c;
	
	int delta, x1, x2;
	delta = b * b - 4 * a * c;
	
	if ( delta < 0 ) { 
		cout << "Nie ma rozwiazanie. ";
	} else {
		x1 = (-b - sqrt(delta)) / ( 2 * a );
		x2 = (-b + sqrt(delta)) / ( 2 * a );
		cout << "Funkcja ax^2 + bx + c ma pierwiastek." << endl;
		cout << "x1 = " << x1 << endl;  
		cout << "x2 = " << x2 << endl;  
	}
	

	return 0;
}

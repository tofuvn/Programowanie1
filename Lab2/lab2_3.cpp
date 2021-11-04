#include <iostream>

using namespace std;

int main() {
	float a;
	
	float x_2 = 10;
	float x_3 = 10;
	
	cout << "Podaj a : " << endl;
	cin >> a;
	
	for (int i = 0 ; i < 10; i++) {
		x_2 = (x_2 + a / x_2) / 2;
		x_3 = (2 * x_3 + a / (x_3 * x_3)) / 3;
		
	}
	
	
	cout << "Pierwiastek kwadratowy : " << x_2 << endl;
	cout << "Szescienny : " << x_3 << endl;
	
	
	return 0;
}

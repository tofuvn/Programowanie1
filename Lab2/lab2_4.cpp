#include <iostream>
#include <cmath>


using namespace std;

int main() {
	
	int a;
	
	cout << "Podaj a = " << endl;
	cin >> a;
	int count = 0;
	if (a % 2 != 0) {
		cout << "a nie jest liczba parzysta !!!!!!" << endl;
	} else {
		
		for (int i = 2; i <= a / 2; i++ ) {
			
			int x = i;
			
			bool is_X_prime = true;
			if (x > 2) {
				for (int j = 2; j < sqrt(x); j++) {
				if (x % j == 0 ) {
					is_X_prime = false;
					break;
				}
				}
			}
			
			if (is_X_prime) {
				int y = a - x;
				bool is_Y_prime = true;
				
				if (y < 2) is_Y_prime = false;
				
				if (y > 2) {
					for (int k = 2; k < sqrt(y) ; k++) {
					if (y % k == 0) {
						is_Y_prime = false;
						break;
					}
				}
				}
				
				if (is_Y_prime) {
					cout << "X = " << x << " i Y = " << y << endl;
					count++;
				}
			}
		}
		
		cout << "The number of pair = " << count;
	}
	
	return 0;
}


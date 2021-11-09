// Van The Ho

#include <iostream>
#include <cmath>


using namespace std;

int main() {
	
	int n, m;
	cin >> n;
	
	for (int i = 0; i < n ;i++) {
		cin >> m;
		
		bool isPrime = true;
		
		if ( m == 2 || m == 3) {
			cout << "Tak";
		} else {
			for (int j = 2; j < sqrt(m); j++) {
			if (m % j == 0) {
				cout << "Nie" <<  endl;
				isPrime = false;
				break;
			}
		}
		
		if (isPrime) cout << "Tak" << endl;
		}
		
	}
	
	return 0;
}

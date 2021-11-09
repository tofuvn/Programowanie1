// Van The Ho

#include <iostream>

using namespace std;

int main() {
	
	int n, m;
	cin >> n;
	bool isPrime;
	
	for (int i = 0; i < n ;i++) {
		cin >> m;
	
		isPrime = true;
		if ( m == 1) 
			isPrime = false;
		else if ( m > 2) {
			for (int j = 2; j <= m / 2; j++) {
				if (m % j == 0) {
					isPrime = false;
					break;
				}
			}
		}
		
		if (isPrime) 
			cout << "TAK" << endl;
		else 
			cout << "NIE" << endl;
		
	}
	
	return 0;
}

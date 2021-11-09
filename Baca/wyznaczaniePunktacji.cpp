// Van The Ho

#include <iostream>


using namespace std;

int main() {
	
	int n;
	
	cin >> n;
	
	int L, m1, m2, m3, m4, m5, m6;
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> L >> m1 >> m2 >> m3 >> m4 >> m5 >> m6;
		
		sum = m1 + m2 + m3 + m4 + m5 + m6;
		
		float sredni = sum / 6.0;
		
		if (0 <= sredni && sredni <= 50) {
			cout << L << ": " << "ndst" << endl;  
		} else if (sredni > 50 && sredni <= 60) {
			cout << L << ": " << "dst" << endl;  
		} else if (sredni > 60 && sredni <= 70) {
			cout << L << ": " << "dst+" << endl;  
		} else if (sredni > 70 && sredni <= 80) {
			cout << L << ": " << "db" << endl;  
		} else if (sredni > 80 && sredni <= 90) {
			cout << L << ": " << "db+" << endl;  
		} else if (sredni > 90 && sredni <= 100) {
			cout << L << ": " << "bdb" << endl;  
		}
		
	}
}


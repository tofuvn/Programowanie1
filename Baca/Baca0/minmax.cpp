// Van The Ho

#include <iostream>


using namespace std;

int main() {
	
	int n;
	int a,b,c;
	
	int min, max;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		
		if ( a < b ) {
			min = a;
			max = b;
		} else {
			max = a;
			min = b;
		}
		
		if (max < c) {
			max = c;
		}
		if (min > c) {
			min = c;
		}
		
		cout << min << " " << max << endl;
	}
}


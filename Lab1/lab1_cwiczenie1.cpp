#include <iostream>
#include <cmath>


using namespace std;

int main() {
	int a,b,c,d,R1,R2;
	
	cout << "Podac a, b: " << endl;
	cin >> a >> b;
	cout << "Podac R1 :" << endl;
	cin >> R1;
	
	cout << "Podac c, d: " << endl;
	cin >> c >> d;
	cout << "Podac R2 :" << endl;
	cin >> R2;
	
	float distance = sqrt(pow(a - c, 2) + pow(b - d, 2));
	
	if (distance > (R1 + R2)) {
		cout << " Nie ma przeciete ";
	} else if (distance == (R1 + R2)) {
		cout << " 1 przeciete ";
	} else {
		cout << " 2 przeciete";
	}
	return 0;
}

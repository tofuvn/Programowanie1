// Van The Ho

#include <iostream>

using namespace std;

int main() {
	
	int n, m, a;
	
	cin >> n >> m;
	
	bool flag = false;
	
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (n % a == 0) {
			cout << "Tak";
		} else continue;
	}
	
	if (!flag) {
		cout << "Nie";
	}
	
	return 0;
}


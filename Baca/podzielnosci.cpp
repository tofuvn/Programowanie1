// Van The Ho

#include <iostream>

using namespace std;

int main() {
	
	int n, m, a;
	
	cin >> n >> m;
	
	bool isExist = false;
	
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (n % a == 0) {
			isExist = true;
			break;
		}
	}
	
	if (isExist) cout << "TAK"; else cout << "NIE";

}


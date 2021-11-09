// Van The Ho

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	
	int n;
	char tab[100];
	cin >> n;
	cin.getline(tab, sizeof(tab));
	for (int i = 0; i < n ;i++) {
		
		cin.getline(tab, sizeof(tab));
		char temp;
		int len = strlen(tab);
		for (int j = 0; j < len / 2; j++) {
			temp = tab[j];
			tab[j] =  tab[len-1-j];
			tab[len-1-j] = temp;
		}
		cout << tab;
	}
}


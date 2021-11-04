#include <iostream>

using namespace std;

int main(){
	char tab_znakowa[] = "       To jest dlugi sms.    Chcialbym go skrocic! Powiesz mi jak    ?      ";
	
	int length = strlen(tab_znakowa);
	
	cout << "Dlugosc przed zmieniem: " << length << endl;
	
	
	for (int i = 0; i <= length - 1; i++) {
		if (tab_znakowa[i] == ' ') {
			cout << "Postion : " << i << endl;
			int j = i + 1;
			int count = 1;
			while (tab_znakowa[j] == ' ' && j <= length - 1) {
				j++;
				count++;
			}
			
			
			for (int k = i; k <= length - count; k++) {
				tab_znakowa[k] = tab_znakowa[k + count];
			}
					
			length -= count;
			tab_znakowa[length] = '\0';
			if (tab_znakowa[i] >=97 && tab_znakowa[i] <= 122) tab_znakowa[i] -= 32;
			cout << tab_znakowa << endl;
			cout << "Length = " << length << endl;
			cout << "=====================" << endl;
		}
	}
	
	cout << length << endl;
	
	
	cout << tab_znakowa << endl;
	
	cout << "Dlugosc po zmieniu: " << strlen(tab_znakowa) << endl;

	return 0;
}


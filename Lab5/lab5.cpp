#include <iostream>

using namespace std;

int main() {
	
	int st1, st2;
	
	cout << "Podaj st1 i st2 : " << endl;
	
	cin << st1, st2;
	
	int *w1 = new int[st1+1];
	int *w2 = new int[st2+1];
	
	for (int i = 0; i < st1 + 1; i++ ){
		w1[i] = rand() % 10 + 5;
	} 
	for (int i = 0; i < st2 + 1; i++ ){
		w2[i] = rand() % 10 + 5;
	}
	
	int *w_suma = new int[(st1 > st2 ? st1 + 1 : st2 + 1)];
	int *w_iloczyn = new int[st1+st2+1];
	
	
	
	delete []w1;
	delete []w2;
	delete []w_suma;
	delete []w_iloczyn;
	
	return 0;
}

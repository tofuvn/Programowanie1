// Lab 01. 05-10-2021

/*
 * This
 * is 
 * a 
 * comment
 */
 
 /*
  * int, long int, float, double, char, bool
  * 
  */
#include <iostream>

using namespace std;
 

int main(){
	cout << "Hello world" << endl;
	
	int var_a = 2;
	int var_b = 5;
	
	cout << "Variable a = " << var_a << endl;
	cout << "Variable b = " << var_b << endl;
	
	cout << "Enter new value of b = " << endl;
	cin >> var_b;
	
	cout << "New value of b = " << var_b << endl;
	
	cout << "8 module 3 = " << 8%3 << endl;
	
	// "and", "&&" are the same
	// "||" , "or" 
	// "!" , "not"
	// "^" xor 
	
	
	// If else condition
	if (var_b < 10) {
		cout << "Variable b < 10";
	} else {
		cout << "Variable b >= 10";
	}
	
	
	// While loop
	while (var_b < 10) {
		var_b = var_b + 1;
	}
	
	// For loop
	for(int i= 0; i < 10; i++) {
		cout << "i = " << i << endl;
	}
	
	

	return 0;
}

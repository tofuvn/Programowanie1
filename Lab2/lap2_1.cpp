#include <iostream>
#include <cmath>


using namespace std;

int main(){
	float z1 = 1, z2 = 0, a = 20, b = 0.5, h = 0.01;
	float nowy_z1 = 0, nowy_z2 = 0;
	
	for (int i = 0; i < 100; i++){
		cout << i + 1 << " punkt  = (" << z1 << ", " << z2 << ")" << endl;
		
		nowy_z1 = z1 + h * z2;
		nowy_z2 = z2 - h * (z2 * b + a * sin(z1)); 
		
		z1 = nowy_z1;
		z2 = nowy_z2; 
	}
		
	return 0;
}


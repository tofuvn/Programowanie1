#include <iostream>
#include <stdarg.h>

using namespace std;

double averageArray(int num, ...) {
	va_list arguments;
	double sum = 0;
	
	va_start(arguments, num );
	for (int x = 0; x < num; x++ )        
    {
        sum += va_arg ( arguments, int ); 
    }
    va_end ( arguments );
 
    return sum / num;  
	
};

int main() {
	
	cout << averageArray(4,1,2,3,4);
	
	return 0;
}

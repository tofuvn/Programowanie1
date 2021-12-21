#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	FILE *file;
	
	if ((file = fopen("cena.txt", "r+t")) == nullptr) {
		printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
	};
	
	float price = 0;
	float total = 0;
	
	
	while (fscanf(file, "%*s %f", &price) == 1) {
		total += price;
	}


	printf("Total price: %0.2f\n", total);
	
	fclose(file);
}

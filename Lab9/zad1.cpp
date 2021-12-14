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
	
	char name[30];
	float price = 0;
	float total = 0;
	
	for (int i = 0; i < 3; i++) {
		fscanf(file, "%s%f", name, &price);
		printf("Price %s %f \n",name, price);
		total += price;
	}

	fprintf(file, "\nTotal price: %f\n", total);
	
	fclose(file);
}

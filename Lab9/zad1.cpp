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
	char name[30];
	
	int c;
	
	while ((c = fgetc(file)) != EOF){
		fscanf(file, "%s%f ", name,  &price);
		//printf("Price %f \n", price);
		total += price;
	}

	printf( "Total price: %f\n", total);
	
	fclose(file);
}

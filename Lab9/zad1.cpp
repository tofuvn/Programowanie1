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
	
<<<<<<< HEAD
	while ((c = fgetc(file)) != EOF){
		fscanf(file, "%s%f ", name,  &price);
		//printf("Price %f \n", price);
		total += price;
	}

	printf( "Total price: %f\n", total);
=======
	
	while (fscanf(file, "%*s %f", &price) == 1) {
		total += price;
	}


	printf("Total price: %0.2f\n", total);
>>>>>>> c618986c4ada96988ee11a7d32c18e1b40122fd7
	
	fclose(file);
}

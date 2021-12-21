#include <iostream>
#include <cstdio>

using namespace std;

void printTotal(FILE *file);

void addToCart(FILE *file) ;

int main() {
	FILE *file = nullptr;
	
	printTotal(file);
	
	addToCart(file);
	
	fclose(file);
}

void printTotal(FILE *file) {
	if ((file = fopen("cena.txt", "r")) == nullptr) {
		printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
	};
	
	float price = 0;
	float total = 0;
	
	
	while (fscanf(file, "%*[^:]: %f", &price) == 1) {
		total += price;
	}


	printf("Total price: %0.2f\n", total);
}

void addToCart(FILE *file) {
	if ((file = fopen("cena.txt", "a")) == nullptr) {
		printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
	};
	
	char *s = new char[30];
	float price = 0;
	printf("Enter line: ");
	scanf("%[^:]: %f", s, &price);
	fprintf(file, "%s: %.2f\n", s, price);
}



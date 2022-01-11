#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	
	FILE *file = nullptr;
	
	if ((file = fopen("text.txt", "r+")) == nullptr) {
		printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
	};
	
	int numberOfLines = 0;
	
	char *s = new char[100];	
	while (fscanf(file, "%[^\n]\n", s) == 1) {
		++numberOfLines;
	}
	
	fseek(file, 0, SEEK_SET);
	
	int numberOfWords = 0;
	
	
	int minWord = 100;
	int maxWord = 0;
	
	int sumLength = 0;
	
	
	while (fscanf(file, "%s ", s) == 1) {
		++numberOfWords;
		sumLength += strlen(s);
		if (minWord > strlen(s)) minWord = strlen(s);
		if (maxWord < strlen(s)) maxWord = strlen(s);
		
	}
	
	cout << "Number of Linen : " << numberOfLines << endl;
	cout << "Number of Words : " << numberOfWords << endl;
	cout << "Longest word: " << maxWord << endl;
	cout << "Shortest word: " << minWord << endl;
	cout << "Average word: " << sumLength * 1.0 / numberOfWords << endl;
	
	return 0;
}

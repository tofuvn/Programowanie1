#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

int main(int argc, char *argv[]) {
	
	int bitmapCode;
	char *source = new char[30];
	char *dest = new char[30];
	
	for (int i =  1; i < argc; ++i) {
		if (strcmp(argv[i],"-v")==0) {
			printf("Version : %s , Author : %s \n", "1.1", "The Ho");
		} else if (strcmp(argv[i],"-c")==0) {
			bitmapCode = atoi(argv[i + 1]);
		} else if (strcmp(argv[i],"-f")==0) {
			source = argv[i + 1];
			printf("Source : %s \n", source);
		} else if (strcmp(argv[i],"-o")==0) {
			dest = argv[i + 1];
			printf("Dest : %s \n", dest);
		} else if (strcmp(argv[i],"-k")==0) {
			frameRate = argv[i + 1];
		}
		
	}
	
	ifstream plik;
	
	
	plik.open(source, ios::binary);
	
	if (!plik.is_open()) {
		printf("Unable to open file %s \n", source);
		return 0;
	}
	
	char *header = new char[1078];
	char *body = new char[10000];
	
	plik.read(header, 1078);
	plik.read(body, 10000);
	plik.close();
	
	ofstream plik_do_zapisu;
	
	plik_do_zapisu.open(dest, ios::binary);
	
	plik_do_zapisu.write(header, 1078);
	
	
	for (int i = 0; i < 10000; ++i ){
		body[i] = bitmapCode;
	}
	
	plik_do_zapisu.write(body, 10000);
	plik_do_zapisu.close();
	
	return 0;
}

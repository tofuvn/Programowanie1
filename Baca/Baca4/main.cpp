#include <iostream>
#include <cstdarg>
#include "source_TheHo.cpp"

using namespace std;

char zmienNaWielkaLitere(char c) {
    return (c >= 'a' and c <= 'z') ? c - 32 : c;
}

bool zostawMalaLitere(char c) {
    return (c < 'a' or c > 'z');
}

int main() {
    char s[] = "oo";
    filtruj(s,"o");
    printf("%s\n",s);
    return 0;
}

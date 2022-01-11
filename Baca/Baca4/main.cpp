#include <iostream>
#include <cstdarg>
#include "source.cpp"

using namespace std;

char zmienNaWielkaLitere(char c) {
    return (c >= 'a' and c <= 'z') ? c - 32 : c;
}

bool zostawMalaLitere(char c) {
    return (c < 'a' or c > 'z');
}

int main() {
    char s1[] = "TO JEST BARDZO TAJNY TEKST!@#$%";
    char s2[] = "to jest bardzo tajny tekst!@#$%";
    char klucz[] = "TAJNE!!";
    szyfruj(s1,klucz);
    szyfruj(s2,klucz);
    printf("%s\n%s",s1,s2);
    return 0;
}

//Lizaveta Khudalei

#include "Uczestnik.h"

struct Member //wezel
{
    Uczestnik *sex;
    unsigned int id;
    Member *prawaReka;
    Member *lewaReka;

    Member(Uczestnik *sex, unsigned int id, Member *lewaReka, Member *prawaReka) : sex(sex), id(id),
                                                                                   prawaReka(prawaReka),
                                                                                   lewaReka(lewaReka) {}

};

class Wodzirej //lista dwukierunkowa
{
private:
    Member *head;   //Wskaznik na poczatek
    unsigned int numberOfPlayers;
    unsigned int index;
    unsigned int numberOfWoman;
    bool isStarted;
    bool isStopped;
    Member *hasFlag;

public:
    Wodzirej()   //stworzenie pierwszego elementu- Wodzireja(0)
    {
        head = new Member(new Uczestnik(Uczestnik::W), 0, nullptr, nullptr);
        head->prawaReka = head;
        head->lewaReka = head;
        numberOfPlayers = 1;
        index = 0;
        numberOfWoman = 0;
        hasFlag = head;
        isStopped = true;
        isStarted = false;
    };

    unsigned int dolacz(Uczestnik *osoba);

    unsigned int lastId;

    unsigned int dolacz(Uczestnik *osoba, unsigned int pozycja);

    bool rozpocznij();

    bool zakoncz();

    bool zrezygnuj(Uczestnik *osoba) { return false; };

    bool zrezygnuj(unsigned int id) { return false; };

    bool przekaz(Uczestnik *osoba) { return false; };

    bool przekaz(unsigned int id) { return false; };

    void uczestnicy() const ;

    void uczestnicy(Uczestnik::Plec p) const {};

    unsigned int liczba() const { return numberOfPlayers; };

    Uczestnik *wodzirej() const { return head->sex ;};

//wspomocnicze funkcji
    bool isPlayerAlreadyInGame(Uczestnik *osoba); //czy osoba juz bierze udzial 

    void insertAfter(Member *node, Uczestnik *osoba); //dolaczenie osoby

    Member *getPlayerWithPos(unsigned int pos); //poszukiwanie gdzie wlasnie trzeba wstawic osobe
};

bool Wodzirej::isPlayerAlreadyInGame(Uczestnik *osoba) {
    Member *temp = head;
    do {
        if (temp->sex == osoba) {
            return true;
        }
        temp = temp->prawaReka;
    } while (temp != head);

    return false;
}

void Wodzirej::insertAfter(Member *node, Uczestnik *osoba) {

    if (osoba->plec == Uczestnik::K) {
        numberOfWoman++;
    }

    numberOfPlayers++;
    index++;

    auto *newPlayer = new Member(osoba, index, node, node->prawaReka);
    node->prawaReka->lewaReka = newPlayer;
    node->prawaReka = newPlayer;

}

unsigned int Wodzirej::dolacz(Uczestnik *osoba) {
    if (!osoba or osoba->plec == Uczestnik::W or isPlayerAlreadyInGame(osoba) ) { return 0; }  //czy nie jest wskaznik zerowy

    insertAfter(head, osoba);

    return index;
}

Member *Wodzirej::getPlayerWithPos(unsigned int pos) {
    Member *temp = head;
    for (int i = 0; i <= pos; ++i) {
        temp = temp->lewaReka;
    }
    return temp;
}

unsigned int Wodzirej::dolacz(Uczestnik *osoba, unsigned int pozycja) {
    if (!osoba or osoba->plec == Uczestnik::W or isPlayerAlreadyInGame(osoba) or pozycja >= numberOfPlayers)
        return 0;

    Member *temp = getPlayerWithPos(pozycja);

    insertAfter(temp, osoba);
    return index;
}


bool Wodzirej::rozpocznij() {

    if (isStarted or !isStopped or numberOfPlayers == 1 or numberOfWoman == (numberOfPlayers - 1) or
        numberOfWoman == 0) {
        return false;
    }
    isStarted = true;
    isStopped = false;
    hasFlag = head->prawaReka;
    return true;
}

bool Wodzirej::zakoncz() {
    if (isStarted) {
        hasFlag = head;
        isStarted = false;
        isStopped = true;
        return true;
    } else {
        return false;
    }
}

void Wodzirej::uczestnicy() const {
    Member *temp = head;
    do {
        std::cout << "plec: " << temp->sex->plec << ", nr: " << temp->id << std::endl;
        temp = temp->lewaReka;
    } while (temp != head);
}

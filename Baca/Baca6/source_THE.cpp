// Van The Ho

#include "Uczestnik.h"
#include <iostream>

using namespace std;

class Player {
private:
    Uczestnik *u;
    unsigned int id;
    Player *left;
    Player *right;

public:
    Player(Uczestnik *u, unsigned int id, Player *left, Player *right) : u(u), id(id), left(left), right(right) {}

    ~Player() {
        delete (u);
        delete (left);
        delete (right);
    }

    Uczestnik *getU() const {
        return u;
    }

    Player *getRight() const {
        return right;
    }

    Player *getLeft() const {
        return left;
    }

    unsigned int getId() const {
        return id;
    }

    void setRight(Player *right_) {
        right = right_;
    }

    void setLeft(Player *left_) {
        left = left_;
    }
};

class Wodzirej {

private:
    Player *leader;
    Player *hasFlag;
    bool isStarted;
    unsigned int numberOfWoman;
    unsigned int numberOfPlayers;
    unsigned int currentIndex;

    void insertAfter(Player *node, Uczestnik *osoba) {
        if (osoba->plec == Uczestnik::K) {
            numberOfWoman++;
        }

        numberOfPlayers++;
        currentIndex++;

        auto *newPlayer = new Player(osoba, currentIndex, node, node->getRight());
        node->getRight()->setLeft(newPlayer);
        node->setRight(newPlayer);

    }

    bool isPlayerAlreadyInGame(Uczestnik *osoba) {
        Player *temp = leader;
        do {
            if (temp->getU() == osoba) {
                return true;
            }
            temp = temp->getRight();
        } while (temp != leader);

        return false;
    }

    Player *getPlayerWithPos(unsigned int pos) {
        Player *temp = leader;
        for (int i = 0; i <= pos; ++i) {
            temp = temp->getLeft();
        }
        return temp;
    }

    Player *getPlayerWithPointerUczesnik(Uczestnik *osoba) {
        Player *temp = leader;
        do {
            if (temp->getU() == osoba) {
                return temp;
            }
            temp = temp->getRight();
        } while (temp != leader);

        return nullptr;
    }

    Player *getPlayerWithId(unsigned int id) {
        Player *temp = leader;
        do {
            if (temp->getId() == id) {
                return temp;
            }
            temp = temp->getRight();
        } while (temp != leader);
        return nullptr;
    }


public :
    Wodzirej() {
        leader = new Player(new Uczestnik(Uczestnik::W), 0, nullptr, nullptr);
        leader->setRight(leader);
        leader->setLeft(leader);
        numberOfPlayers = 1;
        currentIndex = 0;
        numberOfWoman = 0;
        isStarted = false;
        hasFlag = leader;
    }


    unsigned int dolacz(Uczestnik *osoba) {
        if (!osoba or osoba->plec == Uczestnik::W or isPlayerAlreadyInGame(osoba)) return 0;

        insertAfter(leader, osoba);

        return currentIndex;
    }


    unsigned int dolacz(Uczestnik *osoba, unsigned int pozycja) {
        if (!osoba or osoba->plec == Uczestnik::W or isPlayerAlreadyInGame(osoba) or pozycja >= numberOfPlayers)
            return 0;

        Player *temp = getPlayerWithPos(pozycja);
        insertAfter(temp, osoba);
        return currentIndex;

    }

    bool rozpocznij() {
        if (isStarted or numberOfPlayers == 1 or numberOfWoman == (numberOfPlayers - 1) or numberOfWoman == 0) {
            return false;
        }
        isStarted = true;
        hasFlag = leader->getRight();
        return true;
    }

    bool zakoncz() {
        if (isStarted) {
            hasFlag = leader;
            isStarted = false;
            return true;
        }

        return false;
    }

    bool zrezygnuj(Uczestnik *osoba) {
        Player *temp = getPlayerWithPointerUczesnik(osoba);

        if (!temp or !osoba or hasFlag->getU() == osoba or leader->getU() == osoba) {
            return false;
        }

        temp->getLeft()->setRight(temp->getRight());
        temp->getRight()->setLeft(temp->getLeft());
        return true;
    }


    bool zrezygnuj(unsigned int id) {
        Player *temp = getPlayerWithId(id);
        if (!temp or hasFlag->getId() == id or id == 0) {
            return false;
        }
        temp->getLeft()->setRight(temp->getRight());
        temp->getRight()->setLeft(temp->getLeft());
        return true;
    }

    bool przekaz(Uczestnik *osoba) {
        Player *temp = getPlayerWithPointerUczesnik(osoba);
        if (!isStarted or !temp or hasFlag->getU()->plec == osoba->plec or
            osoba->plec == Uczestnik::W) {
            return false;
        }
        hasFlag = temp;
        return true;
    }

    bool przekaz(unsigned int id) {
        Player *temp = getPlayerWithId(id);
        if (!isStarted or !temp or hasFlag->getU()->plec == temp->getU()->plec or
            temp->getU()->plec == Uczestnik::W) {
            return false;
        }
        hasFlag = temp;
        return true;
    }

    unsigned int liczba() const {
        return numberOfPlayers;
    }

    void uczestnicy() const {
        Player *temp = leader;
        do {
            cout << "plec: " << temp->getU()->plec << ", nr: " << temp->getId() << endl;
            temp = temp->getLeft();
        } while (temp != leader);
    }

    void uczestnicy(Uczestnik::Plec p) const {
        Player *temp = leader;
        do {
            if (temp->getU()->plec == p) {
                cout << "nr: " << temp->getId() << endl;
            }
            temp = temp->getRight();
        } while (temp != leader);
    }

    Uczestnik *wodzirej() const {
        return leader->getU();
    }


    ~Wodzirej() {
        /*Player *current = leader;
        while (current) {
            Player* next = current->getRight();
            delete current;
            current = next;
        }*/
        //delete(hasFlag);
    };
};


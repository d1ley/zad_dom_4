#include "Haslo.h"
#include <iostream>

Haslo::Haslo(const std::string& haslo) : haslo(haslo) {
    maska.resize(haslo.length(), true);
}

void Haslo::wyswietl() {
    for (size_t i = 0; i < haslo.length(); i++) {
        if (maska[i]) {
            std::cout << ".";
        }
        else {
            std::cout << haslo[i];
        }
    }
}

bool Haslo::zgadnijHaslo(const std::string& proba) {
    return haslo == proba;
}

bool Haslo::sprawdzLitere(char literka) {
    bool zgadl = false;
    for (size_t i = 0; i < haslo.length(); i++) {
        if (haslo[i] == literka && maska[i]) {
            maska[i] = false;
            zgadl = true;
        }
    }
    return zgadl;
}

int Haslo::podajKwote() {
    int kwota = 0;
    // ...
    return kwota;
}

int Haslo::liczbaLiter(char literka) {
    int liczba = 0;
    // ...
    return liczba;
}

bool Haslo::czyZgadniete() {
    for (bool b : maska) {
        if (b) {
            return false;
        }
    }
    return true;
}

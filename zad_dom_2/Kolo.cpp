#include "Kolo.h"
#include <iostream>

Kolo::Kolo() {
    kola = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };
}

void Kolo::wyswietlWynikLosowania() {
    int indeks = losujKwote();
    if (kola[indeks] == 0) {
        std::cout << "Strata kolejki" << std::endl;
    }
    else if (kola[indeks] == -1) {
        std::cout << "Bankrut" << std::endl;
    }
    else {
        std::cout << kola[indeks] << std::endl;
    }
}

int Kolo::losujKwote() {
    return rand() % kola.size();
}

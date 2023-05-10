#include "Gra.h"
#include "Kolor.h"
#include <iostream>
#include <fstream>

using namespace std;


Gra::Gra() : kolejka(0);

//2 OPERATOR:
istream& operator>>(istream& is, Gra& g) {
    cout << Gracz::gracze[g.kolejka].imie << ": Podaj litere" << endl;
    char literka = Gra::WczytajZnak();
    return is;
}



void Gra::rozpocznijGre() {
    wczytajHasla();
    haslo = Haslo(listaHasel);

    gracze[0] = Gracz("Bryanusz");
    gracze[1] = Gracz("Jessica");
    gracze[2] = Gracz("Nepomucen");

    while (true) {
        wyswietlStanGry();
        menu.wyswietlMenu();
        char wybor = menu.wczytajWybor();

        if (wybor == '1') {
            zgadujHaslo();
        }
        else if (wybor == '2') {
            krecKolem();
        }
    }
}

void wczytajHasla (const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik) {
        std::cout << "Nie można otworzyć pliku " << nazwaPliku << std::endl;
        return;
    }

    std::string haslo;
    while (std::getline(plik, haslo)) {
        listaHasel.push_back(haslo);
    }

    plik.close();
}

void Gra::wyswietlStanGry() {
    std::cout << Kolor::zielony() << "Gra koło fortuny" << Kolor::reset() << std::endl;

    for (int i = 0; i < 3; i++) {
        if (i == kolejka) {
            std::cout << Kolor::niebieski();
        }
        std::cout << gracze[i].imie << "\t" << gracze[i].kasa << std::endl;
        std::cout << Kolor::reset();
    }

    std::cout << std::endl;
}

void Gra::zgadujHaslo() {
    std::string proba;
    std::cout << "Podaj haslo: ";
    std::cin.ignore();
    std::getline(std::cin, proba);

    if (haslo.sprawdzHaslo(proba)) {
        std::cout << Kolor::zielony() << "Gratulacje! Haslo zgadniete!" << Kolor::reset() << std::endl;
        gracze[kolejka].portfel += gracze[kolejka].kasa;
        zakonczGre();
    }
    else {
        kolejka = (kolejka + 1) % 3;
        std::cout << Kolor::czerwony() << "Niepoprawne haslo. Kolej na kolejnego gracza." << Kolor::reset() << std::endl;
    }
}

void Gra::krecKolem() {
    int indeks = losujIndeksKola();
    int kwota = Kolo[indeks];

    if (kwota == 0) {
        std::cout << Kolor::czerwony() << "Strata kolejki!" << Kolor::reset() << std::endl;
        kolejka = (kolejka + 1) % 3;
    }
    else if (kwota == -1) {
        std::cout << Kolor::czerwony() << "Bankrut!" << Kolor::reset() << std::endl;
        gracze[kolejka].kasa = 0;
        kolejka = (kolejka + 1) % 3;
    }
    else {
        std::cout << Kolor::niebieski() << kwota << Kolor::reset() << std::endl;
        gracze[kolejka].kasa += kwota;
    }
}

int Gra::losujIndeksKola() {
    srand(time(NULL));
    return rand() % 16;
}

void Gra::zakonczGre() {
    std::cout << "BRAWO!" << std::endl;
    exit(0);
}




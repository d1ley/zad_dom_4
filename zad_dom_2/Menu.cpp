#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {}

// 1 OPERATOR:
ostream& operator<<(ostream& os, const Menu& menu) {

    os << "1. zgaduj haslo" << endl;
    os << "2. krecenie kolem" << endl;
    return os;
}


char Menu::wczytajWybor() {
    char wybor;
    std::cin >> wybor;

    while (wybor != '1' && wybor != '2') {
        std::cout << std::endl << "Wybierz [1-2]: ";
        std::cin >> wybor;
    }

    return wybor;
}

void Menu::wyswietlMenu() {
    std::cout << "1. Zgaduj haslo" << std::endl;
    std::cout << "2. Krecenie kolem" << std::endl;
}
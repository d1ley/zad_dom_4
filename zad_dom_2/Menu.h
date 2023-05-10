#ifndef MENU_H
#define MENU_H
#include <iostream>

class Menu {
public:
    Menu();
    char wczytajWybor();
    void wyswietlMenu();

    ostream& operator<<(ostream& os, const Menu& menu);

};


#endif 

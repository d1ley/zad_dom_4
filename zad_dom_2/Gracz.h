#ifndef GRACZ_H
#define GRACZ_H
#include <iostream>
#include <string>



class Gracz {
public:
    
    std:: string imie;
    int kasa;
    int portfel;

    Gracz();

    bool operator==(const Gracz& g1, const Gracz& g2);
    bool operator!=(const Gracz& g1, const Gracz& g2);
    ostream& operator<<(ostream& os, const Gracz& gracz);
};

#endif 

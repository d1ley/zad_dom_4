#include "Gracz.h"
#include <iostream>

using namespace std;

Gracz::Gracz() : kasa(0), portfel(0) {}

// 3 OPERATOR:
bool operator==(const Gracz& g1, const Gracz& g2)
{
    return g1.kasa == g2.kasa;
}

// 4 OPERATOR:
bool operator!=(const Gracz& g1, const Gracz& g2)
{
    return g1.portfel != g2.portfel;
}
// 5 OPERATOR: 
ostream& operator<<(ostream& os, const Gracz& gracz)
{
    os << gracz.imie << "\t" << gracz.kasa << "\n";
    return os;
}
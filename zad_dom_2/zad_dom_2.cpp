
#include "Haslo.h"
#include "Gra.h"
#include "Gracz.h"
#include "Kolo.h"
#include "Menu.h"
#include "Kolor.h"

int main() {
    Gra::wczytajHasla("dane.txt");
    Gra::rozpocznijGre();

    return 0;
}

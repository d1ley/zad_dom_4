#ifndef HASLO_H
#define HASLO_H

#include <string>
#include <vector>

class Haslo {
public:
    Haslo(const std::string& haslo);

    void wyswietl();
    bool zgadnijHaslo(const std::string& proba);
    bool sprawdzLitere(char literka);
    int podajKwote();
    int liczbaLiter(char literka);
    bool czyZgadniete();

private:
    std::string haslo;
    std::vector<bool> maska;
};

#endif 

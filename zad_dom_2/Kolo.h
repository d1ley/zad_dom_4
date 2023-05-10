#ifndef KOLO_H
#define KOLO_H
#include <vector>
#include <string>

class Kolo {
public:
    Kolo();
    void wyswietlWynikLosowania();
    int losujKwote();

private:
    std::vector<int> kola;
};

#endif 

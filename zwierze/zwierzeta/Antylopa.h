#ifndef SYMULACJASWIATA_ANTYLOPA_H
#define SYMULACJASWIATA_ANTYLOPA_H
#include "../Zwierze.h"

class Antylopa : public Zwierze{
public:
    Antylopa(int x, int y, Swiat &swiat);
    void akcja() override;
    void walka(Organizm * atakujacy, int x, int y, int xnast, int ynast) override;
    Organizm * stworzPotomka(int x, int y) override;
};


#endif //SYMULACJASWIATA_ANTYLOPA_H

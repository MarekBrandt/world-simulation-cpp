#ifndef SYMULACJASWIATA_ZOLW_H
#define SYMULACJASWIATA_ZOLW_H
#include "../Zwierze.h"

class Zolw : public Zwierze {
public:
    Zolw(int x, int y, Swiat &swiat);
    void akcja() override;
    void walka(Organizm * wskNaNowyObiekt, int xpoprz, int ypoprz, int xnast, int ynast) override;
    Organizm * stworzPotomka(int x, int y) override;
};


#endif //SYMULACJASWIATA_ZOLW_H

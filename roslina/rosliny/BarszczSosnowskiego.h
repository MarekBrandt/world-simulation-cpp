#ifndef SYMULACJASWIATA_BARSZCZSOSNOWSKIEGO_H
#define SYMULACJASWIATA_BARSZCZSOSNOWSKIEGO_H
#include "../Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
    BarszczSosnowskiego(int x, int y, Swiat &swiat);
    Organizm * stworzPotomka(int x, int y) override;
    void akcja() override;
    void kolizja(int x, int y, int xnast, int ynast) override;
};


#endif //SYMULACJASWIATA_BARSZCZSOSNOWSKIEGO_H

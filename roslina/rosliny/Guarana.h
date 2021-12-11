#ifndef SYMULACJASWIATA_GUARANA_H
#define SYMULACJASWIATA_GUARANA_H
#include "../Roslina.h"

class Guarana : public Roslina {
public:
    Guarana(int x, int y, Swiat &swiat);
    Organizm * stworzPotomka(int x, int y) override;
    void kolizja(int x, int y, int xnast, int ynast) override;
};


#endif //SYMULACJASWIATA_GUARANA_H

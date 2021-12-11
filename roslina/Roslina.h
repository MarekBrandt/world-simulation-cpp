#ifndef SYMULACJASWIATA_ROSLINA_H
#define SYMULACJASWIATA_ROSLINA_H
#include "../Organizm.h"


class Roslina : public Organizm {
    void rozprzestrzeniajSie(KierunekRuchu gdzie);
public:
    Roslina(int x, int y, Swiat &swiat, string nazwaObiektu, int sila);
    void akcja() override;
    void kolizja(int x, int y, int xnast, int ynast) override;
    //Organizm * stworzPotomka(int x, int y) override = 0;

};


#endif //SYMULACJASWIATA_ROSLINA_H

#ifndef SYMULACJASWIATA_CZLOWIEK_H
#define SYMULACJASWIATA_CZLOWIEK_H
#include "Zwierze.h"

class Czlowiek : public Zwierze {
    KierunekRuchu gdziePojdzie;
    int umiejSpecjalnaAktywna;
public:
    Czlowiek(int x, int y, Swiat &swiat);
    void akcja() override;
    void kolizja(int x, int y, int xnast, int ynast) override;
    void setGdziePojdzie(KierunekRuchu gdzie);
    void setUmiejSpecjalna();
    Organizm * stworzPotomka(int x, int y) override;
    bool getAktywnoscSpecjalnej() const;
};


#endif //SYMULACJASWIATA_CZLOWIEK_H

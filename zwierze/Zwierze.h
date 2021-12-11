#ifndef SYMULACJASWIATA_ZWIERZE_H
#define SYMULACJASWIATA_ZWIERZE_H
#include "../Organizm.h"
#include "../jednostki.h"
using namespace std;

class Zwierze : public Organizm {
public:
    void wykonajRuch(KierunekRuchu gdzie);
    Zwierze(int x, int y, Swiat &swiat, string nazwaObiektu, int sila, int inicjatywa);
    void akcja() override;
    void kolizja(int xpoprz, int ypoprz, int xnast, int ynast) override;
    void reprodukcja(Organizm * wskNaNowyObiekt, int x, int y, int xnast, int ynast);
    virtual void walka(Organizm * wskNaNowyObiekt, int x, int y, int xnast, int ynast);
};


#endif //SYMULACJASWIATA_ZWIERZE_H

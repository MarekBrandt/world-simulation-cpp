#ifndef SYMULACJASWIATA_LIS_H
#define SYMULACJASWIATA_LIS_H
#include "../Zwierze.h"

class Lis : public Zwierze{

public:
    Lis(int x, int y, Swiat &swiat);
    Organizm * stworzPotomka(int x, int y) override;
    KierunekRuchu losujDostepneSasiedniePole(Wspolrzedne polozenie) override;
};


#endif //SYMULACJASWIATA_LIS_H

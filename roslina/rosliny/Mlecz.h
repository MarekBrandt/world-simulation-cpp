#ifndef SYMULACJASWIATA_MLECZ_H
#define SYMULACJASWIATA_MLECZ_H
#include "../Roslina.h"

class Mlecz : public Roslina {
public:
    Mlecz(int x, int y, Swiat &swiat);
    Organizm * stworzPotomka(int x, int y) override;
    void akcja() override;
};


#endif //SYMULACJASWIATA_MLECZ_H

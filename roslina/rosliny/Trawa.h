#ifndef SYMULACJASWIATA_TRAWA_H
#define SYMULACJASWIATA_TRAWA_H
#include "../Roslina.h"

class Trawa : public Roslina {
public:
    Trawa(int x, int y, Swiat &swiat);
    Organizm * stworzPotomka(int x, int y) override;
};


#endif //SYMULACJASWIATA_TRAWA_H

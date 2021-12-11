#ifndef SYMULACJASWIATA_WILCZEJAGODY_H
#define SYMULACJASWIATA_WILCZEJAGODY_H
#include "../Roslina.h"

class WilczeJagody : public Roslina {
public:
    WilczeJagody(int x, int y, Swiat &swiat);
    Organizm * stworzPotomka(int x, int y) override;
    void kolizja(int x, int y, int xnast, int ynast) override;
};


#endif //SYMULACJASWIATA_WILCZEJAGODY_H

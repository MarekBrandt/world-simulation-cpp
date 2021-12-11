#ifndef SYMULACJASWIATA_WILK_H
#define SYMULACJASWIATA_WILK_H
#include "../Zwierze.h"

class Wilk : public Zwierze{

public:
    Wilk(int x, int y, Swiat &swiat);
    Organizm * stworzPotomka(int x, int y) override;
};


#endif //SYMULACJASWIATA_WILK_H

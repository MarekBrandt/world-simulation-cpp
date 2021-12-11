#ifndef SYMULACJASWIATA_OWCA_H
#define SYMULACJASWIATA_OWCA_H
#include "../Zwierze.h"

class Owca : public Zwierze{
public:
    Owca(int x, int y, Swiat &swiat);
    Organizm * stworzPotomka(int x, int y) override;
};


#endif //SYMULACJASWIATA_OWCA_H

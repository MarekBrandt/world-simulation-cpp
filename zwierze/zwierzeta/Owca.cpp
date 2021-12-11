#include "Owca.h"

Owca::Owca(int x, int y, Swiat &swiat)
        :Zwierze(x, y, swiat, "Owca", 4, 4) {
    setSymbol('O');
}

Organizm *Owca::stworzPotomka(int x, int y) {
    return new Owca(x,y,swiat);
}
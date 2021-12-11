#include "Wilk.h"


Wilk::Wilk(int x, int y, Swiat &swiat)
    :Zwierze(x, y, swiat, "Wilk", 9, 5) {
    setSymbol('W');
}

Organizm *Wilk::stworzPotomka(int x, int y) {
    return new Wilk(x,y,swiat);
}



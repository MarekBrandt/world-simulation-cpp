#include "Trawa.h"

Trawa::Trawa(int x, int y, Swiat &swiat)
    :Roslina(x, y, swiat, "Trawa", 0) {
    setSymbol('T');
}


Organizm *Trawa::stworzPotomka(int x, int y) {
    return new Trawa(x,y,swiat);
}


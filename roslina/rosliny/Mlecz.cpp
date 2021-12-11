#include "Mlecz.h"

Mlecz::Mlecz(int x, int y, Swiat &swiat)
        :Roslina(x, y, swiat, "Mlecz", 0) {
    setSymbol('M');
}

Organizm *Mlecz::stworzPotomka(int x, int y) {
    return new Mlecz(x,y,swiat);
}

void Mlecz::akcja() {
    int liczbaProb = 3;
    for ( int i = 0; i < liczbaProb; i++) {
        if(this->getMogeRuszyc()) Roslina::akcja();
    }
}

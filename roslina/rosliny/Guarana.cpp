#include "Guarana.h"

Guarana::Guarana(int x, int y, Swiat &swiat)
    :Roslina(x, y, swiat, "Guarana", 0) {
    setSymbol('G');
}

Organizm *Guarana::stworzPotomka(int x, int y) {
    return new Guarana(x, y, swiat);
}

void Guarana::kolizja(int x, int y, int xnast, int ynast) {
    Organizm * wskNaObiektKtoryWejdzie = swiat.getWskZPlanszy(x,y);
    wskNaObiektKtoryWejdzie->increaseSila(3);
    Roslina::kolizja(x, y, xnast, ynast);
}

#include "Zolw.h"

Zolw::Zolw(int x, int y, Swiat &swiat)
        :Zwierze(x, y, swiat, "Zolw", 2, 1) {
    setSymbol('Z');
}

Organizm *Zolw::stworzPotomka(int x, int y) {
    return new Zolw(x,y,swiat);
}

void Zolw::akcja() {
    int los = rand() % 100 + 1;
    if(los >= 75) {
        Zwierze::akcja();
    }
}

void Zolw::walka(Organizm *wskNaNowyObiekt, int xpoprz, int ypoprz, int xnast, int ynast) {
    if(wskNaNowyObiekt->getSila() < 5) {
        cout << this->getNazwa() << this->getId() << " odparl atak " << wskNaNowyObiekt->getNazwa() << wskNaNowyObiekt->getId() << endl;
    }
    else Zwierze::walka(wskNaNowyObiekt, xpoprz, ypoprz, xnast, ynast);
}

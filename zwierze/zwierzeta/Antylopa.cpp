#include "Antylopa.h"

Antylopa::Antylopa(int x, int y, Swiat &swiat)
        :Zwierze(x, y, swiat, "Antylopa", 4, 4) {
    setSymbol('A');
}

Organizm *Antylopa::stworzPotomka(int x, int y) {
    return new Antylopa(x,y,swiat);
}

void Antylopa::akcja() {
    int zasieg = 2;
    for( int i = 0; i < zasieg; i++) {
        if(getMogeRuszyc())
            Zwierze::akcja();
    }
}

void Antylopa::walka(Organizm *wskNaNowyObiekt, int x, int y, int xnast, int ynast) {
    int los = rand() % 2;
    if(los) {
        Zwierze::walka(wskNaNowyObiekt, x, y, xnast, ynast);
    }
    else {
        KierunekRuchu gdzie = losujDostepnePusteSasiedniePole(Wspolrzedne(xnast, ynast));
        if(gdzie == zostan) Zwierze::walka(wskNaNowyObiekt, x, y, xnast, ynast);
        else {
            int xnowy = xnast + wektorPrzesuniecia(gdzie).x;
            int ynowy = ynast + wektorPrzesuniecia(gdzie).y;
            this->setPozycja(xnowy, ynowy);
            swiat.dodajOrganizmNaPlansze(xnowy, ynowy, this);
            wskNaNowyObiekt->setPozycja(xnast, ynast);
            swiat.usunOrganizmZPlanszy(x,y);
            swiat.dodajOrganizmNaPlansze(xnast,ynast, wskNaNowyObiekt);
            cout << wskNaNowyObiekt->getNazwa()<<wskNaNowyObiekt->getId() << " idzie na pole ("<<wskNaNowyObiekt->getPozycja().x
                <<","<<wskNaNowyObiekt->getPozycja().y<<") ale "<<this->getNazwa()<<this->getId()<<" ucieka\n";
        }
    }

}

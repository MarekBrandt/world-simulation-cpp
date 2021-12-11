#include "Roslina.h"
#include <utility>

#define SZANSZANAZASIANIE 5

Roslina::Roslina(int x, int y, Swiat &swiat, string nazwaObiektu, int sila)
    : Organizm(x, y, swiat, std::move(nazwaObiektu), "Roslina", sila, 0) {}

void Roslina::akcja() {
    int los = rand() % 100 + 1;
    if(los <= SZANSZANAZASIANIE) {
        KierunekRuchu ktorePole = losujDostepnePusteSasiedniePole(this->getPozycja());
        if(ktorePole != zostan) {
            rozprzestrzeniajSie(ktorePole);
            this->setMogeRuszyc(false);
        }
    }
}

void Roslina::rozprzestrzeniajSie(KierunekRuchu gdzie) {
    int x = getPozycja().x;
    int y = getPozycja().y;
    int dx, dy;

    dx = wektorPrzesuniecia(gdzie).x;
    dy = wektorPrzesuniecia(gdzie).y;

    Organizm * potomek = this->stworzPotomka(x + dx, y + dy);
    cout << this->getNazwa() << this->getId() << " rozprzestrzenia sie" << endl;
    cout << "Powstaje nowa " << potomek->getNazwa() << potomek->getId()
        << " na polu (" << x+dx << "," << y+dy << ")" << endl;
}

void Roslina::kolizja(int x, int y, int xnast, int ynast) {
    Organizm * wskNaObiektKtoryWejdzie = swiat.getWskZPlanszy(x,y);

    if(wskNaObiektKtoryWejdzie->getSila() >= this->getSila()) {
        wskNaObiektKtoryWejdzie->setMogeRuszyc(false);
        cout << wskNaObiektKtoryWejdzie->getNazwa() << wskNaObiektKtoryWejdzie->getId() << " idzie na pole (" << xnast << "," << ynast << ") i ";
        cout << "zjada "<<this->getNazwa()<<this->getId()<<endl;
        swiat.usunOrganizmZPlanszy(xnast, ynast);
        swiat.usunOrganizmZPlanszy(x, y);
        swiat.dodajOrganizmNaListeDoUsuniecia(this);
        swiat.dodajOrganizmNaPlansze(xnast, ynast, wskNaObiektKtoryWejdzie);
        wskNaObiektKtoryWejdzie->setPozycja(xnast, ynast);
    }
    else {
        cout << wskNaObiektKtoryWejdzie->getNazwa() << wskNaObiektKtoryWejdzie->getId() << " idzie na pole (" << xnast << "," << ynast << ") i ";
        cout << "zostaje zabity przez "<< this->getNazwa()<<this->getId()<<endl;
        swiat.usunOrganizmZPlanszy(x, y);
        swiat.dodajOrganizmNaListeDoUsuniecia(wskNaObiektKtoryWejdzie);
    }
}


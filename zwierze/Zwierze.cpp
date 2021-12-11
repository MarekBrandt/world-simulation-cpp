#include "Zwierze.h"

void Zwierze::wykonajRuch(KierunekRuchu gdzie) {
    int x = getPozycja().x;
    int y = getPozycja().y;
    int dx, dy;

    dx = wektorPrzesuniecia(gdzie).x;
    dy = wektorPrzesuniecia(gdzie).y;

    if(swiat.getWskZPlanszy(x + dx,y + dy) == nullptr) {
        setPozycja(x + dx , y + dy);
        cout << this->getNazwa()<<this->getId()<<" poszedl na pole (" <<this->getPozycja().x<<","<<this->getPozycja().y<<")\n";
        swiat.usunOrganizmZPlanszy(x, y);
        swiat.dodajOrganizmNaPlansze(this->getPozycja().x, this->getPozycja().y, this);
    }
    else swiat.getWskZPlanszy(x + dx,y + dy)->kolizja(x, y, x + dx, y + dy);
}

void Zwierze::akcja() {
   KierunekRuchu dostepnePole = losujDostepneSasiedniePole(this->getPozycja());
   if(dostepnePole != zostan) {
       wykonajRuch(dostepnePole);
   }
}

void Zwierze::kolizja(int xpoprz, int ypoprz, int xnast, int ynast) {

    Organizm * wskNaObiektKtoryWchodzi = swiat.getWskZPlanszy(xpoprz, ypoprz);

    if(wskNaObiektKtoryWchodzi->getNazwa() == this->getNazwa()) {
        reprodukcja(wskNaObiektKtoryWchodzi, xpoprz, ypoprz, xnast, ynast);
    }
    else {
        walka(wskNaObiektKtoryWchodzi, xpoprz, ypoprz, xnast, ynast);
    }
}

Zwierze::Zwierze(int x, int y, Swiat &swiat, string nazwaObiektu, int sila, int inicjatywa)
    : Organizm(x, y, swiat, nazwaObiektu, "Zwierze", sila, inicjatywa) {
}

void Zwierze::reprodukcja(Organizm * wskNaNowyObiekt, int xpoprz, int ypoprz, int xnast, int ynast) {
    this->setMogeRuszyc(false);
    wskNaNowyObiekt->setMogeRuszyc(false);
    cout <<wskNaNowyObiekt->getNazwa()<<wskNaNowyObiekt->getId()<<" i "<<this->getNazwa()<<this->getId()<<" zostaja rodzicami\n";
    if(losujDostepnePusteSasiedniePole(Wspolrzedne(xpoprz, ypoprz)) != zostan) {
        KierunekRuchu pole = losujDostepnePusteSasiedniePole(Wspolrzedne(xpoprz, ypoprz));
        int dx = wektorPrzesuniecia(pole).x;
        int dy = wektorPrzesuniecia(pole).y;
        Organizm * potomek = this->stworzPotomka(xpoprz + dx, ypoprz + dy);
        cout << potomek->getNazwa()<<potomek->getId()<<" urodzil sie na polu (" <<potomek->getPozycja().x<<","<<potomek->getPozycja().y<<")\n";
    }
    else if (losujDostepnePusteSasiedniePole(Wspolrzedne(xnast, ynast)) != zostan) {
        KierunekRuchu pole = losujDostepnePusteSasiedniePole(Wspolrzedne(xnast, ynast));
        int dx = wektorPrzesuniecia(pole).x;
        int dy = wektorPrzesuniecia(pole).y;
        Organizm * potomek = this->stworzPotomka(xnast + dx, ynast + dy);
        cout << potomek->getNazwa()<<potomek->getId()<<" urodzil sie na polu (" <<potomek->getPozycja().x<<","<<potomek->getPozycja().y<<")\n";
    }
    else cout << "Niestety, dziecko nie mialo miejsca i zmarlo\n";
}

void Zwierze::walka(Organizm * wskNaNowyObiekt, int xpoprz, int ypoprz, int xnast, int ynast) {
    int sila = this->getSila();
    if( wskNaNowyObiekt->getSila() >= sila) {
        wskNaNowyObiekt->setMogeRuszyc(false);
        cout << wskNaNowyObiekt->getNazwa() << wskNaNowyObiekt->getId() << " idzie na pole (" << xnast << "," << ynast << ") i ";
        cout << "zabija "<<this->getNazwa()<<this->getId()<<endl;
        swiat.usunOrganizmZPlanszy(xnast, ynast);
        swiat.usunOrganizmZPlanszy(xpoprz, ypoprz);
        swiat.dodajOrganizmNaListeDoUsuniecia(this);
        swiat.dodajOrganizmNaPlansze(xnast, ynast, wskNaNowyObiekt);
        wskNaNowyObiekt->setPozycja(xnast, ynast);
    }
    else {
        cout << wskNaNowyObiekt->getNazwa() << wskNaNowyObiekt->getId() << " idzie na pole (" << xnast << "," << ynast << ") i ";
        cout << "zostaje zabity przez "<< this->getNazwa()<<this->getId()<<endl;
        swiat.usunOrganizmZPlanszy(xpoprz, ypoprz);
        swiat.dodajOrganizmNaListeDoUsuniecia(wskNaNowyObiekt);
    }
}








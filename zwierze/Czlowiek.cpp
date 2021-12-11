#include "Czlowiek.h"

Czlowiek::Czlowiek(int x, int y, Swiat &swiat)
    :Zwierze(x, y, swiat, "Czlowiek", 5, 4) {
    swiat.setCzlowiek(this);
    umiejSpecjalnaAktywna = -5;
    gdziePojdzie = zostan;
    setSymbol('C');
}

void Czlowiek::akcja() {
    umiejSpecjalnaAktywna--;
    vector<KierunekRuchu> mozliweRuchy = zwrocWektorDostepnychPol(this->getPozycja());
    bool znaleziono = false;
    int size = mozliweRuchy.size();
    for ( int i = 0; i < size; i++) {
        if(mozliweRuchy[i] == gdziePojdzie) znaleziono = true;
    }
    if(!znaleziono) gdziePojdzie = zostan;

    if (gdziePojdzie != zostan) {
        int x = getPozycja().x;
        int y = getPozycja().y;
        int dx, dy;

        dx = wektorPrzesuniecia(gdziePojdzie).x;
        dy = wektorPrzesuniecia(gdziePojdzie).y;

        Organizm* wskNaObiektNastepny = swiat.getWskZPlanszy(x + dx, y + dy);

        if (wskNaObiektNastepny == nullptr) {
            setPozycja(x + dx, y + dy);
            cout << this->getNazwa() << this->getId() << " poszedl na pole (" << this->getPozycja().x << "," << this->getPozycja().y << ")\n";
            swiat.usunOrganizmZPlanszy(x, y);
            swiat.dodajOrganizmNaPlansze(this->getPozycja().x, this->getPozycja().y, this);
        }
        else {
            if (umiejSpecjalnaAktywna > 0) {
                swiat.usunOrganizmZPlanszy(x, y);
                swiat.dodajOrganizmNaPlansze(x + dx, y + dy, this);
                setPozycja(x + dx, y + dy);
                swiat.dodajOrganizmNaListeDoUsuniecia(wskNaObiektNastepny);
            }
            else {
                wskNaObiektNastepny->kolizja(x, y, x + dx, y + dy);
            }
        }
    }
}

void Czlowiek::kolizja(int x, int y, int xnast, int ynast) {
    Organizm* wskNaAtakujacego = swiat.getWskZPlanszy(x, y);
    if (umiejSpecjalnaAktywna <= 0) {
        Zwierze::kolizja(x, y, xnast, ynast);
    }
    else {
        if (wskNaAtakujacego->getSila() < this->getSila()) Zwierze::kolizja(x, y, xnast, ynast);
        else {
            KierunekRuchu wylosowanyKierunek = losujDostepneSasiedniePole(Wspolrzedne(xnast, ynast));
            int dx = wektorPrzesuniecia(wylosowanyKierunek).x;
            int dy = wektorPrzesuniecia(wylosowanyKierunek).y;

            Organizm* obiektNaWylosowanym = swiat.getWskZPlanszy(xnast + dx, ynast + dy);

            if (obiektNaWylosowanym != nullptr) {
                swiat.dodajOrganizmNaListeDoUsuniecia(obiektNaWylosowanym);
            }
            
            swiat.dodajOrganizmNaPlansze(xnast + dx, ynast + dy, this);
            swiat.usunOrganizmZPlanszy(x, y);
            swiat.dodajOrganizmNaPlansze(xnast, ynast, wskNaAtakujacego);
        }
    }
}

void Czlowiek::setGdziePojdzie(KierunekRuchu gdzie) {
    gdziePojdzie = gdzie;
}

void Czlowiek::setUmiejSpecjalna() {
    gdziePojdzie = zostan;
    if (umiejSpecjalnaAktywna < -3)
    {
        umiejSpecjalnaAktywna = 7;
        cout << "Niesmiertelnosc odpalona\n";
    }
    else
        cout << "Nie minelo jeszcze 5 tur od ostatniego uzycia\n";
}

Organizm *Czlowiek::stworzPotomka(int x, int y) {
    return new Czlowiek(x,y,swiat);
}

bool Czlowiek::getAktywnoscSpecjalnej() const
{
    if (umiejSpecjalnaAktywna > 0)
        return true;
    return false;
}

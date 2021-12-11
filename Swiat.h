#ifndef SWIAT_H
#define SWIAT_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Organizm.h"
#include "vector"
#include <string>
#include "jednostki.h"

using namespace std;

class Organizm;
class Czlowiek;

class Swiat {
    int W, H;
    int liczbaOrganizmow;
    Organizm *** generujPustySwiat() const;
    Organizm *** plansza;
    Czlowiek * czlowiek;
    vector<Organizm*> organizmy;
    vector<Organizm*> organizmyDoUsuniecia;
    vector<Organizm*> organizmyDoDodania;
public:
    Swiat(string nazwaPliku);
    Swiat(int W, int H);
    ~Swiat();
    void rysujSwiat();
    void dodajOrganizmNaPlansze(int x, int y, Organizm * organizm);
    void usunOrganizmZPlanszy(int x, int y);
    void dodajOrganizmyDoWektora();
    void dodajOrganizmNaListeDoUsuniecia(Organizm * organizm);
    void dodajOrganizmNaListeDoDodania(Organizm * organizm);
    void wykonajTure();
    void pozwolWszystkimRuszyc();
    void usunOrganizmyDoUsuniecia();
    void zapiszDoPliku();
    void stworzOrganizmy();
    void zrobObiektZTokenowZPliku(vector <string> tokeny);
    int getWidth() const;
    int getHeight() const;
    Wspolrzedne getWspolrzedneLosowegoPola();
    Organizm * getWskZPlanszy(int x, int y);
    int getLiczbaOrganizmow() const;
    void zainkrementujLiczbeOrganizmow();
    void setCzlowiek(Czlowiek * czlowiek);
    Czlowiek * getCzlowiek();
};


#endif //SWIAT_H

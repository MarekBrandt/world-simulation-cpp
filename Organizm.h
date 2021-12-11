#ifndef SYMULACJASWIATA_ORGANIZM_H
#define SYMULACJASWIATA_ORGANIZM_H
#include "Swiat.h"
#include "jednostki.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include "vector"

using namespace std;

class Swiat;

class Organizm {
    int sila, inicjatywa;
    int id;
    Wspolrzedne pozycja;
    string nazwaObiektu;
    string nazwaTypu;
    char symbol;
    bool mozeRuszyc;
protected:
    Swiat &swiat;
public:
    Organizm(int x, int y, Swiat &swiat, string nazwaObiektu, string nazwaTypu, int sila, int inicjatywa);
    virtual void akcja() = 0;
    virtual void kolizja(int x, int y, int xnast, int ynast) = 0;
    virtual Organizm * stworzPotomka(int x, int y) = 0;
    virtual KierunekRuchu losujDostepneSasiedniePole(Wspolrzedne polozenie);
    virtual KierunekRuchu losujDostepnePusteSasiedniePole(Wspolrzedne polozenie);
    void rysowanie() const;
    vector<KierunekRuchu> zwrocWektorDostepnychPol(Wspolrzedne polozenie);
    static Wspolrzedne wektorPrzesuniecia(KierunekRuchu gdzie);
    string obiektToString();

    //gettery
    Wspolrzedne getPozycja();
    string getNazwa();
    string getTyp();
    int getSila() const;
    int getId() const;
    bool getMogeRuszyc() const;
    int getInicjatywa() const;
    char getSymbol() const;

    //settery
    void setSymbol(char znak);
    void setPozycja(int x, int y);
    void setMogeRuszyc(bool ruszy);
    void increaseSila(int x);
    void setSila(int x);
    void setInicjatywa(int x);
};


#endif //SYMULACJASWIATA_ORGANIZM_H

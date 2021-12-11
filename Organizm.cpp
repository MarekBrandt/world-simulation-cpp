#include "Organizm.h"
#include "vector"



Organizm::Organizm(int x, int y, Swiat &swiat, string nazwaObiektu, string nazwaTypu, int sila, int inicjatywa)
    : pozycja(x, y), swiat(swiat), nazwaObiektu(nazwaObiektu), nazwaTypu(nazwaTypu), sila(sila), inicjatywa(inicjatywa){
    id = swiat.getLiczbaOrganizmow();
    swiat.zainkrementujLiczbeOrganizmow();
    mozeRuszyc = false;
    swiat.dodajOrganizmNaPlansze(x, y, this);
    swiat.dodajOrganizmNaListeDoDodania(this);
}

vector <KierunekRuchu> Organizm::zwrocWektorDostepnychPol(Wspolrzedne polozenie) {
    vector <KierunekRuchu> mozliweRuchy;
    int x = polozenie.x; int y = polozenie.y;

    if(x != 0) mozliweRuchy.insert(mozliweRuchy.begin(), wLewo);
    if(x != swiat.getWidth()-1) mozliweRuchy.insert(mozliweRuchy.begin(), wPrawo);
    if(y != 0) mozliweRuchy.insert(mozliweRuchy.begin(), wGore);
    if(y != swiat.getHeight()-1) mozliweRuchy.insert(mozliweRuchy.begin(), wDol);

    return mozliweRuchy;
}

KierunekRuchu Organizm::losujDostepneSasiedniePole(Wspolrzedne polozenie) {
    vector <KierunekRuchu> mozliweRuchy = zwrocWektorDostepnychPol(polozenie);

    int ktoryZWektora = rand() % mozliweRuchy.size();

    return mozliweRuchy[ktoryZWektora];
}

KierunekRuchu Organizm::losujDostepnePusteSasiedniePole(Wspolrzedne polozenie) {
    vector <KierunekRuchu> mozliweRuchy = zwrocWektorDostepnychPol(polozenie);
    vector <KierunekRuchu> znaleznionoPuste;

    int x = polozenie.x; int y = polozenie.y;
    int dx, dy;

    for(auto & i : mozliweRuchy) {
        dx = wektorPrzesuniecia(i).x;
        dy = wektorPrzesuniecia(i).y;

        if(swiat.getWskZPlanszy(x + dx, y + dy) == nullptr) znaleznionoPuste.push_back(i);
    }

    if(znaleznionoPuste.empty()) return zostan;

    int ktoryZWektora = rand() % znaleznionoPuste.size();

    return znaleznionoPuste[ktoryZWektora];
}

void Organizm::rysowanie() const {
    cout << symbol;
}

Wspolrzedne Organizm::wektorPrzesuniecia(KierunekRuchu gdzie) {
    int dx, dy;
    switch (gdzie) {
        case wLewo:
            dx = -1; dy = 0;
            break;
        case wPrawo:
            dx = 1; dy = 0;
            break;
        case wGore:
            dx = 0; dy = -1;
            break;
        case wDol:
            dx = 0; dy = 1;
            break;
        case zostan:
            dx = 0; dy = 0;
            break;
    }

    return {dx, dy};
}

string Organizm::obiektToString() {
    string znakObiektu(1, getSymbol());
    string xpoz = to_string(getPozycja().x);
    string ypoz = to_string(getPozycja().y);
    string silaVal = to_string(sila);
    string inicjatywaVal = to_string(inicjatywa);
    return  znakObiektu + " " + xpoz + " " + ypoz + " " + silaVal + " " + inicjatywaVal;
}

Wspolrzedne Organizm::getPozycja() {
    return pozycja;
}

string Organizm::getNazwa() {
    return nazwaObiektu;
}

string Organizm::getTyp() {
    return nazwaTypu;
}

int Organizm::getSila() const {
    return sila;
}

int Organizm::getId() const {
    return id;
}

bool Organizm::getMogeRuszyc() const {
    return mozeRuszyc;
}

char Organizm::getSymbol() const {
    return symbol;
}

int Organizm::getInicjatywa() const {
    return inicjatywa;
}

void Organizm::setSymbol(char znak) {
    this->symbol = znak;
}

void Organizm::setPozycja(int x, int y) {
    pozycja.x = x;
    pozycja.y = y;
}

void Organizm::setMogeRuszyc(bool ruszy) {
    mozeRuszyc = ruszy;
}

void Organizm::increaseSila(int x) {
    sila += x;
}

void Organizm::setSila(int x) {
    sila = x;
}

void Organizm::setInicjatywa(int x) {
    inicjatywa = x;
}









#include "Swiat.h"
#include <fstream>
#include <sstream>
#include <conio.h>
#include "zwierze/zwierzeta/Wilk.h"
#include "zwierze/zwierzeta/Owca.h"
#include "zwierze/zwierzeta/Lis.h"
#include "zwierze/zwierzeta/Zolw.h"
#include "zwierze/zwierzeta/Antylopa.h"
#include "roslina/rosliny/Trawa.h"
#include "roslina/rosliny/Mlecz.h"
#include "roslina/rosliny/Guarana.h"
#include "roslina/rosliny/WilczeJagody.h"
#include "roslina/rosliny/BarszczSosnowskiego.h"
#include "zwierze/Czlowiek.h"

#define LICZBAWILKOW 2
#define LICZBAOWIEC 2
#define LiCZBALISOW 2
#define LiCZBAZOLWI 2
#define LiCZBAANTYLOP 2
#define LiCZBATRAWY 2
#define LICZBAMLECZY 2
#define LICZBAGUARANY 2
#define LICZBAWILCZYCHJAGOD 2
#define LICZBABARSZCZU 1

void Swiat::stworzOrganizmy() {
    if(LICZBAWILKOW + LICZBAOWIEC + LiCZBALISOW + LICZBABARSZCZU + LICZBAWILCZYCHJAGOD + LICZBAMLECZY + LICZBAGUARANY + LiCZBATRAWY
       + LiCZBAANTYLOP + LiCZBAZOLWI + 1 > H*W)  {
        cout << "Za mala plansza jak na taka liczbe organizmow, koncze program";
        _getch();
        exit(1);}

    Wspolrzedne losowePole = getWspolrzedneLosowegoPola();

    new Czlowiek(losowePole.x, losowePole.y, *this);


    for(int i = 0; i < LICZBAWILKOW; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new Wilk(losowePolozenie.x, losowePolozenie.y, *this);
    }

    for(int i = 0; i < LICZBAOWIEC; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new Owca(losowePolozenie.x, losowePolozenie.y, *this);
    }

    for(int i = 0; i < LiCZBALISOW; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new Lis(losowePolozenie.x, losowePolozenie.y, *this);
    }

    for(int i = 0; i < LiCZBAZOLWI; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new Zolw(losowePolozenie.x, losowePolozenie.y, *this);
    }

    for(int i = 0; i < LiCZBAANTYLOP; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new Antylopa(losowePolozenie.x, losowePolozenie.y, *this);
    }

    for(int i = 0; i < LiCZBATRAWY; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new Trawa(losowePolozenie.x, losowePolozenie.y, *this);
    }

    for(int i = 0; i < LICZBAMLECZY; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new Mlecz(losowePolozenie.x, losowePolozenie.y, *this);
    }

    for(int i = 0; i < LICZBAGUARANY; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new Guarana(losowePolozenie.x, losowePolozenie.y, *this);
    }

    for(int i = 0; i < LICZBAWILCZYCHJAGOD; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new WilczeJagody(losowePolozenie.x, losowePolozenie.y, *this);
    }

    for(int i = 0; i < LICZBABARSZCZU; i++) {
        Wspolrzedne losowePolozenie = getWspolrzedneLosowegoPola();
        new BarszczSosnowskiego(losowePolozenie.x, losowePolozenie.y, *this);
    }
}
Organizm *** Swiat::generujPustySwiat() const {

    Organizm *** tab = new Organizm **[H];
    for ( int i = 0; i < H; ++i )
    {
        tab[i] = new Organizm *[W];
        for ( int j = 0; j < W; ++j)
            tab[i][j] = nullptr;
    }

    return tab;
}

Swiat::Swiat(int W, int H)
        : W(W), H(H), liczbaOrganizmow(0), czlowiek(nullptr)
{
    plansza = generujPustySwiat();
    srand(time(NULL));

    stworzOrganizmy();
}

void Swiat::rysujSwiat() {
    for (int i = 0; i < (H+2); ++i, cout<<endl )
        for ( int j = 0; j < (W+2); ++j) {
            if( i == 0 || i == H+1) j != W+1 ? cout << "----" : cout << "-";
            else if( j == 0 || j == W+1) cout << "|   ";
            else {
                if (plansza[i-1][j-1] == nullptr) {
                    cout << ".";
                }
                else {
                    plansza[i-1][j-1]->rysowanie();
                }
                cout << "   ";
            }
        }
}

Swiat::~Swiat() {
    for ( int i = 0; i < H; ++i ) {
        for ( int j = 0; j < W; ++j) {
            delete plansza[i][j];
        }
        delete[] plansza[i]; }
    delete [] plansza;
    plansza = nullptr;
}

void Swiat::dodajOrganizmNaPlansze(int x, int y, Organizm * organizm) {
    plansza[y][x] = organizm; //dodaje wskaznik na element do tablicy
}

void Swiat::usunOrganizmZPlanszy(int x, int y) {
    plansza[y][x] = nullptr;
}

void Swiat::dodajOrganizmyDoWektora() {

    int size = organizmyDoDodania.size();

    for (int i = 0; i < size; i++) {
        bool dodano = false;
        if(organizmy.empty()) organizmy.insert(organizmy.begin(), organizmyDoDodania[i]);
        else
        {
            int inicjatywaOrganizmu = organizmyDoDodania[i]->getInicjatywa();
            int organizmowWWektorze = organizmy.size();

            for(int j = 0; j < organizmowWWektorze; j++) {
                if(inicjatywaOrganizmu > organizmy[j]->getInicjatywa())
                {
                    organizmy.insert(organizmy.begin() + j, organizmyDoDodania[i]);
                    dodano = 1;
                    break;
                }
            }
            if(dodano == 0) organizmy.insert(organizmy.end(), organizmyDoDodania[i]);
        }
    }
    organizmyDoDodania.clear();
}

void Swiat::dodajOrganizmNaListeDoDodania(Organizm *organizm) {
    organizmyDoDodania.insert(organizmyDoDodania.end(), organizm);
}

void Swiat::wykonajTure() {
    dodajOrganizmyDoWektora();
    usunOrganizmyDoUsuniecia();
    pozwolWszystkimRuszyc();

    int organizmowWWektorze = organizmy.size();

    for (int i = 0; i < organizmowWWektorze; i++) {
        if (organizmy[i]->getMogeRuszyc()) {
            organizmy[i]->akcja();
        }
    }
    cout << endl;

}

int Swiat::getWidth() const {
    return W;
}

int Swiat::getHeight() const {
    return H;
}

Organizm *Swiat::getWskZPlanszy(int x, int y) {
    return plansza[y][x];
}

void Swiat::pozwolWszystkimRuszyc() {
    int organizmowWWektorze = organizmy.size();

    for (int i = 0; i < organizmowWWektorze; i++) {
        organizmy[i]->setMogeRuszyc(true);
    }
}

void Swiat::dodajOrganizmNaListeDoUsuniecia(Organizm *organizm) {
    organizmyDoUsuniecia.insert(organizmyDoUsuniecia.end(), organizm);
    organizm->setMogeRuszyc(false);
}

void Swiat::usunOrganizmyDoUsuniecia() {
    int size = organizmyDoUsuniecia.size();

    for (int i = 0; i < size; i++) {
        int size2 = organizmy.size();
        for (int j = 0; j < size2; j++) {
            if(organizmyDoUsuniecia[i] == organizmy[j]) {
                organizmy.erase(organizmy.begin() + j);
                delete organizmyDoUsuniecia[i];
                break;
            }
        }
    }

    organizmyDoUsuniecia.clear();
}

Wspolrzedne Swiat::getWspolrzedneLosowegoPola() {
    int x = rand() % getWidth();
    int y = rand() % getHeight();

    if(getWidth()*getHeight() <= organizmy.size()) return {0,0};

    while(plansza[y][x]!= nullptr) {
        x = rand() % getWidth();
        y = rand() % getHeight();
    }

    return {x, y};
}

int Swiat::getLiczbaOrganizmow() const {
    return liczbaOrganizmow;
}

void Swiat::zainkrementujLiczbeOrganizmow() {
    liczbaOrganizmow++;
}

void Swiat::setCzlowiek(Czlowiek *czlowiek) {
    this->czlowiek = czlowiek;
}

Czlowiek *Swiat::getCzlowiek() {
    return czlowiek;
}

void Swiat::zapiszDoPliku() {
    string nazwapliku;
    dodajOrganizmyDoWektora();
    usunOrganizmyDoUsuniecia();

    cout << "Wpisz nazwe pliku: ";
    cin >> nazwapliku;

    nazwapliku += ".txt";

    fstream plik;

    plik.open(nazwapliku, ios::trunc | ios::out | ios::in);
    if(plik.good()) {
        plik << H << " " << W << endl;

        for ( int i = 0; i < organizmy.size(); i++) {
            plik << organizmy[i]->obiektToString() << endl;
        }

        plik.close();
    }
    else cout << "Nie uzyskano destepu do pliku !!"<<endl;

}

Swiat::Swiat(string nazwaPliku) {
    srand(time(NULL));
    liczbaOrganizmow = 0;
    czlowiek = nullptr;
    fstream plik;
    string dane;
    string token;
    vector <string> tokeny;
    plik.open(nazwaPliku, ios::in);
    bool pierwszalinia = true;
    if(plik.good()) {
        while(getline(plik, dane)){
            stringstream check(dane);
            while (getline(check, token, ' ')) {
                tokeny.push_back(token);
            }
            if(pierwszalinia) { H = stoi(tokeny[0]); W = stoi(tokeny[1]); plansza = generujPustySwiat();}
            else {
                zrobObiektZTokenowZPliku(tokeny);
            }
            pierwszalinia = false;
            tokeny.clear();
        }
    }
}

void Swiat::zrobObiektZTokenowZPliku(vector<string> tokeny) {
    int x = stoi(tokeny[1]);
    int y = stoi(tokeny[2]);
    int sila = stoi(tokeny[3]);
    int inicjatywa = stoi(tokeny[4]);

    char symbol = tokeny[0][0];
    Organizm * wskNaOrganizm;
    switch(symbol) {
        case 'W':
            wskNaOrganizm = new Wilk(x, y, *this); break;
        case 'O':
            wskNaOrganizm = new Owca(x, y, *this); break;
        case 'L':
            wskNaOrganizm = new Lis(x, y, *this); break;
        case 'A':
            wskNaOrganizm = new Antylopa(x, y, *this); break;
        case 'Z':
            wskNaOrganizm = new Zolw(x, y, *this); break;
        case 'C':
            wskNaOrganizm = new Czlowiek(x, y, *this);
            czlowiek = (Czlowiek*)(Zwierze*)wskNaOrganizm;
            break;
        case 'T':
            wskNaOrganizm = new Trawa(x, y, *this); break;
        case 'M':
            wskNaOrganizm = new Mlecz(x, y, *this); break;
        case 'G':
            wskNaOrganizm = new Guarana(x, y, *this); break;
        case 'B':
            wskNaOrganizm = new BarszczSosnowskiego(x, y, *this); break;
        case 'J':
            wskNaOrganizm = new WilczeJagody(x, y, *this); break;
    }
    wskNaOrganizm->setSila(sila); wskNaOrganizm->setInicjatywa(inicjatywa);
}














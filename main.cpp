#include <iostream>
#include <conio.h>
#include "Swiat.h"
#include "zwierze/Czlowiek.h"

using namespace std;

int main() {

    int H = 20, W = 20;
    int keyCode = 0;

    cout << "Symulacja swiata" << endl;
    cout << "Wykonanie: Marek Brandt s184590" << endl << endl;
    cout << "Legenda: " << endl;
    cout << "   Zwierzeta:"<<endl;
    cout << "\tC - czlowiek, W - wilk, O - owca, L - lis, A - antylopa, Z - zolw"<<endl;
    cout << "   Rosliny: "<<endl;
    cout << "\tT - trawa, M - mlecz, G - guarana, J - wilcze jagody, B - barszcz sosnowskiego"<<endl<<endl;
    cout << "   Sterowanie:"<<endl;
    cout << "\tPoruszanie czlowieka za pomoca strzalek. Klawisz S to umiejetnosc specjalna. Klawisz Z zapis stanu gry"<<endl<<endl;
    cout << "Nacisnij dowolny znak zeby przejsc do menu";
    _getch();
    system("cls");

    cout << "\tMENU\n";
    cout << "1. Generuj losowy swiat" << endl;
    cout << "2. Otworz swiat z pliku" << endl;
    cout << "3. Zakoncz program" << endl;
    cin >> keyCode;

    Swiat * swiat;

    if (keyCode == 1)
    {
        cout << "Wprowadz wysokosc planszy: ";
        cin >> H;
        cout << "Wprowadz szerokosc planszy: ";
        cin >> W;
        system("cls");
        swiat = new Swiat(W, H);
    }
    else if (keyCode == 2){
        string nazwaPliku;
        cout << "Wprowadz nazwe pliku : ";
        cin >> nazwaPliku;
        nazwaPliku += ".txt";
        swiat = new Swiat(nazwaPliku);
    }
    else return 0;

    swiat->rysujSwiat();

    Czlowiek * czlowiek = swiat->getCzlowiek();

    while(keyCode != KB_ESCAPE) {

        keyCode = _getch();

        if(czlowiek != nullptr){
            if (keyCode == KB_DOWN || keyCode == KB_UP || keyCode == KB_RIGHT || keyCode == KB_LEFT
                 || keyCode == S_key || keyCode == s_key || keyCode == Z_key || keyCode == z_key) {
                switch (keyCode) {
                    case KB_LEFT:
                        czlowiek->setGdziePojdzie(wLewo);
                        break;
                    case KB_RIGHT:
                        czlowiek->setGdziePojdzie(wPrawo);
                        break;
                    case KB_UP:
                        czlowiek->setGdziePojdzie(wGore);
                        break;
                    case KB_DOWN:
                        czlowiek->setGdziePojdzie(wDol);
                        break;
                    case S_key:
                    case s_key:
                        czlowiek->setUmiejSpecjalna();
                        break;
                    case Z_key:
                    case z_key:
                        swiat->zapiszDoPliku();
                        break;
                    default:
                        break;
                }
                if (keyCode != Z_key && keyCode != z_key) {
                    swiat->wykonajTure();
                    swiat->rysujSwiat();
                }
            }
        }
        else {cout << "Wczytales stan symulacji bez czlowieka, symulacji nie mozna odtworzyc.\n"
                      "Mozna jedynie obejrzec plansze\nKliknij ESC by zakonczyc\n";}
    }

    return 0;
}

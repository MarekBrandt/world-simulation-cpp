#include "BarszczSosnowskiego.h"
#include "../../zwierze/Czlowiek.h"
#include <utility>

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat &swiat)
    :Roslina(x, y, swiat, "BarszczSosnowskiego", 10){
    setSymbol('B');
}

Organizm * BarszczSosnowskiego::stworzPotomka(int x, int y) {
    return new BarszczSosnowskiego(x, y, swiat);
}

void BarszczSosnowskiego::akcja() {
    vector <KierunekRuchu> wektorSasiadow = zwrocWektorDostepnychPol(getPozycja());

    int x = getPozycja().x;
    int y = getPozycja().y;
    int dx, dy;

    int size = wektorSasiadow.size();
    for ( int i = 0; i < size; i++) {
        dx = wektorPrzesuniecia(wektorSasiadow[i]).x;
        dy = wektorPrzesuniecia(wektorSasiadow[i]).y;

        Wspolrzedne wspSasiada(x + dx, y + dy);

        Organizm * wskNaSasiada = swiat.getWskZPlanszy(wspSasiada.x, wspSasiada.y);

        if(wskNaSasiada != nullptr && wskNaSasiada->getTyp() == "Zwierze" && wskNaSasiada->getNazwa() != "CyberOwca" && !(wskNaSasiada->getNazwa() == "Czlowiek" && swiat.getCzlowiek()->getAktywnoscSpecjalnej() == true)) {
            cout << this->getNazwa() << this->getId() << " zabija " << wskNaSasiada->getNazwa() << wskNaSasiada->getId() << endl;
            swiat.usunOrganizmZPlanszy( wspSasiada.x, wspSasiada.y);
            swiat.dodajOrganizmNaListeDoUsuniecia(wskNaSasiada);
        }
    }
    Roslina::akcja();
}

void BarszczSosnowskiego::kolizja(int x, int y, int xnast, int ynast) {
    Organizm * wskNaObiektKtoryWejdzie = swiat.getWskZPlanszy(x,y);
  
    if(wskNaObiektKtoryWejdzie->getNazwa() != "CyberOwca") {
        cout << wskNaObiektKtoryWejdzie->getNazwa() << wskNaObiektKtoryWejdzie->getId() << " ginie, bo zjadl "
             << this->getNazwa() << this->getId() << endl;
        swiat.dodajOrganizmNaListeDoUsuniecia(wskNaObiektKtoryWejdzie);
        swiat.usunOrganizmZPlanszy(x, y);
    }
    else {
        cout << wskNaObiektKtoryWejdzie->getNazwa() << wskNaObiektKtoryWejdzie->getId() << " idzie na (" << xnast << ","
        << ynast << ") i zjada " << this->getNazwa() << this->getId() << endl;
        wskNaObiektKtoryWejdzie->setPozycja(xnast, ynast);
        swiat.dodajOrganizmNaPlansze(x, y, wskNaObiektKtoryWejdzie);
    }
    swiat.usunOrganizmZPlanszy(xnast, ynast);
    swiat.dodajOrganizmNaListeDoUsuniecia(this);
}

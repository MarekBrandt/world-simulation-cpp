#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(int x, int y, Swiat &swiat)
    :Roslina(x, y, swiat, "Wilcza jagoda", 99){
    setSymbol('J');
}

Organizm * WilczeJagody::stworzPotomka(int x, int y) {
    return new WilczeJagody(x, y, swiat);
}

void WilczeJagody::kolizja(int x, int y, int xnast, int ynast) {
    Organizm * wskNaObiektKtoryWejdzie = swiat.getWskZPlanszy(x,y);
    cout << wskNaObiektKtoryWejdzie->getNazwa() << wskNaObiektKtoryWejdzie->getId() << " ginie, bo zjadl " << this->getNazwa() << this->getId() << endl;
    swiat.usunOrganizmZPlanszy(x, y);
    swiat.usunOrganizmZPlanszy(xnast, ynast);
    swiat.dodajOrganizmNaListeDoUsuniecia(wskNaObiektKtoryWejdzie);
    swiat.dodajOrganizmNaListeDoUsuniecia(this);
}

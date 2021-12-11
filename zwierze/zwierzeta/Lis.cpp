#include "Lis.h"


Lis::Lis(int x, int y, Swiat &swiat)
        :Zwierze(x, y, swiat, "Lis", 3, 7) {
    setSymbol('L');
}

Organizm *Lis::stworzPotomka(int x, int y) {
    return new Lis(x,y,swiat);
}

KierunekRuchu Lis::losujDostepneSasiedniePole(Wspolrzedne polozenie) {
    vector <KierunekRuchu> dostepnePola = zwrocWektorDostepnychPol(polozenie);
    vector <KierunekRuchu> polaDostepneDlaLisa;

    int size = dostepnePola.size();
    for ( int i = 0; i < size; i++) {
        Wspolrzedne przesuniecie = wektorPrzesuniecia(dostepnePola[i]);
        Organizm * tempOrganizm = swiat.getWskZPlanszy(polozenie.x + przesuniecie.x, polozenie.y + przesuniecie.y);
        if(tempOrganizm == nullptr || tempOrganizm->getSila() <= this->getSila()) {
            polaDostepneDlaLisa.insert(polaDostepneDlaLisa.begin(), dostepnePola[i]);
        }
    }

    if(polaDostepneDlaLisa.empty()) return zostan;

    size = polaDostepneDlaLisa.size();

    int ktorePole = rand() % size;

    return polaDostepneDlaLisa[ktorePole];
}



//
// Created by Dani on 2023. 11. 29..
//

#include "Szemely.h"

Szemely::Szemely(const string &vezetekNev, const string &keresztNev, int szuletesiEv) {
    this->vezetekNev = vezetekNev;
    this->keresztNev = keresztNev;
    this->szuletesiEv = szuletesiEv;

}

void Szemely::print(ostream &os)const {
    os << "vezetekNev: " << this->vezetekNev << "\n" << "keresztNev: " << this->keresztNev << "\n" << "szuletesiEv: " << this->szuletesiEv << endl;

}

ostream &operator<<(ostream &os, const Szemely &szemely) {
    szemely.print(os);
    return os;
}

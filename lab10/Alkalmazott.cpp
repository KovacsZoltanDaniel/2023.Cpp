//
// Created by Dani on 2023. 11. 29..
//

#include "Alkalmazott.h"
int Alkalmazott::counter = 0;
Alkalmazott::Alkalmazott(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor)
        : Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor),id(++counter) {}

void Alkalmazott::print(ostream &os)const {
    Szemely::print(os);
    os << this->munkakor << endl;
}

int Alkalmazott::getId() const {
    return id;
}

const string &Alkalmazott::getMunkakor() const {
    return munkakor;
}

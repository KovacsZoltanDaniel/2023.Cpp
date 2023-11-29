//
// Created by Dani on 2023. 11. 29..
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H
#include <iostream>
#include <string>
#include "Szemely.h"
using namespace std;

class Alkalmazott : public Szemely {
protected:
    int id;
    static int counter;
    string munkakor;
public:
    int getId() const;
    Alkalmazott(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor);
    virtual void print(ostream &os)const override;

};


#endif //CPP_2022_ALKALMAZOTT_H

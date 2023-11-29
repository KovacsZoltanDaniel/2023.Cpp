//
// Created by Dani on 2023. 11. 29..
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H
#include <iostream>
#include <string>
#include "Alkalmazott.h"
#include <vector>
using namespace std;

class Manager : public Alkalmazott {
private:
    vector<Alkalmazott*> beosztottak;

public:
    Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor);
    void addBeosztott(Alkalmazott *beosztott);
    void deleteBeosztott(int id);
    int getBeosztottakSzama() const;
    virtual void print(ostream &os)const override;
    static const string MANAGER_MUNKAKOR ;
};


#endif //CPP_2022_MANAGER_H

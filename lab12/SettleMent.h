//
// Created by Dani on 2023. 12. 13..
//

#ifndef CPP_2022_SETTLEMENT_H
#define CPP_2022_SETTLEMENT_H
#include <string>
#include <iostream>

using namespace std;

class SettleMent {
    string name = "";
    string county = "";
    int population = 0;
// constructor, getters, setters, inserter operator
public:
    SettleMent(const string &name, const string &county, int population);

    const string &getName() const;

    const string &getCounty() const;

    int getPopulation() const;

    void setName(const string &name);

    void setCounty(const string &county);

    void setPopulation(int population);

    friend ostream &operator<<(ostream &os, const SettleMent &ment);
};



#endif //CPP_2022_SETTLEMENT_H

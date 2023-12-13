//
// Created by Dani on 2023. 12. 13..
//

#include "SettleMent.h"

SettleMent::SettleMent(const string &name, const string &county, int population) : name(name), county(county),
                                                                                   population(population) {}

const string &SettleMent::getName() const {
    return name;
}

const string &SettleMent::getCounty() const {
    return county;
}

int SettleMent::getPopulation() const {
    return population;
}

void SettleMent::setName(const string &name) {
    SettleMent::name = name;
}

void SettleMent::setCounty(const string &county) {
    SettleMent::county = county;
}

void SettleMent::setPopulation(int population) {
    SettleMent::population = population;
}

ostream &operator<<(ostream &os, const SettleMent &ment) {
    os << "name: " << ment.name << " county: " << ment.county << " population: " << ment.population;
    return os;
}

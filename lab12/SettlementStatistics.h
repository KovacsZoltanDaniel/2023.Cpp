//
// Created by Dani on 2023. 12. 13..
//

#ifndef CPP_2022_SETTLEMENTSTATISTICS_H
#define CPP_2022_SETTLEMENTSTATISTICS_H

#include <iostream>
#include <vector>
#include "SettleMent.h"
using namespace std;

#include "SettleMent.h"

struct SettlementStatistics {
    virtual int numSettlements() const = 0;

    virtual int numCounties() const = 0;

    virtual int numSettlementsByCounty(const string &county) const = 0;

    virtual vector <SettleMent> findSettlementsByCounty(
            const string &county) const = 0;

    virtual SettleMent findSettlementsByNameAndCounty(
            const string &name, const string &county) const = 0;

    virtual SettleMent maxPopulation() const = 0;

    virtual SettleMent minPopulation() const = 0;

    virtual vector <SettleMent> findSettlementsByName(
            const string &name) = 0;
};


#endif //CPP_2022_SETTLEMENTSTATISTICS_H

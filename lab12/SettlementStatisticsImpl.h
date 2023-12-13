//
// Created by Dani on 2023. 12. 13..
//

#ifndef CPP_2022_SETTLEMENTSTATISTICSIMPL_H
#define CPP_2022_SETTLEMENTSTATISTICSIMPL_H

#include <map>
#include "SettleMent.h"
#include "SettlementStatistics.h"

class SettlementStatisticsImpl : public SettlementStatistics {
private:
    multimap<string, SettleMent> settlements;
public:
    explicit SettlementStatisticsImpl(const string &filename);

    int numSettlements() const override;

    int numCounties() const override;

    int numSettlementsByCounty(const string &county) const override;

    vector<SettleMent> findSettlementsByCounty(const string &county) const override;

    SettleMent findSettlementsByNameAndCounty(const string &name, const string &county) const override;

    SettleMent maxPopulation() const override;

    SettleMent minPopulation() const override;

    vector<SettleMent> findSettlementsByName(const string &name) override;
};


#endif //CPP_2022_SETTLEMENTSTATISTICSIMPL_H

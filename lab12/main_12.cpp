#include <iostream>
#include "SettlementStatisticsImpl.h"
#include "SettleMent.h"
#include "SettlementStatistics.h"
int main() {
    SettlementStatistics *statistics = new SettlementStatisticsImpl("telepulesek.csv");
    cout << statistics->numSettlementsByCounty("AB") << endl;
    return 0;
}
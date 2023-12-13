//
// Created by Dani on 2023. 12. 13..
//

#include <fstream>
#include <sstream>
#include "SettlementStatisticsImpl.h"

int SettlementStatisticsImpl::numSettlements() const {
    return this->settlements.size();

}

int SettlementStatisticsImpl::numCounties() const {
    string x = "";
    int result = 0;
    for(auto &[key, value] : this->settlements){
        if (x != key){
            result++;
            x = key;
        }
    }
    return result;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return this->settlements.count(county);
}

vector<SettleMent> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<SettleMent> result;
    for(auto it = settlements.lower_bound(county); it != settlements.upper_bound(county); ++it){
        result.push_back(it->second);
    }
    return result;
}

SettleMent SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for(auto it = settlements.lower_bound(county); it != settlements.upper_bound(county); ++it){
        if ( it->second.getName() == name){
            return it->second;
        }
    }
    throw runtime_error("Settlement not found");
}

SettleMent SettlementStatisticsImpl::maxPopulation() const {
    const SettleMent *max = &settlements.begin()->second;
    for(auto &[key, value] : this->settlements){
       if (value.getPopulation() > max->getPopulation()){
           max = &value;
       }
    }
     return *max;
}

SettleMent SettlementStatisticsImpl::minPopulation() const {
    const SettleMent *min = &settlements.begin()->second;
    for(auto &[key, value] : this->settlements){
        if (value.getPopulation() < min->getPopulation()){
            min = &value;
        }
    }
    return *min;
}

vector<SettleMent> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<SettleMent> result;
    for(auto &[key, value] : this->settlements){
        if (value.getName() == name){
            result.push_back(value);
        }
    }
    return result;
}

SettlementStatisticsImpl::SettlementStatisticsImpl(const string &filename) {
    ifstream file(filename);
    if(!file){
        throw runtime_error("Cannot open file");
    }
    string line;
    getline(file, line);
    while(getline(file, line)){
        stringstream ss(line);
        string name;
        string county;
        string population;
        getline(ss, name, ',');
        getline(ss, county, ',');
        getline(ss, population);
        if(population.empty()){
            population = "0";
        }
        this->settlements.insert(pair(county, SettleMent(name, county, stoi(population))));
    }
}


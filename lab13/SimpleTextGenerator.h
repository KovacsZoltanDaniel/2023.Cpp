//
// Created by Dani on 2023. 12. 20..
//

#ifndef CPP_2022_SIMPLETEXTGENERATOR_H
#define CPP_2022_SIMPLETEXTGENERATOR_H

#include <vector>
#include <map>
#include <string>
#include "TextGenerator.h"
class SimpleTextGenerator: public TextGenerator {
    map<string, vector<string>> data;
public:
    void trainFromText(string trainingText) override;
    void trainFromFile(string filename) override;
    string generate(string startWords, int numWords=6) override;
    void printData() const; // a map kiíratása
};

#endif //CPP_2022_SIMPLETEXTGENERATOR_H

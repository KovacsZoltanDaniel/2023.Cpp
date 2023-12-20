//
// Created by Dani on 2023. 12. 20..
//

#ifndef CPP_2022_TEXTGENERATOR_H
#define CPP_2022_TEXTGENERATOR_H
using namespace std;
#include <string>

class TextGenerator {
public:
    virtual void trainFromText(string trainingText) = 0;
    virtual void trainFromFile(string filename) = 0;
    virtual string generate(string startWords, int numWords=10) = 0;
    virtual ~TextGenerator() = default;
};

#endif //CPP_2022_TEXTGENERATOR_H

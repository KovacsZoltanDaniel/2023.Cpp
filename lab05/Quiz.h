//
// Created by Dani on 2023. 10. 25..
//

#ifndef CPP_2022_QUIZ_H
#define CPP_2022_QUIZ_H

using namespace std;
#include <iostream>
#include "Question.h"

class Quiz {
private:
    const string name;
    vector<Question> questions;
public:
    Quiz(const string &name, const vector<Question> &questions);
    explicit Quiz(const string &name);
    const string &getName() const;
    vector<Question> &getQuestions();
    void readFromFile(string FileName);
};


#endif //CPP_2022_QUIZ_H

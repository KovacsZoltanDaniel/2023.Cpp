//
// Created by Dani on 2023. 10. 25..
//

#include <fstream>
#include <sstream>
#include "Quiz.h"

Quiz::Quiz(const string &name, const vector<Question> &questions) : name(name), questions(questions) {}

Quiz::Quiz(const string &name) : name(name) {}

const string &Quiz::getName() const {
    return name;
}


 vector<Question> &Quiz::getQuestions() {
    return questions;
}
void Quiz::readFromFile(string FileName) {
    ifstream f(FileName);
    string line;
    if (!f) {
        throw runtime_error("error when opening file!");
    }
    while(getline(f,line)){
        if(line[0] == 'Q' && line[1] == ' '){
            questions.emplace_back(line.substr(2)); // 2. poziciotol a vegeig vegye
            continue;
        }
        if(line[0] == 'A' && line[1] == ' '){
            questions.back().getAnswers().emplace_back(line.substr(2));
            continue;
        }
        stringstream s(line);
        while(true){
            int n;
            s >> n;
            if(!s){
                break;
            }
            questions.back().getAnswers()[n-1].setCorrect(true);
        }
    }

}

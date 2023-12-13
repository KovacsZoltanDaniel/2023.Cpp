//
// Created by Dani on 2023. 12. 13..
//

#ifndef CPP_2022_STUDENTSERVICE_H
#define CPP_2022_STUDENTSERVICE_H

#include <string>
#include <vector>

using namespace std;

class StudentService {
public:
    virtual bool isEnrolled(int id) const = 0;
    virtual double getResultBySubject(int id, const string& subject) const = 0;
    virtual double getAverage(int id) const = 0;
    virtual bool isPassed(int id) const = 0;
    virtual vector<string> getSubjects(int id) const = 0;
};

#endif //CPP_2022_STUDENTSERVICE_H

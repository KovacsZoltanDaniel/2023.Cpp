//
// Created by Dani on 2023. 12. 13..
//

#ifndef CPP_2022_STUDENT_H
#define CPP_2022_STUDENT_H


#include <string>
#include <map>

using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:
    Student(int id, const string &firstName, const string &lastName);
    int getId() const {
        return id;
    }
    void setId(int id);
    const string &getFirstName()const {
        return firstName;
    }
    const string &getLastName() const {
        return lastName;
    }
    void addGrade(const string& subject, double grade);
// throws out_of_range exception for nonexistent subject
    double getGrade(const string& subject) const;
    const map<string, double> &getGrades() const {
        return grades;
    }
    void computeAverage();
    double getAverage() const {
        return average;
    }
    friend ostream& operator<<(ostream& os, const Student& student);
};


#endif //CPP_2022_STUDENT_H

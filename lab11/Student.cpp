//
// Created by Dani on 2023. 12. 13..
//


#include "Student.h"
#include <stdexcept>
#include <iostream>

Student::Student(int id, const string &firstName, const string &lastName) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

void Student::setId(int id) {
    this->id = id;
}

void Student::addGrade(const string &subject, double grade) {
    grades[subject] = grade;
}

double Student::getGrade(const string &subject) const {
    if (grades.find(subject) == grades.end()) {
        throw out_of_range("Subject not found");
    }
    return grades.at(subject);
}

void Student::computeAverage() {
    for (const auto &grade : grades) {
        if (grade.second < 5) {
            average = 0;
            return;
        }
    }

    double sum = 0;
    for (const auto &grade : grades) {
        sum += grade.second;
    }
    average = sum / grades.size();
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.id << ", " << student.firstName << " " << student.lastName << ", avg: " <<  student.average << ", ";
    os << "grades: ";
    for (const auto &grade : student.grades) {
        os << grade.first << ": " << grade.second << " ";
    }
    return os;
}

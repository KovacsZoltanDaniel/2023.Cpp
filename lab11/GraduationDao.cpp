//
// Created by Dani on 2023. 12. 13..
//

#include "GraduationDao.h"

#include <fstream>
#include <iostream>

using namespace std;

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Failed to open file" << endl;
        exit(1);
    }

    int id;
    string firstName;
    string lastName;
    while (file >> id) {
        file >> firstName;
        file >> lastName;
        Student student(id, firstName, lastName);
        students.insert(make_pair(id, student));
    }

    file.close();
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Failed to open file" << endl;
        exit(1);
    }

    int id;
    double grade;
    while (file >> id) {
        file >> grade;
        try {
            students.at(id).addGrade(subject, grade);
        } catch (const out_of_range &e) {
            cout << "Invalid ID: "<< id << endl;
        }
    }

    file.close();

}

void GraduationDao::computeAverage() {
    for (auto &student: students) {
        student.second.computeAverage();
    }
}

int GraduationDao::numPassed() const {
    int count = 0;
    for (auto &student: students) {
        if (student.second.getAverage() >= 6) {
            count++;
        }
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    try {
        return students.at(id);
    } catch (const out_of_range &e) {
        throw runtime_error("Invalid ID");
    }
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0;
    int count = 0;
    for (auto &student: students) {
        sum += student.second.getGrade(subject);
        count++;
    }
    return sum / count;
}

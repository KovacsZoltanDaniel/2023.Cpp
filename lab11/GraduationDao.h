//
// Created by Dani on 2023. 12. 13..
//

#ifndef CPP_2022_GRADUATIONDAO_H
#define CPP_2022_GRADUATIONDAO_H


#include "Student.h"

class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}
    void enrollStudents(const string &filename);
    void saveGradesForSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const {
        return students.size();
    }
    int numPassed() const;
// throws out_of_range exception for nonexistent id
    Student findById(int id) const;
    double getAverageBySubject(const string &subject) const;
};

#endif //CPP_2022_GRADUATIONDAO_H

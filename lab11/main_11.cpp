#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
#include "StudentService.h"
#include "StudentServiceImpl.h"
#include <vector>

int main() {
    /*
    Student student(1, "Saul", "Goodman");
    student.addGrade("maths", 10);
    student.addGrade("romanian", 7.5);
    student.addGrade("hungarian", 8);
    cout << "Saul Goodman's math grade: " << student.getGrade("maths");
    cout << endl;
    student.computeAverage();
    cout << student << endl;
*/

    vector<string> subjects = {"math", "romanian", "hungarian"};
    const int numSubjects = subjects.size();

    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
        dao.saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;

    StudentService* service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id=" << id << " not found" << endl;
            continue;
        }
        cout << "Student id=" << id << " results: " << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }

        vector<string> subjects2 = service->getSubjects(id);
        for (int i = 0; i < subjects2.size(); ++i) {
            cout << "\t" << subjects2[i] << ": " <<
                 service->getResultBySubject(id, subjects2[i]) << endl;
        }
        cout << "\taverage: " << service->getAverage(id) << endl;
    }
    delete service;

    return 0;
}
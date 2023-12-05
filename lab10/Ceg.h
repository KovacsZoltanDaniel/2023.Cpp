//
// Created by kovac on 2023. 12. 05..
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H


#include "Manager.h"
#include <string>

class Ceg {
protected:
    vector<Alkalmazott*> alkalmazottak;
    string companyName;
public:
    Ceg(const string& companyName);
    void addNewEmployee(Alkalmazott *alkalmazott);
    void fireEmployee(int id);
    void assignEmployeeToManager(Manager &manager, Alkalmazott &alkalmazott);
    void detachEmployeeFromManager(Manager &manager, Alkalmazott &alkalmazott);
    void printAllEmployees() const;
    void printOnlyManagers() const;
};


#endif //CPP_2022_CEG_H

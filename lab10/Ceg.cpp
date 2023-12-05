//
// Created by kovac on 2023. 12. 05..
//

#include "Ceg.h"

#include <algorithm>
#include <iostream>

Ceg::Ceg(const string& companyName) {
    this->companyName = companyName;
}

void Ceg::addNewEmployee(Alkalmazott *alkalmazott) {
    this->alkalmazottak.push_back(alkalmazott);
}

void Ceg::fireEmployee(int id) {
    for (auto alkalmazott : alkalmazottak) {
        if (alkalmazott->getId() == id) {
            alkalmazottak.erase(std::remove(alkalmazottak.begin(), alkalmazottak.end(), alkalmazott), alkalmazottak.end());
        }
    }
}

void Ceg::assignEmployeeToManager(Manager &manager, Alkalmazott &alkalmazott) {
    manager.addBeosztott(&alkalmazott);
}

void Ceg::detachEmployeeFromManager(Manager &manager, Alkalmazott &alkalmazott) {
    manager.deleteBeosztott(alkalmazott.getId());
}

void Ceg::printAllEmployees() const {
    cout << "\nEmployees: " << endl;
    for (auto alkalmazott : alkalmazottak) {
        cout  << *alkalmazott;
    }
}

void Ceg::printOnlyManagers() const {
    cout << "\nManagers: " << endl;
    for (auto alkalmazott : alkalmazottak) {
        if (alkalmazott->getMunkakor() == Manager::MANAGER_MUNKAKOR) {
            cout << "\t" << *alkalmazott << endl;
        }
    }
}
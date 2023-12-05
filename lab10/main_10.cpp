#include <iostream>
#include "Manager.h"
#include "Alkalmazott.h"
#include "Ceg.h"

int main() {
    Ceg ceg("myCompany");

    Alkalmazott a1 ("John", "Doe", 1990, "IT");
    Alkalmazott a2 ("Jane", "Smith", 1982, "IT");
    Alkalmazott a3 ("Bob", "Johnson", 1988, "IT");
    Alkalmazott a4 ("Emily", "Williams", 1993, "IT");
    Alkalmazott a5 ("Michael", "Brown", 1987, "IT");
    Manager a6 ("Emma", "Jones", 1995,"manager");
    Alkalmazott a7 ("William", "Davis", 1984, "IT");
    Manager a8 ("Olivia", "Miller", 1992,"manager");
    Manager a9 ("Daniel", "Wilson", 1989,"manager");
    Alkalmazott a10 ("Sophia", "Taylor", 1991, "IT");



    ceg.addNewEmployee(&a1);
    ceg.addNewEmployee(&a2);
    ceg.addNewEmployee(&a3);
    ceg.addNewEmployee(&a4);
    ceg.addNewEmployee(&a5);
    ceg.addNewEmployee(&a6);
    ceg.addNewEmployee(&a7);
    ceg.addNewEmployee(&a8);
    ceg.addNewEmployee(&a9);
    ceg.addNewEmployee(&a10);

    ceg.printAllEmployees();

    ceg.assignEmployeeToManager(a6, a1);
    ceg.assignEmployeeToManager(a6, a3);
    ceg.assignEmployeeToManager(a6, a5);

    ceg.assignEmployeeToManager(a8, a10);
    ceg.assignEmployeeToManager(a8, a7);

    ceg.assignEmployeeToManager(a9, a4);
    ceg.assignEmployeeToManager(a9, a2);

    ceg.printOnlyManagers();

    cout << "Move employee Michael Brown from manager Emma Jones to manager Daniel Wilson: " << endl;
    ceg.detachEmployeeFromManager(a6, a5);
    ceg.assignEmployeeToManager(a9, a5);
    ceg.printOnlyManagers();

    return 0;
}
#include <iostream>
#include "Manager.h"
#include "Szemely.h"
#include "Alkalmazott.h"

int main() {
    Szemely *s = new Szemely("John", "Doe", 1990);
    Szemely *a = new Alkalmazott("Jane", "David", 1995, "IT");
    Szemely *m = new Manager("Jane", "Michael", 1990, "IT");
    s->print(cout);
    a->print(cout);
    m->print(cout);
    delete s;
    delete a;
    delete m;
    return 0;
}
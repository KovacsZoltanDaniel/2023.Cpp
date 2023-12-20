using namespace std;
#include <iostream>
#include "SimpleTextGenerator.h"
int main() {
    SimpleTextGenerator simpleTextGenerator;
    simpleTextGenerator.trainFromFile("bible.txt");
//    for (int i = 0; i < 10; ++i) {
//     cout << simpleTextGenerator.generate("earth bring",10) << endl;
//    }
    simpleTextGenerator.printData();
   // delete simpleTextGenerator;
    return 0;
}
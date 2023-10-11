
#include "List.h"
#include "Stack.h"
using namespace std;

int main() {

    /*
    List lista;
    lista.insertFirst(11);
    lista.insertFirst(100);
    lista.insertFirst(9);
    lista.insertFirst(66);
    lista.insertFirst(5);
    lista.print();

    lista.removeFirst();
    lista.print();

    lista.remove(50, List::DeleteFlag::LESS);
    lista.print();

    lista.remove(50, List::DeleteFlag::GREATER);
    lista.print();

    lista.remove(50, List::DeleteFlag::EQUAL);
    lista.print();

    lista.removeFirst();
    lista.removeFirst();
    lista.removeFirst();
    lista.print();*/

    Stack stack;
    stack.push(2);
    stack.push(5);
    stack.pop();
    stack.push(15);
    stack.printStack();
    return 0;
}

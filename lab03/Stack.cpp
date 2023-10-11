//
// Created by Dani on 2023. 10. 11..
//
#include <iostream>
using namespace std;
#include "Stack.h"

void Stack::push(int e) {
    list.insertFirst(e);
}

int Stack::pop() {
    return list.removeFirst();
}

bool Stack::isEmpty() const {
    return list.empty();
}

Stack::Stack() {
    cout << "Stack created" << endl;
}

void Stack::printStack() {
    list.print();
}

Stack::~Stack() {
    cout << "Stack destroyed" << endl;
}

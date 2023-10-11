//
// Created by Dani on 2023. 10. 11..
//

#include <stdexcept>
#include "List.h"
#include <iostream>
using namespace std;

List::List() {
    cout << "List created" << endl;
    this->first = nullptr;
}

List::~List() {
    cout << "List destroyed" << endl;
    while (first != nullptr) {
        Node *tmp = first;
        first = first->next;
        delete tmp;
    }
}

bool List::exists(int d) const {
    for (Node *n = first; n != nullptr; n = n->next) {
        if (n->value == d) {
            return true;
        }
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return first == nullptr;
}

void List::insertFirst(int d) {
    this->first = new Node(d, this->first);
    nodeCounter++;
}

int List::removeFirst() {
    if(first == nullptr){
        throw runtime_error("List is empty");
    }
    Node *tmp = this->first;
    int value = tmp->value;
    this->first = first->next;
    delete tmp;
    return value;
}

void List::remove(int d, List::DeleteFlag df) {
    Node * prev = nullptr;
    for(auto n = first; n != nullptr; n = n->next){
        if((n->value == d && df == DeleteFlag::EQUAL) || (n->value > d && df == DeleteFlag::GREATER) || (n->value < d && df == DeleteFlag::LESS)){
            if(prev == nullptr){
                removeFirst();
                return;
            }
            prev->next = n->next;
            delete n;
            nodeCounter--;
            return;
        }
        prev = n;
        }
    }

void List::print() const {
    for (Node *n = first; n != nullptr; n = n->next) {
        if(n != first){
            cout << ", ";
        }
        cout << n->value;
    }
    cout << endl;
}


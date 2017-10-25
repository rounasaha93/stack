//
// Created by Rounak on 18/10/17.
//


#ifndef STACK_STACKBYINHERITENCE_H
#define STACK_STACKBYINHERITENCE_H


#include "LinearList.h"

#include <iostream>

using namespace std;

template<class T>
class StackByInheritence : private LinearList<T> {
public:
    //Constructor
    StackByInheritence(int maxSize) : LinearList<T>(maxSize) {}

    bool isEmpty() {
        return LinearList<T>::isEmpty();
    }

    bool isFull() {
        return LinearList<T>::lengthOfList() == LinearList<T>::getMaxSize();
    }

    T Top(T &x) {
        if (!isEmpty()) {
            LinearList<T>::findElement(LinearList<T>::lengthOfList(), x);
        } else {
            cout << "Stack is empty. Please insert and try again!" << endl;
            return INT_MIN;
        }
    }

    StackByInheritence<T> &Push(const T &x) {
        if (!isFull()) {
            LinearList<T>::Insert(LinearList<T>::lengthOfList(), x);
            return *this;
        } else {
            cout << "Stack is full. Please delete and try again!" << endl;
            return *this;
        }
    }

    StackByInheritence<T> &Pop(T &x) {
        if (!isEmpty()) {
            LinearList<T>::Delete(LinearList<T>::lengthOfList(), x);
            return *this;
        } else {
            cout << "Stack is empty. Please insert and try again!" << endl;
            return *this;
        }
    }

};


#endif //STACK_STACKBYINHERITENCE_H

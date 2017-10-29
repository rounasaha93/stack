//
// Created by Rounak on 29/10/17.
//

#ifndef STACK_STACKBYLL_H
#define STACK_STACKBYLL_H



#include "LinkedListChain.h"

template<class T>
class StackByLL : private LinkedListChain<T> {
public:
    bool isEmpty() {
        return LinkedListChain<T>::isEmpty();
    }

    T Top(T &x) {
        if (!isEmpty()) {
            LinkedListChain<T>::find(LinkedListChain<T>::length(), x);
        } else {
            cout << "Stack is empty. Please insert and try again!" << endl;
            return INT_MIN;
        }
    }

    StackByLL<T> &Push(const T &x) {
        LinkedListChain<T>::Insert(LinkedListChain<T>::length(), x);
        return *this;
    }

    StackByLL<T> &Pop(T &x) {
        if (!isEmpty()) {
            LinkedListChain<T>::Delete(LinkedListChain<T>::length()-1, x);
            return *this;
        } else {
            cout << "Stack is empty. Please insert and try again!" << endl;
            return *this;
        }
    }

};




#endif //STACK_STACKBYLL_H

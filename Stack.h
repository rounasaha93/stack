//
// Created by Rounak on 18/10/17.
//

#ifndef STACK_LINEARLIST_H
#define STACK_LINEARLIST_H

#include<iostream>

using namespace std;

template<class T>
class Stack {
private :
    int top;
    T *elements;
    int MaxSize;
public :

    Stack(int MaxSize);

    ~Stack() { delete[] elements; }

    bool isEmpty() const { return top == -1; }

    bool isFull() const { return top == MaxSize; }

    Stack<T> &push(const T &x);

    Stack<T> &pop(T &x);

    T topOfStack();

    void OutputStream(ostream &out) const;
};

template<class T>
Stack<T>::Stack(int MaxSize) {
    MaxSize = MaxSize;
    top = -1;
    elements = new T[MaxSize];
}

template<class T>
Stack<T> &Stack<T>::push(const T &x) {
    //Check if Stack is full
    if (!isFull()) {
        ++top;
        elements[top] = x;
        return *this;
    } else {
        cout << "Stack is full. Please delete item to try again!" << endl;
        return *this;
    }
}

template<class T>
Stack<T> &Stack<T>::pop(T &x) {
    //Check if Stack is empty
    if (!isEmpty()) {
        x = elements[top];
        top--;
        return *this;
    } else {
        cout << "Stack is empty. Please insert item to try again!" << endl;
        return *this;
    }
}

template<class T>
T Stack<T>::topOfStack() {
    if (!isEmpty()) {
        return elements[top];
    } else {
        cout << "Stack is empty. Please insert item to try again!" << endl;
        return INT_MIN;
    }

}

template<class T>
void Stack<T>::OutputStream(ostream &out) const {
    for (int i = 0; i <= top; i++) {
        out << elements[i] << " ";
    }
}


#endif //STACK_LINEARLIST_H

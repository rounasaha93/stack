//
// Created by Rounak on 14/10/17.
//

#ifndef CPLUSPLUSTUTS_LINEARLIST_H
#define CPLUSPLUSTUTS_LINEARLIST_H

#include <iostream>

using namespace std;

template<class T>
class LinearList {
public:
    LinearList(int MaxSize = 10);   //Constructor To Initialise Value of The List

    ~LinearList() { delete[] elements; };   //Destructor To Delete the List

    bool isEmpty() const {
        return length == 0;
    }   //Method to return TRUE if List is Not Empty and the Converse Otherwise

    int lengthOfList() const { return length; }

    LinearList<T> &Insert(int k,
                          const T &x);   //Method to INSERT element to the List. Insertion will be after position k with value x

    LinearList<T> &
    Delete(int k, T &X);   //Method to DELETE element at position k in the list and return the deleted value in x

    bool findElement(int k, T &x) const;  //Method to find element at position K & return the Value in X

    int search(const T &x) const; //Find element X in the list and return position k

    void OutputStream(ostream &out) const;    //To Print the List

    void deleteDuplicates();    //Deletes all Duplicate Elements in the List

    int getMaxSize() { return size; }


private :
    int size;
    T *elements;
    int length;
};

//CONSTRUCTOR
template<class T>
LinearList<T>::LinearList(int MaxSize) {
    size = MaxSize;
    elements = new T[MaxSize];
    length = 0;
}

//INSERTION
template<class T>
LinearList<T> &LinearList<T>::Insert(int k, const T &x) {
    if (k < 0 || k > length) {
        cout << "Index is out of Bounds. Please try again !" << endl;
        return *this;
    }
    if (length == size) {
        cout << "List is Full. Please Delete an element to insert !" << endl;
        return *this;
    }
    for (int i = length - 1; i >= k; i--) {
        elements[i + 1] = elements[i];
    }
    elements[k] = x;
    length++;
    return *this;
}

//DELETE ELEMENT
template<class T>
LinearList<T> &LinearList<T>::Delete(int k, T &x) {
    if (findElement(k, x)) {
        for (int i = k; i < length; i++) {
            elements[i - 1] = elements[i];
        }
        length--;
        return *this;
    } else {
        cout << "Out of Bounds" << endl;
        return *this;
    }
}

//OUTPUTTING THE LIST
template<class T>
void LinearList<T>::OutputStream(ostream &out) const {
    for (int i = 0; i < length; i++) {
        out << elements[i] << " ";
    }
}

//FINDING AN ELEMENT IN  THE LIST
template<class T>
bool LinearList<T>::findElement(int k, T &x) const {
    if (k < 1 || k > length) {
        return false;
    } else {
        x = elements[k - 1];
        return true;
    }
}

//FINDING AN ELEMENT X IN THE LIST TO RETURN POSITION K
template<class T>
int LinearList<T>::search(const T &x) const {
    for (int i = 0; i < length; i++) {
        if (elements[i] == x) {
            return ++i;
        }
    }
    return 0;
}

//DELETION OF DUPLICATE ITEMS IN THE LIST
template<class T>
void LinearList<T>::deleteDuplicates() {
    int deleteValue;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (elements[i] == elements[j]) {
                Delete(j, deleteValue);
            }
        }
    }
}


#endif //CPLUSPLUSTUTS_LINEARLIST_H

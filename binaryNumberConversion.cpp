//
// Created by Rounak on 25/10/17.
//

#include "StackByInheritence.h"
#include <iostream>

using namespace std;

void binaryConversion(int n) {
    StackByInheritence<int> stack(100);
    //Insert Into Stack the Binary Equivalents
    while (n >= 1) {
        if (!stack.isFull()) {
            stack.Push(n % 2);
            n /= 2;
        } else {
            cout << "Number is TOO Large !. Please try with a shorted number" << endl;
            return;
        }
    }
    //Display in Reverse Order
    while (!stack.isEmpty()) {
        int popDigit;
        stack.Pop(popDigit);
        cout << popDigit << " ";
    }
    cout << endl;
}

int main() {
    int decimal;
    cout << "Enter a Decimal Number : ";
    cin >> decimal;
    if (decimal > 0) {
        cout << "The Binary Equivalen is : ";
        binaryConversion(decimal);
        cout << endl;
    } else {
        cout << "The number is not positive !" << endl;
    }
    return 0;
}
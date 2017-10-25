//
// Created by Rounak on 25/10/17.
//

#include <iostream>
#include "StackByInheritence.h"

bool checkSwitchBox(int pinString[], int n) {
    int topOfStack, valueDeleted;
    StackByInheritence<int> stack(n);
    for (int i = 0; i < n; i++) {
        if (!stack.isEmpty()) {
            //Check if Value of Top of Stack is Same as the value to be inserted
            stack.Top(topOfStack);
            /*DEBUG STATEMENT
             * cout << "Top Of Stack : " << topOfStack << endl;*/
            if (topOfStack == pinString[i]) {
                stack.Pop(valueDeleted);
                /*DEBUG STATEMENT
                 * cout << "Deleting value : " << valueDeleted << endl;*/
            } else {
                /*DEBUG STATEMENT
                 * cout << "Inserting value : " << pinString[i] << endl;*/
                stack.Push(pinString[i]);
            }
        } else {
            /*DEBUG STATEMENT
             * cout << "Inserting value : " << pinString[i] << endl;
             */
            stack.Push(pinString[i]); //First Time Insertion Value
        }
    }
    //Final Check to see if Stack is Empty
    if (stack.isEmpty()) {
        return true;
    }
    return false;
}

int main_off3() {
    int noPins;
    cout << "Enter the no of pins : ";
    cin >> noPins;
    int pinString[noPins];  //Note to beginners : Be Careful while initialising this array. Ensure it is done after you take noPins as input as C++ compiles in TOP DOWN fashion
    cout << "Please input the Pin String : ";
    for (int i = 0; i < noPins; i++) {
        cin >> pinString[i];
    }

    if (checkSwitchBox(pinString, noPins)) {
        cout << "Switch Box CAN be routed !" << endl;
    } else {
        cout << "Switch Box CANNOT be routed !" << endl;
    }
    return 0;
}
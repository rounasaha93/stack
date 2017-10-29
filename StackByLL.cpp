//
// Created by Rounak on 29/10/17.
//

#include "StackByLL.h"

int main() {
    StackByLL<int> stack;
    int x = INT_MIN;
    stack.Push(23);
    stack.Top(x);
    stack.Push(232);
    stack.Push(2213);
    stack.Pop(x);
    cout << "X is : " << x << endl;
    stack.Top(x);
    cout << "X is : " << x << endl;
    return 0;
}

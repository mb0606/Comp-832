
#include <iostream>
#include <string>
#include "cstack.h"

using namespace std;

bool isValidExpression(LStack<char>* stackObj, string expression);

int main() {
    string userInput;
    
    while (userInput != "quit" && userInput != "Quit" && userInput != "q" && userInput != "Q"){
        LStack<char> *s1 =  new LStack<char>();
        userInput = "";
        cout << "Enter an expression: \n";
        cin >> userInput;
        if(userInput != "quit" && userInput != "Quit" && userInput != "q" && userInput != "Q"){
            if (isValidExpression(s1, userInput)) {
                cout << "It's a valid expression\n";
            }
            else {
                cout << "It's NOT a valid expression\n";
            }
            delete s1;
        }
    }
    
    return 0;
}

bool isValidExpression(LStack<char>* stackObj, string expression) {
    for (int i = 0; i < expression.length() ; i++) {
        char currentChar = expression[i];
        // if it's an opening bracket push on to the stack
        if (currentChar == '{' || currentChar == '[' || currentChar == '(') {
            stackObj->push(currentChar);
        }
        else {
            // Stack should have at least one openning expression
            if (stackObj->isEmpty()) {
                return false;
            }
            // if it is not an opening bracket and check if it is a closing
            char stackChar = stackObj->pop();
            //cout << stackChar << " " << currentChar << endl;
            if (stackChar == '{' &&  currentChar == '}') {}
            else if (stackChar == '[' &&  currentChar == ']') {}
            else if (stackChar == '(' &&  currentChar == ')') {}
            else {
                return false;
            }
        }
    }
    // if we got to the end of the string but there are still char in the stack
    if (stackObj->isEmpty()) {
        return true;
    }
    return false;
    
    
}

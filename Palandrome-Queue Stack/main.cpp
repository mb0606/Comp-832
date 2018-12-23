// this is the main driver program

#include <iostream>
#include <string>
#include "cstack.h"
#include "cqueue.h"

using namespace std;

bool isPalindrome(CStack<char>* s, CQueue<char>* q)
{
    int length = s->length();
    //cout << length;
    if(length == 1 ){
        return true;
    }
    else if(length <= 2 ){
        return false;
    } else {
        for(int i = 0; i < length; i++){
            
            char compare1 = s->pop();
            char compare2 = q->dequeue();
            if(compare1 != compare2){
                return false;
            }
        }
    }
    return true;
};

//char toLower(char letter){
//    if(static_cast<int>(letter) <= 97){
//        return static_cast<char>(static_cast<int>(letter) + 32);
//    }
//    return letter;
//    
//};
bool isChar(char letter){
    if((static_cast<int>(letter) <= 90 && static_cast<int>(letter) >= 65) || (static_cast<int>(letter) <= 122 && static_cast<int>(letter) >= 97)){
        return true;
    }
    return false;
};

int main()
{
    string choice;
    
    do {
        choice = "";
        cout << "Please enter a string to test for palindrome or type QUIT to exit:";
        getline(cin, choice, '\n');
        cin.clear();
        string printOut = choice;
        
        //cout << "coice size " << choice.size() << endl;
        int length = static_cast<int>(choice.size());
        for(int i = 0; i < length; i++){
            if(isChar(choice[i])){
                choice[i] = tolower(choice[i]);
                
            }
            
        }
        if(choice != "quit"){
            cout << " "<< printOut << endl;
            CStack<char> *s1 =  new CStack<char>();
            CQueue<char> *q1 =  new CQueue<char>();
            for(int i = 0; i < length; i++){
                if(isChar(choice[i])){
                    s1->push(choice[i]);
                    q1->enqueue(choice[i]);
                }
                
            }
            if(isPalindrome(s1, q1)) {
                cout << "The input is a palindrome." << endl;
            } else {
                cout << "The input is not a palindrome." << endl;
            }
            delete s1;
            delete q1;
            
        }
    } while (choice != "quit");
    
}

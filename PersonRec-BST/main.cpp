#include "Tree.h"
#include <iostream>

using namespace std;

int displayMenu(void);
void processChoice(int, Tree&);

int main(void)
{
    int num;
    
    Tree ct;
    do
    {
        num = displayMenu();
        if (num != 3)
            processChoice(num, ct);
    } while (num != 3);
    
    return 0;
}

int displayMenu(void)
{
    int choice;
    cout << "\nMenu\n";
    cout << "==============================\n\n";
    cout << "1. Add student to waiting list\n";
    cout << "2. View waiting list\n";
    cout << "3. Exit program\n\n";
    cout << "Please enter choice: ";
    cin >> choice;
    return choice;
}

void processChoice(int choice, Tree& myTree)
{
    switch (choice)
    {
        case 1:
            myTree.Add();
            break;
        case 2:
            myTree.View();
            break;
    }
}

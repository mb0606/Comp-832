//
//  main.cpp
//  binary-tree-personlist
//
//  Created by mb0606 on 12/13/18.
//  Copyright © 2018 mb0606. All rights reserved.
//

#include "personlist.h"
#include <iostream>

using namespace std;

int displayMenu(void);
void processChoice(int, PersonList&);

int main()
{
    int num;
    
    PersonList myList;
    do
    {
        num = displayMenu();
        if (num != 3)
            processChoice(num, myList);
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
    cin.ignore();
    return choice;
}

void processChoice(int choice, PersonList& p)
{
    switch (choice)
    {
        case 1: p.AddToList();
            break;
        case 2: p.ViewList();
            break;
    }
}

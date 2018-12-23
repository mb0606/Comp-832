//
//  personlist.cpp
//  binary-tree-personlist
//
//  Created by mb0606 on 12/13/18.
//  Copyright © 2018 mb0606. All rights reserved.
//

#include "personlist.h"

void PersonList::ViewList(){
    if (head == NULL){
        std::cout <<  "List is empty\n";
        
    } else {
        std::cout << "# Name Contribution\n";
        std::cout << "=======================================\n";
        PersonRec* curr = head;
        int count = 1;
        while(curr != NULL){
            std::cout << count << " " <<  curr->name << " $" << curr->contribution << std::endl;
            count++;
            curr = curr->next;
        }
    }
};

void PersonList::AddToList() {
    // ask user for info
    std::string name;
    int contribution;
    std::cout << "Enter the person's name: ";
    std::getline(std::cin, name);
    //std::cin.ignore(25, '\n');
    std::cout << "Enter the person's contribution: ";
    std::cin >> contribution;
    std::cin.ignore();
    std::cin.clear();
    
    if (head == NULL) {
        head = new PersonRec;
        head->name = name;
        head->contribution = contribution;
    }
    else {
        PersonRec* temp = new PersonRec;
        temp->name = name;
        temp->contribution = contribution;
        PersonRec* curr = head;
        while (curr != NULL) {
            //std::cout << "in loop " << name << std::endl;
            //                // we are on the head and it is less
            if (curr->contribution < temp->contribution && curr == head) {
                temp->next = head;
                head = temp;
                curr = NULL;
            }
            // the person we are on is equal but not the next
            else if (curr->next == NULL && curr->contribution >= temp->contribution){
                curr->next = temp;
                curr = NULL;
            }
            else if (curr->contribution == temp->contribution
                     && curr->next->contribution != temp->contribution) {
                temp->next = curr->next;
                curr->next = temp;
                curr = NULL;
            }
            // current value is greater but the next is less
            else if (curr->contribution > temp->contribution
                     && curr->next->contribution < temp->contribution ) {
                temp = curr->next;
                curr->next = temp;
                curr = NULL;
            }
            // move to the next node
            else {
                curr = curr->next;
            }
            
            
        }
    }
    
}
void PersonList::clear() {   // Return link nodes to free store
    PersonRec* curr;
    while (head != NULL) {
        curr = head;
        head = head->next;
        delete curr;
    }
}



//
//  Tree.cpp
//  tree
//
//  Created by mb0606 on 12/13/18.
//  Copyright © 2018 mb0606. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "Tree.h"

using namespace std;

Tree::PersonRec* Tree::CreateLeaf(int bribe, string name){
    PersonRec* n = new PersonRec;
    n->bribe = bribe;
    n->name = name;
    
    n->left = NULL;
    n->right = NULL;
    
    return n;
};

void Tree::AddLeafPrivate(int bribe, string name, PersonRec* Ptr){
    // if the root is not assigned
    if(root == NULL){
        root = CreateLeaf(bribe, name);
    }
    // if the key value is less than
    else if(bribe < Ptr->bribe) {
        if (Ptr->left != NULL){
            AddLeafPrivate(bribe, name, Ptr->left);
        } else {
            Ptr->left = CreateLeaf(bribe, name);
        }
    }
    // if the key value is greater
    else if(bribe > Ptr->bribe) {
        if (Ptr->right != NULL){
            AddLeafPrivate(bribe, name, Ptr->right);
        } else {
            Ptr->right = CreateLeaf(bribe, name);
        }
        // if the key is equal to the value
    } else {
        cout << "\nThis bribe amount has already been paid." << endl;
    }
    
};

void Tree::PrintInOrderPrivate(PersonRec* Ptr, int &count){
    if(root != NULL){
        //Go right if possible
        if(Ptr->right != NULL){
            PrintInOrderPrivate(Ptr->right, count);
        }
        // Process node
        cout << count << " " << Ptr->name << " $" << Ptr->bribe << endl;
        count++;
        // Go left if possible
        if(Ptr->left != NULL){
            PrintInOrderPrivate(Ptr->left, count);
        }
    }
    else {
        cout << "The tree is empty." << endl;
    }
    
    
};
void Tree::PrintInOrder(){
    int count = 1;
    PrintInOrderPrivate(root, count);
};


void Tree::AddLeaf(int bribe, string name){
    AddLeafPrivate(bribe, name, root);
};

void Tree::Add(){
    std::string name;
    int contribution;
    std::cout << "\nEnter the person's name: \n";
    cin.ignore();
    std::getline(std::cin, name);
    //std::cin.ignore(10, '\n');
    std::cout << "Enter the person's contribution: ";
    std::cin >> contribution;
    std::cin.ignore();
    std::cin.clear();
    AddLeaf(contribution, name);
}

Tree::Tree(){
    root = NULL;
};
Tree::~Tree(){
};

void Tree::View (){
    if(root != NULL){
        cout <<"\n# Name Contribution"<< endl;
        cout <<"======================================="<< endl;
        PrintInOrder();
        
    }
    else {
        cout << "\nList is empty" << endl;
    }
};



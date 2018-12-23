//
//  Tree.hpp
//  Tree-assignment-5
//
//  Created by mb0606 on 11/9/18.
//  Copyright © 2018 mb0606. All rights reserved.
//

#ifndef Tree_h
#define Tree_h
#include <string>

#include <stdio.h>
using namespace std;
class Tree {
    
private:
    struct PersonRec {
        int bribe;
        string name;
        PersonRec* left;
        PersonRec* right;
    };
    PersonRec* root;
    PersonRec* CreateLeaf(int bribe, string name);
    void AddLeafPrivate(int bribe, string name, PersonRec* Ptr);
    void PrintInOrderPrivate(PersonRec* Ptr, int &count);
    
    
public:
    Tree();
    ~Tree();
    void AddLeaf(int bribe, string name);
    void Add();
    void View ();
    void PrintInOrder();
    int ReturnRootKey();
    void PrintChildren(int bribe);
    
    
    
    
    
};

#endif /* tree_h */

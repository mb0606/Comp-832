//
//  personlist.hpp
//  binary-tree-personlist
//
//  Created by mb0606 on 12/13/18.
//  Copyright © 2018 mb0606. All rights reserved.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>


struct PersonRec {
    std::string name;
    int contribution;
    PersonRec * next = NULL;
    
};

class PersonList {
    
private:
    PersonRec* head;
    void clear();
    
public:
    PersonList() { head = NULL; };
    ~PersonList() {
        clear();
    };
    void ViewList();
    void AddToList();
};
#endif

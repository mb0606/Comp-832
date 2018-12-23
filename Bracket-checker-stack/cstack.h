//
//  cstack.hpp
//  assisgment-2
//
//  Created by mb0606 on 12/13/18.
//  Copyright © 2018 mb0606. All rights reserved.
//

#ifndef cstack_h
#define cstack_h

#include <stdio.h>
#include "link.h"
#include "stack.h"

#include "cstack.h"

template <typename E> class LStack: public Stack<E> {
private:
    Link<E>* top;            // Pointer to first element
    int size;                   // Number of elements
    
public:
    explicit LStack(int sz = 20) // Constructor
    {
        top = NULL;
        size = 0;
    }
    
    ~LStack() { clear(); }
    
    void clear() {
        while (top != NULL) {
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
    
    void push(const E& it) {
        Link<E>* temp = top;
        top = new Link<E>(it, temp);
        size++;
    }
    
    E pop() {
        E it = top->element;
        Link<E>* ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
        
    }
    const E& topValue() const { // Return top value
        return top->element;
    }
    bool isEmpty(){
        return size == 0;
    }
    
    int length() const { return size; } // Return length
};


#endif /* cstack_hpp */

//
//  cstack.cpp
//  assisgment-2
//
//  Created by mb0606 on 12/13/18.
//  Copyright © 2018 mb0606. All rights reserved.
//

//#include "cstack.h"
template <typename E> class Stack {
private:
    void operator =(const Stack&) {}
    Stack(const Stack&) {}
    
public:
    Stack() {}
    virtual ~Stack() {}
    virtual void clear() = 0;
    virtual void push(const E& it) = 0;
    virtual E pop() = 0;
    virtual const E& topValue() const = 0;
    virtual int length() const = 0;
};

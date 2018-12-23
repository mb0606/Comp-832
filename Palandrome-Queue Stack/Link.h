//
//  Link.h
//  final exam
//
//  Created by mb0606 on 12/15/18.
//  Copyright © 2018 mb0606. All rights reserved.
//
//
//  link.h
//  assisgment-2
//
//  Created by mb0606 on 12/13/18.
//  Copyright © 2018 mb0606. All rights reserved.
//

#ifndef link_h
#define link_h
template <typename E> class Link {
public:
    E element;
    Link *next;
    
    Link(const E& elemval, Link* nextval =NULL){
        element = elemval;
        next = nextval;
    }
    
    explicit Link(Link* nextval =NULL) {
        next = nextval;
    }
};


#endif /* link_h */

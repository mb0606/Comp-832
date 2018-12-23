//
//  Lqueue.h
//  queue
//
//  Created by mb0606 on 12/15/18.
//  Copyright © 2018 mb0606. All rights reserved.
//

#ifndef Lqueue_h
#define Lqueue_h
template <typename E>
struct Node {
    E value;
    Node* next;
}
 template <typename E> class LQueue {
 private:
     E front;    // Index of front element
     E rear;
     int max;
     int size;
 public:
     explict LQueue(int maxSize = 50){
         max = maxSize
         size = 0;
     }
     ~LQueue {
         while(front != NULL){
             Node *temp = front;
             front = front.next;
             delete temp;
         }
     }

 }

#endif /* Lqueue_h */

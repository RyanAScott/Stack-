//
//  Queue.h
//  ProgrammingProject2
//
//  Created by Ryan Scott on 9/16/20.
//  Copyright © 2020 Ryan Scott. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include "Sequence.hpp"

// Queue1 Contract
template <class T>
class Queue1
    //! is modeled by string of T
    //! exemplar self
{
public: // Standard Operations
    Queue1 (); // constructer
        //! replaces self
        //! ensures: self = <>
    ~Queue1 (); // destructer
    void clear (void);// clears itself from memory
        //! clears self
    void transferFrom (Queue1& source);
        //! replaces self
        //! clears source
        //! ensures: self = #source
    Queue1& operator = (Queue1& rhs);
        //! replaces self
        //! restores rhs
        //! ensures: self = rhs
    
    // Queue1 Specific Operations
    void enqueue (T& x); // adds new elements
        //! updates self
        //! clears x
        //! ensures: self = #self * <#x>
    void dequeue (T& x);// removing an element
        //! updates self
        //! replaces x
        //! requires: self /= <>
        //! ensures: <x> is prefix of #self and self = #self(1, |#self|)
    void replaceFront (T& X);// replacing the very front element with the new element
        //! updates self, x
        //! requires: self /= <>
        //! ensures: <x> is prefix of #self and self = <#x> * #self(1, |#self|)
    T& front (void);// returning a reference to the very first element
        //! restores self
        //! requires: self /= <>
        //! ensures: <front> is prefix of self
    int length (void);// return the size of the queue
        //! restores self
        //! ensures: length = itself
    void outputQueue();
        //! outputs the queue
        //! calling on the output sequence would help out here
    
private: // calling the sequence class
    Sequence<T> seQ;// Sequence that behaves like a queue at that point

};// Queue1 contract



#endif /* Queue_h */

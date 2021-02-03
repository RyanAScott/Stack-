//
//  Stack.h
//  ProgrammingProject3
//
//  Created by Ryan Scott on 9/24/20.
//  Copyright © 2020 Ryan Scott. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include "Queue.hpp"
#include <iostream>
using namespace std;

template <class T>
class Stack1
    //! is modeled by string(T)
    //! exemplar self
{
public: // standard Operations
    Stack1();
        //! alters self
        //! ensures: self = < >
    
    ~Stack1();
    
    void clear(void);
        //! alters self
        //! ensures: self = < >
    
    void transferFrom(Stack1& source);
        //! alters self, source
        //! ensurses self = #source and source = < >
    
    Stack1& operator =(Stack1& rhs);
        //! alters self
        //! preserves rhs
        //! ensures: self = rhs
    
    // Stack1 Specific Operations
    void push(T& x);
        //! alters self
        //! consumes x
        //! ensures: self = <#x> * self
    
    void pop(T& x);
        //! alters self
        //! produces x
        //! requires: self /= < >
        //! ensures: <x> is prefix of #self and self = #self[1, |#self|)
    
    void replaceTop(T& x);
        //! alters self, x
        //! requires: self /= < >
        //! ensures: <x> is prefix of #self and self = <#x> * #self[1, |#self|)
    
    T& top(void);
        //! preserves self
        //! requires: self /= < >
        //! ensures: <top> is prefix of self
    
    int length(void);
        //! preserves self
        //! ensures: length = |self|
    
    void outputStack();
    //! outputs the queue
    //! calling on the output sequence would help out here
    
private: // Representation
    Queue1<int> primary_queue, secondary_queue;
    
};// stack design contract

#endif /* Stack_h */

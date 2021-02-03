//
//  Stack.hpp
//  ProgrammingProject3
//
//  Created by Ryan Scott on 9/24/20.
//  Copyright © 2020 Ryan Scott. All rights reserved.
//  Source of stack information: https://www.youtube.com/watch?v=kKjYSBeDpFA&t=1s&ab_channel=CodeWhoop
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include "Stack.h"
#include <iostream>
using namespace std;

// Stack1 constructor
template <class T>
Stack1<T>::Stack1(){
    
}// constructor

// Stack1 destructor
template <class T>
Stack1<T>::~Stack1(){

}// deconstuctor

// Stack1 clear
template <class T>
void Stack1<T>::clear (void){
    primary_queue.clear();
    secondary_queue.clear();
}// clear

// Stack1 transferFrom
template <class T>
void Stack1<T>::transferFrom (Stack1& source){
    primary_queue.transferFrom(source.primary_queue);
    secondary_queue.transferFrom(source.secondary_queue);
    source.clear();
}// transferFrom

// Stack1 operator
template <class T>
Stack1<T>& Stack1<T>::operator = (Stack1& rhs){
    primary_queue.operator = (rhs.primary_queue);
    secondary_queue.operator = (rhs.secondary_queue);
    return (*this);
}// operator

// Stack1 Push
template <class T>
void Stack1<T>::push(T& x){
    // enqueue in secondary_queue
    secondary_queue.enqueue(x);
    
    // add elements of primary_queue to secondary_queue
    while(primary_queue.length() != 0){
        secondary_queue.enqueue(primary_queue.front());
        primary_queue.dequeue(x);
    }// while
    
    // swapping the queues
    Queue1<int> temp_queue = primary_queue;
    primary_queue = secondary_queue;
    secondary_queue = temp_queue;
    
}// push

// Stack1 Pop
template <class T>
void Stack1<T>::pop(T& x){
    if(primary_queue.length() == 0){
        return;
    }// if
    else {
        primary_queue.dequeue(x);
    }// else
}// pop

// Stack1 Top
template <class T>
T& Stack1<T>::top (){
    if (length() != 0){ // a test if the queue is empty
        return primary_queue.front();
    }// if
    else{
        return primary_queue.front();
    }// else
}// front

// Stack1 replaceTop
template <class T>
void Stack1<T>::replaceTop(T& x){
    primary_queue.replaceFront(x);
}// replaceFron

// Stack1 length
template <class T>
int Stack1<T>::length (void){
    return primary_queue.length();
}// length

// Queue1 output
template <class T>
void Stack1<T>::outputStack(){
    primary_queue.outputQueue();
}// outputQueue

#endif /* Stack_hpp */

//
//  Queue.hpp
//  ProgrammingProject2
//
//  Created by Ryan Scott on 9/16/20.
//  Copyright © 2020 Ryan Scott. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include "Queue.h"
using namespace std;

// Queue1 constuctor
template <class T>
Queue1<T>::Queue1(){
    
}// constructor

// Queue1 destructor
template <class T>
Queue1<T>::~Queue1(){

}// deconstuctor

// Queue1 clear
template <class T>
void Queue1<T>::clear (void){
    seQ.clear();
}// clear

// Queue1 transferFrom
template <class T>
void Queue1<T>::transferFrom (Queue1& source){
    seQ.transferFrom(source.seQ);
    source.clear();
}// transferFrom

// Queue1 operator
template <class T>
Queue1<T>& Queue1<T>::operator = (Queue1& rhs){
    seQ.operator = (rhs.seQ);
    return (*this);
}// operator

// Queue1 enqueue
template <class T>
void Queue1<T>::enqueue(T& x){
    seQ.add(x, length());// callback to the programming assignment 1
}// enqueue

// Queue1 dequene
template <class T>
void Queue1<T>::dequeue(T& x){
    seQ.remove(x, 0);// callback to the programming assignment 1
}// dequeue

// Queue1 replaceFront
template <class T>
void Queue1<T>::replaceFront(T& x){
    if(length() != 0){
        T temp = x;
        seQ.remove(x, 0);
        seQ.add(temp, 0);
    }// if
}// replaceFront

// Queue1 front
template <class T>
T& Queue1<T>::front (){
    if (length() != 0){ // a test if the queue is empty
        return seQ.entry(0);
    }// if
    else{
        return seQ.entry(0);
    }// else
}// front

// Queue1 length
template <class T>
int Queue1<T>::length (void){
    return seQ.length();
}// length

// Queue1 output
template <class T>
void Queue1<T>::outputQueue(){
    seQ.outputSequence();
}// outputQueue

#endif /* Queue_hpp */

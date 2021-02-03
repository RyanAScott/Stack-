//
//  Sequence.hpp
//  ProgrammingProject2
//
//  Created by Ryan Scott on 9/16/20.
//  Copyright © 2020 Ryan Scott. All rights reserved.
//

#ifndef Sequence_hpp
#define Sequence_hpp

#include <iostream>
#include <cstdio>
using namespace std;
#include "Sequence.h"

template <class T>
Sequence<T>::Sequence ()
{
    head = NULL;
    size = 0;
}// Sequence

template <class T>
Sequence<T>::~Sequence ()
{
    reclaimAllNodes(head);
}    // ~Sequence


template <class T>
void Sequence<T>::clear (void)
{
    reclaimAllNodes(head);
    head = NULL;
    size = 0;
} // clear

template <class T>
void Sequence<T>::reclaimAllNodes (NodeRecord*& initialP)
// requires: Null(initialP)  or  Alive(initialP)
//  ensures: all nodes in linked list
//           beginning with initialP are reclaimed
{
    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);
    } // end if
} // reclaimAllNodes

// You are required to implement add, remove, entry, length, and outputSequence functions here.

// add function
template <class T>
void Sequence<T>:: add(T& x, int pos){
    // validate pos to be between [0,pos]
    if(pos > size){
        cout << "\n Invalid\n";
    }// if
    else {
        if (pos == 0){
            NodeRecord* temp = new NodeRecord;
            temp->next = head;
            head = temp;
            head->value = x;
            size++;
        }// if
        
        else{
            NodeRecord* curr = head;
            for (int a = 0; a < pos - 1; a++){
                curr = curr->next;
            }// for
            
            NodeRecord* temp = new NodeRecord;
            temp->next = curr->next;
            curr->next = temp;
            size++;
            temp->value = x;
        }// else
    }// else
    
}// add

template <class T>
void Sequence<T>:: remove(T& x, int pos){
    if (pos >= size){
        cout<<"Invalid position\n";
        return;
    }// if
    
    if (pos == 0){
        NodeRecord* temp = head;
        x = temp->value;
        delete temp;
        head = head->next;
    }// if
    
    else{
        NodeRecord* curr = head;
        for (int a = 0; a < pos - 1; a++){
            curr = curr->next;
        }// for
        
        NodeRecord* temp = curr->next;
        curr->next = temp->next;
        x = temp->value;
        delete temp;
    }// else
    size--;
}// remove

template <class T>
T& Sequence<T>:: entry (int pos){
    if (pos < 0 || pos >= size){
        cout<<"Invalid Entry";
        return head->value;
    }// if
    
    NodeRecord* curr = head;
    for(int a = 0; a < pos; a++){
        curr = curr->next;
    }// for
    return curr->value;
}// entry

template <class T>
int Sequence<T>::length(void){
    return size;// return the number of elements in sequence
    
}//length

template <class T>
void Sequence<T>:: outputSequence(void){
    if (size == 0){
        cout<<"Empty Sequence\n";
    }// if
    else{
        NodeRecord* curr = head;
        cout << "< ";
        while (curr != NULL){
            cout<<curr->value;
            cout<<" , ";
            curr = curr->next;
        }// while
        cout<<">";
    }// else
    
}// outputSequence

template <class T>
void Sequence<T>::transferFrom(Sequence& source){
    T temp;
    clear(); // clears self
    for (int i = 0; i < source.length(); i++){ // traverses source
        temp = source.entry(i);
        add(temp, length());//adds source elements to self
    }// for
    source.clear();// clears source
}// transferFrom

template <class T>
Sequence<T>& Sequence<T>::operator=(Sequence& rhs){
    clear();// clears self
    for (int i = 0; i < rhs.length(); i++){ // traverses ehs
        add(rhs.entry(i), length());// adds elements from rhs to self
    }// for
    return (*this);// returns self = rhs
}// operator


 /*
 Sequence<int> s1;
 Sequence<int> s2;
 Sequence<int> s3;
 int xi = 0;
 cout << "SEQUENCE ONE\nS1: ";
 s1.outputSequence();

 cout << "\n\nTESTING ADD, OUTPUTSEQUENCE, LENGTH\nFilled S1 with <23, 14, 18, 31, 11>";
 xi = 23;
 s1.add(xi, 0);
 xi = 14;
 s1.add(xi, 1);
 xi = 18;
 s1.add(xi, 2);
 xi = 31;
 s1.add(xi, 3);
 xi = 11;
 s1.add(xi, 4);
 cout << "\nS1: ";
 s1.outputSequence();
 cout << "\nS1 size: " << s1.length();

 cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 17 to position 0";
 xi = 17;
 s1.add(xi, 0);
 cout << "\nS1: ";
 s1.outputSequence();
 cout << "\nS1 size: " << s1.length();

 cout << "\n\nTESTING REMOVE\n+ OUTPUTSEQUENCE, LENGTH\nRemoved entry at position 3";
 s1.remove(xi, 3);
 cout << "\nElement removed: "<<xi;
 cout << "\nS1: ";
 s1.outputSequence();
 cout << "\nS1 size: " << s1.length();

 cout << "\n\nTESTING ENTRY\nS1[1]: "<< s1.entry(1);
 cout << "\nS1[0]: " << s1.entry(0);

 cout << "\n\nTESTING CLEAR\n+ OUTPUTSEQUENCE\nClearing Sequence One\nS1:";
 s1.clear();
 s1.outputSequence();

  */

/* TESTING SEQUENCE TWO
    TESTED:
        ADD
        OUTPUTSEQUENCE
        LENGTH
        ENTRY
        REMOVE
        CLEAR
 */

 //Client does NOT abide by requires clauses
 //Goes over size
 /*
 
 cout << "\n\n\nSEQUENCE TWO\nS2: ";
 s2.outputSequence();

 cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nFilled S2 with <1>";
 xi = 1;
 s2.add(xi, 0);
 cout << "\nS2: ";
 s2.outputSequence();
 cout << "\nS2 size: " << s2.length();

 cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 3 to position 3";
 xi = 3;
 s2.add(xi, 3); //error because 3 > size
 cout << "\nS2: ";
 s2.outputSequence();
 cout << "\nS2 size: " << s2.length();

 cout << "\n\nENTRY\nS2[3]: ";
 cout << s2.entry(3); //error because 3 > size

 
 cout << "\n\nREMOVE, OUTPUTSEQUENCE\nRemoved entry at position 2";
 s2.remove(xi, 2);
 cout << "Element removed: " << xi;
 cout << "\nS2: ";
 s2.outputSequence();
  


 cout << "\n\nENTRY";
 cout << "\nS2[0]: ";
 cout << s2.entry(0);
 cout << "\nS2[1]: ";
 cout << s2.entry(1); //error because 1 = size
 cout << "\nS2[2]: ";
 cout << s2.entry(2); //error because 2 > size
 cout << "\nS2[3]: ";
 cout << s2.entry(3); //          ||

 cout << "\n\nCLEAR, OUTPUTSEQUENCE, LENGTH\nClearing Sequence Two";
 s2.clear();
 cout << "\nS2: ";
 s2.outputSequence();
 cout << "\nS2 size: " << s2.length();

  */

 /* TESTING SEQUENCE THREE
    TESTED:
        ADD
        OUTPUTSEQUENCE
        LENGTH
        ENTRY
        REMOVE
        CLEAR
 */



 /*
 cout << "\n\n\nSEQUENCE THREE\nS3: ";
 s3.outputSequence();

 cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nFilled S3 with <8, 23, 2000>";
 xi = 8; //08 => invalid octal digit ??
 s3.add(xi, 0);
 xi = 23;
 s3.add(xi, 1);
 xi = 2000;
 s3.add(xi, 2);
 cout << "\nS3: ";
 s3.outputSequence();
 cout << "\nS3 size: " << s3.length();


 cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 1 to position 0 + 6 to position 1 + 2002 to position 3>";
 xi = 1;
 s3.add(xi, 0);
 xi = 6;
 s3.add(xi, 1);
 xi = 2002;
 s3.add(xi, 2);
 cout << "\nS3: ";
 s3.outputSequence();
 cout << "\nS3 size: " << s3.length();


 cout << "\n\nENTRY, REMOVE";
 cout << "\nS3[2]: " << s3.entry(2);
 cout << "\nRemoved entry at position 2";
 s3.remove(xi, 2);
 cout << "Element removed: " << xi;
 cout << "\nS3[2]: " << s3.entry(2);
 cout << "\nRemoved entry at position 2";
 s3.remove(xi, 2);
 cout << "Element removed: " << xi;
 cout << "\nS3[2]: " << s3.entry(2);


 cout << "\n\nOUTPUTSEQUENCE, LENGTH\nS3: ";
 s3.outputSequence();
 cout << "\nS3 size: " << s3.length();


 cout << "\n\nCLEAR, OUTPUTSEQUENCE, LENGTH\nClearing Sequence Three";
 s3.clear();
 cout << "\nS3: ";
 s3.outputSequence();
 cout << "\nS3 size: " << s3.length();


 cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 6 to position 0, 2019 to position 1, and 25 to position 1";
 xi = 6;
 s3.add(xi, 0);
 xi = 2019;
 s3.add(xi, 1);
 xi = 25;
 s3.add(xi, 2);
 cout << "\nS3: ";
 s3.outputSequence();
 cout << "\nS3 size: " << s3.length();
 */

#endif /* Sequence_hpp */

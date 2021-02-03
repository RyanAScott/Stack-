//
//  main.cpp
//  ProgrammingProject2
//
//  Created by Ryan Scott on 9/16/20.
//  Copyright © 2020 Ryan Scott. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
using namespace std;

int main()
{
    // Testing out Stack1
    Stack1<int> s;
    
    // variables
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    
    s.push(a);
    s.push(b);
    s.push(c);
    s.push(d);
    
    cout<<"Stack s\n";
    cout<<"Testing push";
    s.outputStack();
    
    // test top
    cout<<"\n";
    cout<<"Top: "<<s.top()<<"\n";
    cout<<"\n";
    
    cout<<"Testing Pop\n";
    // testing pop
    s.pop(a);
    
    s.outputStack();
    cout<<"\n";
    
    cout<<"Testing replaceTop\n";
    // Testing replaceTop
    int e = 5;
    s.replaceTop(e);
    
    s.outputStack();
    cout<<"\n";
    
    cout<<"Testing length for s: "<<s.length();
    cout<<"\n";
    
    return 0;

} //main

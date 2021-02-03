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
    Stack1<int> s2;
    Stack1<int> s3;
    
    // variables
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    cout << "Stack s\n";
    cout << "\nTesting push";
    cout << "\ns before: ";
    s.outputStack();

    s.push(a);
    s.push(b);
    s.push(c);
    s.push(d);

    cout << "\ns after: ";
    s.outputStack();
        
    // test top
    cout << "\n";
    cout<<"\n";
    cout<<"Top: "<<s.top()<<"\n";
    cout<<"\n";
    
    cout<<"Testing Pop\n";
    cout << "\ns before: ";
    s.outputStack();

    // testing pop
    s.pop(a);
    
    cout << "\ns after: ";
    s.outputStack();
    cout<<"\n";
    
    cout<<"\nTesting replaceTop\n";
    // Testing replaceTop
    cout << "\ns before: ";
    s.outputStack();

    int e = 5;
    s.replaceTop(e);
    
    cout << "\ns after: ";
    s.outputStack();
    cout<<"\n";
    
    cout<<"\nTesting length for s: "<<s.length();
    cout<<"\n";

    // Testing operator=
    cout << "\nTesting operator=\n";
    cout << "\ns2 before: ";
    s2.outputStack();
    cout << "\ns before: ";
    s.outputStack();

    s2.operator=(s);

    cout << "\ns2 after: ";
    s2.outputStack();
    cout << "\ns after: ";
    s.outputStack();
    cout << "\n";

    // Testing transferFrom
    cout << "\nTesting transferFrom\n";
    cout << "\ns3 before: ";
    s3.outputStack();
    cout << "\ns before: ";
    s.outputStack();

    s3.transferFrom(s);

    cout << "\ns3 after: ";
    s3.outputStack();
    cout << "\ns after: ";
    s.outputStack();
    cout << "\n";

    return 0;

} //main

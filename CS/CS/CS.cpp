//
//  CS.cpp
//  CS
//
//  Created by Jonathan Springer on 9/5/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
//  Descrition: Print CS! in ACSII Art
//

#include <iostream>
using namespace std;

int main()
{
    int i;
    for (i=0; i<50; i=i+1) { //Print a line of *
        cout<<"*";
    }
    /*
     Print CS! with C, S, and ! respectively using tabs(\t) and spaces to position the letters
    */
    cout<<endl;
    cout<<endl;
    cout<<"\t\tC C C\t\t\t\tS S S S\t\t\t!!"<<endl;
    cout<<"\t  C\t\t  C\t\t\t  S\t\t\tS\t\t!!"<<endl;
    cout<<"\t C\t\t\t\t\t S\t\t\t\t\t!!"<<endl;
    cout<<"\tC\t\t\t\t\t  S\t\t\t\t\t!!"<<endl;
    cout<<"\tC\t\t\t\t\t\tS S S S\t\t\t!!"<<endl;
    cout<<"\tC\t\t\t\t\t\t\t\tS\t\t!!"<<endl;
    cout<<"\t C\t\t\t\t\t\t\t\t S\t\t!!"<<endl;
    cout<<"\t  C\t\t  C\t\t\t  S\t\t\tS"<<endl;
    cout<<"\t\tC C C\t\t\t\tS S S S\t\t\tOO"<<endl;
    cout<<endl;
    for (i=0; i<50; i=i+1) { //Print a line of *
        cout<<"*";
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\tComputer Science is Cool Stuff!!!"; //Print "Computer Science is Cool Stuff!!!"
    return 0;
}
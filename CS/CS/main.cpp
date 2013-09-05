//
//  main.cpp
//  CS
//
//  Created by Jonathan Springer on 9/5/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int display(string output)
{
    cout<<output;
    return 0;
}

int main()
{
    string output;
    
    cout<<"Enter string to pe printed: ";
    cin>>output;
    display(output);
    return 0;
}
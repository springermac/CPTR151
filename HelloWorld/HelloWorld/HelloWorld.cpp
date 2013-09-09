//
//  HelloWorld.cpp
//  HelloWorld
//
//  Created by Jonathan Springer on 9/5/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
//  Description: This program prints out "Hello World" 20 times to the console.
//

#include <iostream>
using namespace std;

int main()
{
    int i;//Variable to hold the count of how many times the for loop has been run
    for (i=0; i<20; i=i+1)//For loop that loops 20 times
    {
        cout<<endl<<("Hello World")<<endl;//Prints "Hello World" to the console
    }
}
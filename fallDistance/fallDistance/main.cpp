//
//  main.cpp
//  fallDistance
//
//  Created by Jonathan Springer on 9/4/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    const int ACCELERATION=32;
    
    float time;
    float distance;
    
    cout<<"Enter the time in seconds, that the object falls: ";
    cin>>time;
    
    distance=(ACCELERATION*time*time)/2;
    
    cout<<"\nThe object will fall "<<distance<<" feet in "<<time<<" seconds.\n";
    
    return 0;
}


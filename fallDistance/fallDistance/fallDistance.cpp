//
//  fallDistance.cpp
//  fallDistance
//
//  Created by Jonathan Springer on 9/4/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
//  Description: Compute the distance in feet an object will fall in a given time.
//

#include <iostream>
using namespace std;

int main()
{
    const int ACCELERATION=32; // 32 feet per second
    
    /*
     Variables to hold user specified time and the result of the calculation in feet
    */
    float time;
    float distance;
    
    /*
     Prompt for the amount of time the object falls
    */
    cout<<"Enter the time in seconds, that the object falls: ";
    cin>>time;
    
    /*
     Compute the distance the object will fall in the given time
    */
    distance=(ACCELERATION*time*time)/2;
    
    /*
     Display the distance the object will fall and the time it took to fall
    */
    cout<<endl<<"The object will fall "<<distance<<" feet in "<<time<<" seconds."<<endl;
    
    return 0;
}
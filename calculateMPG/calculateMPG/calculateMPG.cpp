//
//  calculateMPG.cpp
//  calculateMPG
//
//  Created by Jonathan Springer on 9/9/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    double begMiles;
    double endMiles;
    double gallonsUsed;
    double milesPerGallon;
    
    cout<<endl<<"MPG calculator"<<endl;
    
    cout<<"Enter the begining miles: ";
    cin>>begMiles;
    
    cout<<"Enter the ending miles: ";
    cin>>endMiles;
    
    cout<<"Enter the gallons used: ";
    cin>>gallonsUsed;
    
    milesPerGallon=(endMiles-begMiles)/gallonsUsed;
    
    cout<<"MPG: "<<milesPerGallon;
    
    return 0;
}
//
//  coinCounter.cpp
//  coinCounter
//
//  Description: Collect number of quarters, nickles, and dimes input by keyboard then calculate and display total
//  monetary value.
//
//  Created by Jonathan Springer on 9/4/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int quarters;
    int dimes;
    int nickles;
    double total;
    double currancy;
    
    cout<<endl;
    cout<<"Enter number of quarters: ";
    cin>>quarters;
    
    cout<<"Enter number of dimes: ";
    cin>>dimes;
    
    cout<<"Enter number of nickles: ";
    cin>>nickles;
    
    total=(quarters*25)+(dimes*10)+(nickles*5);
    currancy=total/100;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"Total value: $"<<currancy<<" or ¢"<<total<<endl;
    
    return 0;
}
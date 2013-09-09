//
//  Hello.cpp
//  Hello
//
//  Created by Jonathan Springer on 9/2/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
//  Description:
//  Prompt for individuals first name, last name and age then output to data to console.
//
#include "iostream"
using namespace std;

int main()
{
    int age;//age of individual
    string firstName;//first name of individual
    string lastName;//last name of individual
    
    //get the first name of individual
    cout<<"\n";
    cout<<"Enter your first name: ";
    cin>>firstName;
    
    //get the last name of the individual
    cout<<"Enter your last name: ";
    cin>>lastName;
    
    //get the age of individual
    cout<<"Enter your age ";
    cin>>age;
    
    //display results
    cout<<"\nHello "<<firstName<<" "<<lastName;
    cout<<" your age is "<<age<<". Really????";
    cout<<"\n";
    return 0;
    
}//end main function
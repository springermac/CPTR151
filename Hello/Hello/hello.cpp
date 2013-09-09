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
    int age;//Initialize a variable to store the age of the individual
    string firstName;//Initialize a variable to store the first name of the individual
    string lastName;//Initialize a variable to store the last name of the individual
    
    cout<<endl;
    cout<<"Enter your first name: ";//Prompt for the individuals first name
    cin>>firstName;//Store the input from the console to the variable firstName
    
    cout<<"Enter your last name: ";//Prompt for the individuals last name
    cin>>lastName;//Store the input from the console to the variable lastName
    
    cout<<"Enter your age: ";//Prompt for the individuals age
    cin>>age;//Store the input from the console to the variable age
    
    cout<<endl<<"Hello "<<firstName<<" "<<lastName;//Print out the individuals first name and last name to the console
    cout<<" your age is "<<age<<". Really????";//Print out the individuals age to the console
    cout<<endl;
    return 0;
    
}
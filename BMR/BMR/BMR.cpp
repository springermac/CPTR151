//
//  BMR.cpp
//  BMR
//
//  Created by Jonathan Springer on 9/17/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
//  Description: Caluclates the number of chocolate bars that should be eaten to maintain a given weight without exercise.
//

#include <iostream>
using namespace std;

int main()
{
    char loop; //Variable to hold value of users response of whether they want to run the program again
    
    do {
        /*
         Declare variables to hold a persons weight, height, age, gender, the calculated BMR, and the number of chocolate
         bars they should eat.
        */
        int weight;
        int height;
        int age;
        char gender;
        int BMR;
        int bars;
        
        /*
         Prompt for a persons weight, height, age and gender.
        */
        cout<<"Please enter your weight: ";
        cin>>weight;
        cout<<"Please enter your height in inches: ";
        cin>>height;
        cout<<"Please enter your age: ";
        cin>>age;
        cout<<"Please enter your gender as (M)ale or (F)emale: ";
        cin>>gender;
        
        /*
         Calculate a persons BMR based on the entered valuse using an if statement to determine which calculation should
         be done based on the persons gender.
         Also calculate the number of chocolate bars a person with the entered valuses should eat to maintain the entered
         weight with out exericise.
        */
        if (gender=='m'||gender=='M') {
            BMR=66+(6.3*weight)+(12.9*height)-(6.8*age);
            bars=BMR/230;
            cout<<"If you do exercise you must eat "<<bars<<" chocolate bars to maintain your weight."<<endl; //Display the results of the calculations
        }
        else if (gender=='f'||gender=='F') {
            BMR=655+(4.3*weight)+(4.7*height)-(4.7*age);
            bars=BMR/230;
            cout<<"If you do exercise you must eat "<<bars<<" chocolate bars to maintain your weight."<<endl; //Display the results of the calculations
        }
        else {
            cout<<"Gender entered was not male or female"<<endl; //If the entered gender was not (M)ale or (F)emale tell user
        }
        
        cout<<"Try again? Y/N: "; //Prompt the user if they want to run the program again
        cin>>loop;
        
    } while (loop=='y'||loop=='Y'); //If user wants to run again this is true causing the program to loop
    
    return 0;
}


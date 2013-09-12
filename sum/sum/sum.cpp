//
//  sum.cpp
//  sum
//
//  Created by Jonathan Springer on 9/11/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    const int NUMBER_OF_INPUTS=10; //How many numbers can be entered. Extra numbers will be ignored.
    int values[10];
    int positive[10];
    int negative[10];
    int countOfPositive=0;
    int countOfNegative=0;
    float sumPositive=0;
    float sumNegative=0;
    float averagePositive=0;
    float averageNegative=0;
    float sum=0;
    float average=0;
    int i;
    
    cout<<"Enter 10 numbers seperated by a space. Press return after last number."<<endl;
    cout<<"Numbers: ";
    for (i=0; i<=NUMBER_OF_INPUTS-1; i++) { //Accept only as many numbers from the console as the const NUMBER_OF_INPUTS specifies
        cin>>values[i];
        if (cin.fail()) {
            cout<<"Not a valid number."<<endl;
            cout<<"Number: "<<endl;
        }
    }
    
    /*
     Test each value in values array
    */
    for (i=0; i<=NUMBER_OF_INPUTS-1; i++) {
        if (values[i]<0) {
            negative[countOfNegative]=values[i];
            countOfNegative++;
        }
        else if (values[i]>0) {
            positive[countOfPositive]=values[i];
            countOfPositive++;
        }
        else if (values[i]==0) {
            //Do nothing with zeros.
        }
        else {
            cout<<"Input value "<<i<<" is not a valid number";
            break; //Not a number
        }
    }
    
    for (i=0; i<=countOfPositive-1; i++) {
        sumPositive=positive[i]+sumPositive;
    }
    averagePositive=sumPositive/countOfPositive;
    
    for (i=0; i<=countOfNegative-1; i++) {
        sumNegative=negative[i]+sumNegative;
    }
    averageNegative=sumNegative/countOfNegative;
    
    for (i=0; i<=9; i++) {
        sum=sum+values[i];
    }
    average=sum/NUMBER_OF_INPUTS;
    
    cout.precision(2);
    cout<<"Sum of positive numbers: "<<sumPositive<<endl;
    cout<<"Average of positive numbers: "<<averagePositive<<endl;
    cout<<"Sum of negative numbers: "<<sumNegative<< endl;
    cout<<"Average of negative numbers: "<<averageNegative<<endl;
    cout<<"Sum of all numbers: "<<sum<<endl;
    cout<<"Average of all numbers: "<<average<<endl;
    
    return 0;
}


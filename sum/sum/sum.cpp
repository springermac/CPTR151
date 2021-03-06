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
    int count=0;
    float sumPositive=0;
    float sumNegative=0;
    float averagePositive=0;
    float averageNegative=0;
    float sum=0;
    float average=0;
    int i;
    string dummy;
    
    cout<<"Enter 10 numbers seperated by a space. Press return after last number."<<endl;
    cout<<"Numbers: ";
    for (i=0; i<NUMBER_OF_INPUTS; i++) { //Accept only as many numbers from the console as the const NUMBER_OF_INPUTS specifies
        cin>>values[i];
        if (!cin.fail()) {
            count++;
        }
        else if (cin.eof()) {
            return 0;
        }
        else {
            cin.clear();
            cin >> dummy;
            cout<<"Entry "<<i+1<<" is not a valid number"<<endl;
        }
    }
    
    /*
     Test each value in values array
    */
    for (i=0; i<NUMBER_OF_INPUTS; i++) {
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
    
    for (i=0; i<countOfPositive; i++) {
        sumPositive=positive[i]+sumPositive;
    }
    averagePositive=(1.0*sumPositive)/countOfPositive;
    
    for (i=0; i<countOfNegative; i++) {
        sumNegative=negative[i]+sumNegative;
    }
    averageNegative=(1.0*sumNegative)/countOfNegative;
    
    for (i=0; i<10; i++) {
        sum=sum+values[i];
    }
    average=(1.0*sum)/count;
    
    cout<<"Sum of positive numbers: "<<sumPositive<<endl;
    cout<<"Average of positive numbers: "<<averagePositive<<endl;
    cout<<"Sum of negative numbers: "<<sumNegative<< endl;
    cout<<"Average of negative numbers: "<<averageNegative<<endl;
    cout<<"Sum of all numbers: "<<sum<<endl;
    cout<<"Average of all numbers: "<<average<<endl;
    
    return 0;
}
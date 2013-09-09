//
//  peasPerPod.cpp
//  peasPerPod
//
//  Created by Jonathan Springer on 9/3/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
//  Description: This program calculates the number of peas given the number of pods and the number of peas per pod.
//

#include <iostream>
using namespace std;

int main()
{
    int numberOfPods;//Variable to hold the number of pods
    int peasPerPod;//Variable to hold the number of peas per pod
    int totalPeas;//Variable to hold the total number of peas
    
    cout<<endl<<"Press return after entering a number."<<endl;//Give instructions on how to enter the number of pods and peas per pod
    cout<<"Enter the number of pods:"<<endl;//Prompts for the number of pods
    
    cin>>numberOfPods;//Stores the input form the console to the variable numberOfPods
    
    cout<<"Enter the number of peas per pod:"<<endl;//Prompts for the number of peas per pod
    cin>>peasPerPod;//Stores the input form the console to the variable peasPerPod
    
    /*Calculates the total number of peas by multiplying the number of pods by the number of peas per pod*/
    totalPeas=numberOfPods*peasPerPod;
    
    cout<<"If you have "<<numberOfPods<<" pea pods"<<endl;//Displays the number of pods
    cout<<"and "<<peasPerPod<<" peas in each pod, then"<<endl;//Displays the number of peas per pod
    cout<<"you have "<<totalPeas<<" peas in all the pods.";//Displays the total number of peas
    
    return 0;
}
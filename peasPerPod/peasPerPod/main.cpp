//
//  main.cpp
//  dis
//
//  Created by Jonathan Springer on 9/3/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int numberOfPods;
    int peasPerPod;
    int totalPeas;
    
    cout<<"Press return after entering a number.\n";
    cout<<"Enter the number of pods:\n";
    
    cin>>numberOfPods;
    
    cout<<"Enter the number of peas per pod:\n";
    cin>>peasPerPod;
    
    totalPeas=numberOfPods*peasPerPod;
    
    cout<<"If you have "<<numberOfPods<<" pea pods\n";
    cout<<"and "<<peasPerPod<<" peas in each pod, then\n";
    cout<<"you have "<<totalPeas<<" peas in all the pods.";
    
    return 0;
}
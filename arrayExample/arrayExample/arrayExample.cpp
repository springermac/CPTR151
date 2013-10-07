//
//  arrayExample.cpp
//  arrayExample
//
//  Created by Jonathan Springer on 10/2/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
	const int NUM_EMPLOYEES=6;
	int hours[NUM_EMPLOYEES];
	int count;
	
	for (count=0; count<NUM_EMPLOYEES; count++) {
		cout<<"Enter the hours worked for employee "<<count+1<<": ";
		cin>>hours[count];
	}
	
	for (count=0; count<NUM_EMPLOYEES; count++) {
		cout<<"Hours employee "<<count+1<<" worked: "<<hours[count]<<endl;
	}
	
    return 0;
}
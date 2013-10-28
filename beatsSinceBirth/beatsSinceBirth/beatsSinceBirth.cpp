//
//  beatsSinceBirth.cpp
//  beatsSinceBirth
//
//  Created by Jonathan Springer on 10/27/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
//	Description: Promt for the users age and heart rate in beats per minute. Then calculate and display the number of
//	beats since they where born.
//

#include <iostream>
using namespace std;

void beatsSinceBirth(int age, int heartRate); //Function to calculate and display how many time the users heart has beat\
											  since they where born based on their age and heart rate.

int main()
{
	int age;
	int heartRate;
	
	cout<<"Please enter your age: ";
	cin>>age;
	cout<<"Please enter your heart rate in beats per minute: ";
	cin>>heartRate;
	
	beatsSinceBirth(age, heartRate); //Call function to calculate and display the number of times the users heart has\
									 beat since they where born.
	
    return 0;
}

void beatsSinceBirth(int age, int heartRate) { //Function to calculate and display how many time the users heart has\
											   beat since they where born based on their age and heart rate.
	int totalBeats;
	
	totalBeats=age*heartRate*1440*365; //Multiply the users age by their heart rate by the number of minutes in a day\
									   the number of days in a year.
	
	cout<<"Your heart has beat "<<totalBeats<<" times since your where born."<<endl;
}
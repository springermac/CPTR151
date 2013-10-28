//
//  temperatureConversion.cpp
//  temperatureConversion
//
//  Created by Jonathan Springer on 10/27/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

float convert(char type, float temp);

int main()
{
	char type;
	float temp;
	
	cout<<"Please enter a tempurature: ";
	cin>>temp;
	cout<<"Please enter the measurement unit Celcius or Fahrenheit: C/F ";
	cin>>type;
	
	temp=convert(type, temp);
	if (temp=='f') {
		cout<<"Please enter a valid temperature type C/F"<<endl<<endl;
		main();
	}
	else if (type=='f'||type=='F') {
		cout<<"The tempurature in Celcius is "<<temp<<endl<<endl;
	}
	else {
		cout<<"The tempurature in Fahrenheit is "<<temp<<endl<<endl;
	}
	
    return 0;
}

float convert(char type, float temp) {
	if (type=='f'||type=='F') {
		temp=(temp-32);
		temp=temp*5;
		temp=temp/9;
	}
	else if (type=='c'||type=='C') {
		temp=temp+32;
		temp=temp*9;
		temp=temp/5;
	}
	else {
		return 'f';
	}
	
	return temp;
}
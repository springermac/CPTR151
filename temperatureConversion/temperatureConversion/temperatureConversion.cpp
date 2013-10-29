//
//  temperatureConversion.cpp
//  temperatureConversion
//
//  Created by Jonathan Springer on 10/27/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
//	Description: Converts a Fahrenheit or Celsius temperature to Celsius or Fahrenheit respectively.
//

#include <iostream>
using namespace std;

float convert(char type, float temp); //Function to convert Fahrenheit to Celsius or Celsius to Fahrenheit

int main()
{
	char type; //Temperature type
	float temp; //Temperature
	
	cout<<"Please enter a temperature: ";
	cin>>temp;
	cout<<"Please enter the measurement unit Celsius or Fahrenheit: C/F ";
	cin>>type;
	
	temp=convert(type, temp); //Send the temperature and type to the conversion function and store the output to temp
	if (temp=='f') { //If the function fails it returns the char f so we can display an error
		cout<<"Please enter a valid temperature type C/F"<<endl<<endl;
		main();
	}
	else if (type=='f'||type=='F') { //If the input type is f or F display the output in Celsius
		cout<<"The temperature in Celsius is "<<temp<<endl<<endl;
	}
	else { //If the input type is c or C display the output in Fahrenheit
		cout<<"The temperature in Fahrenheit is "<<temp<<endl<<endl;
	}
	
    return 0;
}

float convert(char type, float temp) {
	if (type=='f'||type=='F') { //If the type is f or F convert the input temp to Celsius
		temp=(temp-32);
		temp=temp*5;
		temp=temp/9;
	}
	else if (type=='c'||type=='C') { //If the type is c or C convert the input temp to Fahrenheit
		temp=temp+32;
		temp=temp*9;
		temp=temp/5;
	}
	else {
		return 'f'; //If the type isn't f, F, c or C return f to represent an error
	}
	
	return temp;
}
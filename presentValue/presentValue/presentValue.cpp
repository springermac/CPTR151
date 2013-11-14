//
//  presentValue.cpp
//  presentValue
//
//  Created by Jonathan Springer on 11/14/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;


void presentValue(float *futureValue, float *annualInterestRate, float *years,	float *depositeNeeded);

int main()
{
	float depositeNeeded;
	float futureValue;
	float annualInterestRate;
	float years;
	
	cout<<"Please enter the amount of money you want to have in the future: ";
	cin>>futureValue;
	cout<<"Please enter the annual interest rate: ";
	cin>>annualInterestRate;
	cout<<"Please enter the number of years you want to invest the money for: ";
	cin>>years;
	
	futureValue=round(futureValue*100)/100;
	annualInterestRate=round(annualInterestRate*100)/100;
	years=round(years*10)/10;
	
	presentValue(&futureValue, &annualInterestRate, &years, &depositeNeeded);
	
	depositeNeeded=round(depositeNeeded*100)/100;
	
	cout<<"If you deposit $"<<depositeNeeded<<" now and it accrues for "<<years<<" years at an annual interest rate of "<<annualInterestRate<<"% you will have $"<<futureValue<<" after "<<years<<" years"<<endl;
	
    return 0;
}

void presentValue(float *futureValue, float *annualInterestRate, float *years, float *depositeNeeded) {
	*depositeNeeded=*futureValue/((1+*annualInterestRate)*(*years));
}
//
//  interest.cpp
//  interest
//
//  Created by Jonathan Springer on 10/1/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

double interest(double initialBalance,double monthlyRate,double numberOfMonths);

int main()
{
	char runAgain;
	do {
		double initialBalance;
		double monthlyRate;
		double interestDue;
		int numberOfMonths;
		
		cout<<"Enter the begining balance: ";
		cin>>initialBalance;
		cout<<"Enter the monthly rate: ";
		cin>>monthlyRate;
		cout<<"Enter the number of months to calculate the interest for: ";
		cin>>numberOfMonths;
		
		interestDue=interest(initialBalance,monthlyRate,numberOfMonths);
		
		cout<<"Interest Due: "<<interestDue<<endl;
		
		cout<<"Do you want to run the program again? Y/N ";
		cin>>runAgain;
		
	} while (runAgain=='y'||runAgain=='Y');
	
	return 0;
}

double interest(double initialBalance,double monthlyRate,double numberOfMonths) {
	double interestDue;
	double interest;
	double balance=initialBalance;
	while (numberOfMonths>0) {
		interest=balance*monthlyRate;
		balance=balance+interest;
		numberOfMonths--;
	}
	interestDue=balance-initialBalance;
	return interestDue;
}
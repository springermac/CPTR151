//
//  pay.cpp
//  pay
//
//  Created by Jonathan Springer on 9/18/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    const double RATE_PER_HOUR=16.78;
	const int HOURS_BEFORE_OVERTIME=40;
	const double OVERTIME_RATE_MULTIPLIER=1.5;
	const double SOCIAL_SECURITY_TAX_PERCENTAGE=0.06; //Percent of gross pay with held for Social Security tax.
	const double FEDERAL_INCOME_TAX_PERCENTAGE=0.14; //Percent of gross pay with held for Federal Income tax.
	const double STATE_INCOME_TAX_PERCENTAGE=0.05; //Percent of gross pay with held for State Income tax.
	const int UNION_DUES=10;
	const int DEPENDENT_HEALTH_INSUARANCE_WITHHELD=35;
	double hoursWorked;
	int numberOfDependents;
	double grossPay;
	double SSWithheld;
	double fedWithheld;
	double stateWithheld;
	double netPay;
	
	cout<<"Please enter the number of hours you worked followed by enter: ";
	cin>>hoursWorked;
	cout<<"Please enter the number of dependents followed by enter: ";
	cin>>numberOfDependents;
	
	if (hoursWorked<=HOURS_BEFORE_OVERTIME) {
		grossPay=RATE_PER_HOUR*hoursWorked;
	}
	else {
		grossPay=RATE_PER_HOUR*OVERTIME_RATE_MULTIPLIER*(hoursWorked-HOURS_BEFORE_OVERTIME*1.0);
	}
	
	cout<<"Gross pay: $"<<grossPay<<endl;
	
	SSWithheld=grossPay*SOCIAL_SECURITY_TAX_PERCENTAGE;
	cout<<"Social Security tax withheld: $"<<SSWithheld;
	
	fedWithheld=grossPay*FEDERAL_INCOME_TAX_PERCENTAGE;
	cout<<"Federal Income tax withheld: $"<<fedWithheld;
	
	stateWithheld=grossPay*STATE_INCOME_TAX_PERCENTAGE;
	cout<<"State Income tax withheld: $"<<stateWithheld;
	
	cout<<"Union dues withheld: $"<<UNION_DUES;

    return 0;
}


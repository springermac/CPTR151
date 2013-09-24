//
//  pay.cpp
//  pay
//
//  Created by Jonathan Springer on 9/18/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdarg>
using namespace std;

void output(char input);

int main() {
	
	char runAgain;
	
	do {
	    const double RATE_PER_HOUR=16.78;
		const int HOURS_BEFORE_OVERTIME=40;
		const double OVERTIME_RATE_MULTIPLIER=1.5;
		const double SOCIAL_SECURITY_TAX_PERCENTAGE=6; //Percent of gross pay with held for Social Security tax.
		const double FEDERAL_INCOME_TAX_PERCENTAGE=14; //Percent of gross pay with held for Federal Income tax.
		const double STATE_INCOME_TAX_PERCENTAGE=5; //Percent of gross pay with held for State Income tax.
		const double UNION_DUES=10;
		const double DEPENDENT_HEALTH_INSUARANCE_WITHHELD=35;
		int numberOfDependents;
		double hoursWorked;
		double overTimeHours;
		double normalPay;
		double overTimePay;
		double grossPay;
		double SSWithheld;
		double fedWithheld;
		double stateWithheld;
		double netPay;
		stringstream outSSLeft;
		stringstream outSSMid;
		stringstream outSSRight;
		stringstream outNormalPayLeft;
		stringstream outNormalPayMid;
		stringstream outNormalPayRight;
		stringstream outOvertimePayLeft;
		stringstream outOvertimePayMid;
		stringstream outOvertimePayRight;
		stringstream outGrossPayLeft;
		stringstream outGrossPayRight;
		stringstream outFedLeft;
		stringstream outFedMid;
		stringstream outFedRight;
		stringstream outStateLeft;
		stringstream outStateMid;
		stringstream outStateRight;
		stringstream outUnionDuesLeft;
		stringstream outUnionDuesRight;
		stringstream outNumberOfDependentsLeft;
		stringstream outNumberOfDependentsRight;
		stringstream outNetPayLeft;
		stringstream outNetPayMid;
		stringstream outNetPayRight;
		
		cout<<"Please enter the number of hours you worked followed by the enter key: ";
		cin>>hoursWorked;
		cout<<"Please enter the number of dependents followed by the enter key: ";
		cin>>numberOfDependents;
		cout<<endl<<endl;
		
		if (hoursWorked<=HOURS_BEFORE_OVERTIME) {
			grossPay=RATE_PER_HOUR*hoursWorked;
			outNormalPayLeft<<"Normal pay:";
			outNormalPayMid<<"$"<<RATE_PER_HOUR<<" * "<<hoursWorked<<" hours";
			outNormalPayRight<<" = $"<<round(grossPay*100)/100<<endl;
			outGrossPayLeft<<"Gross pay:";
			outGrossPayRight<<"$"<<round(grossPay*100)/100<<endl<<endl;
			output(2,'$',grossPay);
		}
		else {
			overTimeHours=hoursWorked-HOURS_BEFORE_OVERTIME;
			normalPay=RATE_PER_HOUR*OVERTIME_RATE_MULTIPLIER*overTimeHours;
			overTimePay=HOURS_BEFORE_OVERTIME*RATE_PER_HOUR;
			grossPay=overTimePay+normalPay;
			outNormalPayLeft<<"Normal pay:";
			outNormalPayMid<<"$"<<RATE_PER_HOUR<<" * "<<HOURS_BEFORE_OVERTIME<<" hours";
			outNormalPayRight<<" = $"<<normalPay<<endl;
			outOvertimePayLeft<<"Overtime pay:";
			outOvertimePayMid<<"$"<<RATE_PER_HOUR*OVERTIME_RATE_MULTIPLIER<<" * "<<overTimeHours<<" hours";
			outOvertimePayRight<<" = $"<<round(overTimePay*100)/100<<endl;
			outGrossPayLeft<<"Gross pay:";
			outGrossPayRight<<"$"<<round(grossPay*100)/100<<endl<<endl;
		}
		
		SSWithheld=grossPay*(SOCIAL_SECURITY_TAX_PERCENTAGE/100);
		outSSLeft<<"Social Security tax withheld:";
		outSSMid<<"$"<<round(grossPay*100)/100<<" * "<<SOCIAL_SECURITY_TAX_PERCENTAGE<<"%";
		outSSRight<<" = $"<<round(SSWithheld*100)/100.00<<endl;
		
		fedWithheld=grossPay*(FEDERAL_INCOME_TAX_PERCENTAGE/100);
		outFedLeft<<"Federal Income tax withheld:";
		outFedMid<<"$"<<grossPay<<" * "<<FEDERAL_INCOME_TAX_PERCENTAGE<<"%";
		outFedRight<<" = $"<<round(fedWithheld*100)/100.00<<endl;
		
		stateWithheld=grossPay*(STATE_INCOME_TAX_PERCENTAGE/100);
		outStateLeft<<"State Income tax withheld:";
		outStateMid<<"$"<<grossPay<<" * "<<STATE_INCOME_TAX_PERCENTAGE<<"%";
		outStateRight<<" = $"<<round(stateWithheld*100)/100<<endl;
		
		outUnionDuesLeft<<"Union dues withheld:";
		outUnionDuesRight<<"$"<<round(UNION_DUES*100)/100<<endl;
		
		if (numberOfDependents>=3) {
			netPay=grossPay-(SSWithheld+fedWithheld+stateWithheld+UNION_DUES+DEPENDENT_HEALTH_INSUARANCE_WITHHELD);
			outNumberOfDependentsLeft<<"Three or more dependents, withholding extra health insurance:";
			outNumberOfDependentsRight<<"$"<<DEPENDENT_HEALTH_INSUARANCE_WITHHELD<<endl;
			outNetPayLeft<<endl<<"Net pay is:";
			outNetPayMid<<"$"<<round(grossPay*100)/100<<" - ($"<<round(SSWithheld*100)/100<<" + $"<<round(fedWithheld*100)/100<<" + $"<<round(stateWithheld*100)/100<<" + $"<<UNION_DUES<<" + $"<<DEPENDENT_HEALTH_INSUARANCE_WITHHELD<<")";
			outNetPayRight<<" = $"<<round(netPay*100)/100<<endl;
		}
		else {
			netPay=grossPay-(SSWithheld+fedWithheld+stateWithheld+UNION_DUES);
			outNumberOfDependentsLeft<<"Less than three dependents, no extra health insurance withheld:";
			outNumberOfDependentsRight<<"$0"<<endl;
			outNetPayLeft<<endl<<"Net pay is:";
			outNetPayMid<<"$"<<round(grossPay*100)/100<<" - ($"<<round(SSWithheld*100)/100<<" + $"<<round(fedWithheld*100)/100<<" + $"<<round(stateWithheld*100)/100<<" + $"<<UNION_DUES<<")";
			outNetPayRight<<" = $"<<round(netPay*100)/100<<endl;
		}
		
		if (hoursWorked<=HOURS_BEFORE_OVERTIME) {
			cout<<left<<outNormalPayLeft.str();
			cout.width(60);
			cout<<right<<outNormalPayMid.str();
			cout.width(10);
			cout<<left<<outNormalPayRight.str();
			cout<<left<<outGrossPayLeft.str();
			cout.width(72);
			cout<<right<<outGrossPayRight.str();
		}
		else {
			cout<<left<<outNormalPayLeft.str();
			cout.width(60);
			cout<<right<<outNormalPayMid.str();
			cout.width(10);
			cout<<left<<outNormalPayRight.str();
			cout<<left<<outOvertimePayLeft.str();
			cout.width(58);
			cout<<right<<outOvertimePayMid.str();
			cout.width(10);
			cout<<left<<outOvertimePayRight.str();
			cout<<left<<outGrossPayLeft.str();
			cout.width(73);
			cout<<right<<outGrossPayRight.str();
		}
		cout<<left<<outSSLeft.str();
		cout.width(42);
		cout<<right<<outSSMid.str();
		cout.width(10);
		cout<<left<<outSSRight.str();
		cout<<left<<outFedLeft.str();
		cout.width(43);
		cout<<right<<outFedMid.str();
		cout.width(10);
		cout<<left<<outFedRight.str();
		cout<<left<<outStateLeft.str();
		cout.width(45);
		cout<<right<<outStateMid.str();
		cout.width(10);
		cout<<left<<outStateRight.str();
		cout<<left<<outUnionDuesLeft.str();
		cout.width(58);
		cout<<right<<outUnionDuesRight.str();
		cout.width(70);
		cout<<left<<outNumberOfDependentsLeft.str();
		cout.width(8);
		cout<<right<<outNumberOfDependentsRight.str();
		cout<<left<<outNetPayLeft.str();
		cout.width(60);
		cout<<right<<outNetPayMid.str();
		cout<<left<<outNetPayRight.str();
		
		cout<<endl<<"Do you want to run again? Y/N ";
		cin>>runAgain;
		
	} while (runAgain=='y'||runAgain=='Y');

    return 0;
}

void output(char input, ...) {
	double val;
	vector <double> record;
	va_list args;
	va_start(args,input);
	for (int i=0;i<input;i++)
	{
		val=va_arg(args,double);
		cout<<val;
	}
	va_end(args);
	/*while (getline( ss, field, ',' ))
    {
		// for each field we wish to convert it to a double
		// (since we require that the CSV contains nothing but floating-point values)
		stringstream fs( field );
		double f = 0.0;  // (default value is 0.0)
		fs >> f;
		
		// add the newly-converted field to the end of the record
		record.push_back(f);
    }
	cout<<record[3];*/
}


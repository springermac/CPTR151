//
//  pay.cpp
//  pay
//
//  Created by Jonathan Springer on 9/18/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
// Description: Compute the gross pay, all tax deductions, fees, and the net pay based on the number of hours worked
//				and number of dependents.
//

#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

void output(char input);

int main() {
	
	char runAgain;
	
	do {
	    const double RATE_PER_HOUR=16.78; // Base pay rate per hour
		const int HOURS_BEFORE_OVERTIME=40; // Hours an employee can work before they are payed overtime
		const double OVERTIME_RATE_MULTIPLIER=1.5; // Multiplier for overtime pay
		const double SOCIAL_SECURITY_TAX_PERCENTAGE=6; // Percent of gross pay with held for Social Security tax.
		const double FEDERAL_INCOME_TAX_PERCENTAGE=14; // Percent of gross pay with held for Federal Income tax.
		const double STATE_INCOME_TAX_PERCENTAGE=5; // Percent of gross pay with held for State Income tax.
		const double UNION_DUES=10; // Amount of money payed for union membership
		const double DEPENDENT_HEALTH_INSUARANCE_WITHHELD=35; // Amount of money withheld for insuarance if the number\
															  of dependents is three or more
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
		/*
		 Variables to hold strings for display. These strings are displayed as blocks that are left or right justified.
		*/
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
		
		/*
		 Checks if the number of hours worked is greater than 40 hours and if it is adds overtime pay for the hours past 40
		*/
		if (hoursWorked<=HOURS_BEFORE_OVERTIME) {
			grossPay=RATE_PER_HOUR*hoursWorked; // Calculate gross pay from the hours worked times the pay rate
			/*
			 These lines store the output lines to strings that are displayed later. Each line is a block the can be
			 displayed independently.
			*/
			outNormalPayLeft<<"Normal pay:";
			outNormalPayMid<<"$"<<RATE_PER_HOUR<<" * "<<hoursWorked<<" hours";
			outNormalPayRight<<" = $"<<round(grossPay*100)/100<<endl;
			outGrossPayLeft<<"Gross pay:";
			outGrossPayRight<<"$"<<round(grossPay*100)/100<<endl<<endl;
		}
		else {
			overTimeHours=hoursWorked-HOURS_BEFORE_OVERTIME; // Calculate the number of hours worked past the\
															 HOURS_BEFORE_OVERTIME constant
			overTimePay=RATE_PER_HOUR*OVERTIME_RATE_MULTIPLIER*overTimeHours; // Calculate the pay for the number of\
																			  hours worked past the HOURS_BEFORE_OVERTIME\
																			  constant
			normalPay=HOURS_BEFORE_OVERTIME*RATE_PER_HOUR; // Calculate the pay for the hours before overtime
			grossPay=overTimePay+normalPay; // Add the two values overTimePay and normalPay to get the gross pay
			/*
			 These lines store the output lines to strings that are displayed later. Each line is a block the can be
			 displayed independently.
			*/
			outNormalPayLeft<<"Normal pay:";
			outNormalPayMid<<"$"<<RATE_PER_HOUR<<" * "<<HOURS_BEFORE_OVERTIME<<" hours";
			outNormalPayRight<<" = $"<<normalPay<<endl;
			outOvertimePayLeft<<"Overtime pay:";
			outOvertimePayMid<<"$"<<RATE_PER_HOUR*OVERTIME_RATE_MULTIPLIER<<" * "<<overTimeHours<<" hours";
			outOvertimePayRight<<" = $"<<round(overTimePay*100)/100<<endl;
			outGrossPayLeft<<"Gross pay:";
			outGrossPayRight<<"$"<<round(grossPay*100)/100<<endl<<endl;
		}
		
		SSWithheld=grossPay*(SOCIAL_SECURITY_TAX_PERCENTAGE/100); // Calculate the amount of money withheld for social\
																  security
		/*
		 These lines store the output lines to strings that are displayed later. Each line is a block the can be
		 displayed independently.
		*/
		outSSLeft<<"Social Security tax withheld:";
		outSSMid<<"$"<<round(grossPay*100)/100<<" * "<<SOCIAL_SECURITY_TAX_PERCENTAGE<<"%";
		outSSRight<<" = $"<<round(SSWithheld*100)/100.00<<endl;
		
		fedWithheld=grossPay*(FEDERAL_INCOME_TAX_PERCENTAGE/100); // Calculate the amount of money withheld for federal\
																  income tax
		/*
		 These lines store the output lines to strings that are displayed later. Each line is a block the can be
		 displayed independently.
		*/
		outFedLeft<<"Federal Income tax withheld:";
		outFedMid<<"$"<<grossPay<<" * "<<FEDERAL_INCOME_TAX_PERCENTAGE<<"%";
		outFedRight<<" = $"<<round(fedWithheld*100)/100.00<<endl;
		
		stateWithheld=grossPay*(STATE_INCOME_TAX_PERCENTAGE/100); // Calculate the amount of money withheld for state\
																  income tax
		/*
		 These lines store the output lines to strings that are displayed later. Each line is a block the can be
		 displayed independently.
		*/
		outStateLeft<<"State Income tax withheld:";
		outStateMid<<"$"<<grossPay<<" * "<<STATE_INCOME_TAX_PERCENTAGE<<"%";
		outStateRight<<" = $"<<round(stateWithheld*100)/100<<endl;
		
		/*
		 These lines store the output lines to strings that are displayed later. Each line is a block the can be
		 displayed independently.
		*/
		outUnionDuesLeft<<"Union dues withheld:";
		outUnionDuesRight<<"$"<<round(UNION_DUES*100)/100<<endl;
		
		/*
		 Checks the number of dependents and calculate the net pay accordingly
		*/
		if (numberOfDependents>=3) {
			/*
			 Calculate the net pay when the number of dependents is three or greater. Add health insuarance when the
			 number of dependents is three or more.
			*/
			netPay=grossPay-(SSWithheld+fedWithheld+stateWithheld+UNION_DUES+DEPENDENT_HEALTH_INSUARANCE_WITHHELD);
			/*
			 These lines store the output lines to strings that are displayed later. Each line is a block the can be
			 displayed independently.
			*/
			outNumberOfDependentsLeft<<"Three or more dependents, withholding extra health insurance:";
			outNumberOfDependentsRight<<"$"<<DEPENDENT_HEALTH_INSUARANCE_WITHHELD<<endl;
			outNetPayLeft<<endl<<"Net pay is:";
			outNetPayMid<<"$"<<round(grossPay*100)/100<<" - ($"<<round(SSWithheld*100)/100<<" + $"<<\
			round(fedWithheld*100)/100<<" + $"<<round(stateWithheld*100)/100<<" + $"<<UNION_DUES<<" + $"<<\
			DEPENDENT_HEALTH_INSUARANCE_WITHHELD<<")";
			outNetPayRight<<" = $"<<round(netPay*100)/100<<endl;
		}
		else {
			/*
			 Calculate the net pay if the number of dependents is less than three. Don't add health insuarance if the
			 number of dependents is less than three.
			*/
			netPay=grossPay-(SSWithheld+fedWithheld+stateWithheld+UNION_DUES);
			/*
			 These lines store the output lines to strings that are displayed later. Each line is a block the can be
			 displayed independently.
			*/
			outNumberOfDependentsLeft<<"Less than three dependents, no extra health insurance withheld:";
			outNumberOfDependentsRight<<"$0"<<endl;
			outNetPayLeft<<endl<<"Net pay is:";
			outNetPayMid<<"$"<<round(grossPay*100)/100<<" - ($"<<round(SSWithheld*100)/100<<" + $"<<\
			round(fedWithheld*100)/100<<" + $"<<round(stateWithheld*100)/100<<" + $"<<UNION_DUES<<")";
			outNetPayRight<<" = $"<<round(netPay*100)/100<<endl;
		}
		
		/*
		 This block of code displays the output from the previous code.
		 cout<<left will display the line left justified within a block of characters.
		 The block of characters is the same as the number of characters in the string unless cout.width() is used to
		 override the number of characters. cout.width(char) were char is the number of characters to make the block.
		 These blocks are used to pad the output and keep all output aligned regarless of the terminal or tab width.
		*/
		if (hoursWorked<=HOURS_BEFORE_OVERTIME) { // Change the output layout if overtime is payed
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
		
		cout<<endl<<"Do you want to run again? Y/N "; // Prompt the user asking if they want to run again
		cin>>runAgain; // Get the users intention
		
	} while (runAgain=='y'||runAgain=='Y'); // If the user wants to run again loop

    return 0;
}
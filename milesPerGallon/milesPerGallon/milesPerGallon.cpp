//
//  milesPerGallon.cpp
//  milesPerGallon
//
//  Created by Jonathan Springer on 9/23/13.
//
//

#include <iostream>
using namespace std;

double calcMPG(double begMiles, double endMiles, double gallonsUsed);
void eval(double total);

int main()
{
	double begMiles;
	double endMiles;
	double gallonsUsed;
	double totalMPG;
	
	cout<<"Enter begining miles";
	cin>>begMiles;
	cout<<"Enter ending miles";
	cin>>endMiles;
	cout<<"Enter gallons used";
	cin>>gallonsUsed;
	
	totalMPG=calcMPG(begMiles, endMiles, gallonsUsed);
	
	cout<<"MPG: "<<totalMPG;
	
	eval(totalMPG);

	return 0;
}

double calcMPG(double begMiles, double endMiles, double gallonsUsed) {
	double totalMPG;
	totalMPG=(endMiles-begMiles)/gallonsUsed;
	return totalMPG;
}
void eval(double total) {
	if (total<10) {
		cout<<"Sell it";
	}
}
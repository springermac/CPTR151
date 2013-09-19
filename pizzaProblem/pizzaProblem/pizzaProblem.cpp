//
//  pizzaProblem.cpp
//  pizzaProblem
//
//  Created by Jonathan Springer on 9/19/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
	const double PI=3.14159;
	double diameterSmall;
	double diameterLarge;
	double priceSmall;
	double priceLarge;
	double pricePerInchLarge;
	double pricePerInchSmall;
	
	cout<<"Enter the diameter of the larger pizza: ";
	cin>>diameterLarge;
	cout<<"Enter the price of the larger pizza: ";
	cin>>priceLarge;
	
	cout<<"Enter the diameter of the smaller pizza: ";
	cin>>diameterSmall;
	cout<<"Enter the price of the smaller pizza: ";
	cin>>priceSmall;
	
	pricePerInchLarge=priceLarge/((diameterLarge/2)*(diameterLarge/2)*PI);
	pricePerInchSmall=priceSmall/((diameterSmall/2)*(diameterSmall/2)*PI);
	
	if (pricePerInchLarge==pricePerInchSmall) {
		cout<<"Both pizzas are the same value";
	}
	else if (pricePerInchLarge>pricePerInchSmall) {
		cout<<"Smaller pizza is the better deal";
	}
	else if (pricePerInchLarge<pricePerInchSmall) {
		cout<<"Larger pizza is the better deal";
	}
	else {
		//Something is very wrong
	}
	
	cout<<endl;
	
    return 0;
}


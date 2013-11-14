//
//  stockProfit.cpp
//  stockProfit
//
//  Created by Jonathan Springer on 11/13/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
	char cont;
	
	do {
		float numberOfShares;
		float salePricePerShare;
		float saleCommisionPaid;
		float purchasePricePerShare;
		float purchaseCommisionPaid;
		float profit;
		
		cout<<"Number of shares: ";
		cin>>numberOfShares;
		cout<<"Purchase price of share: ";
		cin>>purchasePricePerShare;
		cout<<"Purchase commision of shares: ";
		cin>>purchaseCommisionPaid;
		cout<<"Sale price of share: ";
		cin>>salePricePerShare;
		cout<<"Sale commision of shares: ";
		cin>>saleCommisionPaid;
		
		profit=((numberOfShares*salePricePerShare)-saleCommisionPaid)-((numberOfShares*purchasePricePerShare)+purchaseCommisionPaid);
		
		if (profit>0) {
			cout<<"Gain of "<<profit<<endl;
		}
		else if (profit<0) {
			cout<<"Loss of "<<profit<<endl;
		}
		else if (profit==0) {
			cout<<"No gain or loss"<<endl;
		}
		
		cout<<"Do you wnat to run again? Y/N ";
		cin>>cont;
	} while (cont=='y'||cont=='Y');
    return 0;
}


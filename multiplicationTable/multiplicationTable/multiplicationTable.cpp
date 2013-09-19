//
//  multiplicationTable.cpp
//  multiplicationTable
//
//  Created by Jonathan Springer on 9/19/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
	cout<<"\t\t\tWhat is the output"<<endl;
	cout<<"   ";
	for (int j=1; j<=9; j++) {
		cout<<"   "<<j;
	}
	
	cout<<endl<<"---------------------------------------";
	cout<<endl;
	
	for (int row=1; row<=9; row++) {
		cout<<row<<" |";
		for (int col=1; col<=9; col++) {
			if (row*col<10) {
				cout<<"   "<<row*col;
			} else {
				cout<<"  "<<row*col;
			}
		}
		cout<<endl;
	}
	
    return 0;
}


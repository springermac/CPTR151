//
//  accountNumber.cpp
//  accountNumber
//
//  Created by Jonathan Springer on 11/13/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

bool search(int id[], int key);

int main()
{
	int id[]={4506044,6049389,3094959,3040506,7899898,2300505,8739483,9874623,1212345,1180980,8998443,4566632};
	int key;
	bool result;
	
	cout<<"Please enter a user ID: ";
	cin>>key;
	
	result=search(id, key);
	if (result==true) {
		cout<<"ID is valid"<<endl;
	}
	else if (result==false) {
		cout<<"ID not found"<<endl;
	}
	else {
		cout<<"Error";
	}
	
    return 0;
}

bool search(int id[], int key) {
	for (int i=0; i<12; i++) {
		if (id[i]==key) {
			return true;
		}
	}
	return false;
}
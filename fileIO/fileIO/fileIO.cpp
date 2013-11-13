//
//  fileIO.cpp
//  fileIO
//
//  Created by Jonathan Springer on 11/4/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int number;
	int sum=0;
	int output;
	ofstream outputFile;
	ifstream inputFile;
	outputFile.open("/Users/jonathanspringer/test.txt");
	
	for (int i=0; i<10; i++) {
		cout<<"Please enter a number: ";
		cin>>number;
		outputFile<<number<<endl;
	}

	outputFile.close();
	
	cout<<"Done."<<endl;
	
	inputFile.open("/Users/jonathanspringer/test.txt");
	
	cout<<"Now reading data from file."<<endl;
	
	for (int i=0; i<10; i++) {
		inputFile>>output;
		cout<<output<<endl;
		sum=sum+output;
	}
	
	cout<<"Sum of the numbers "<<sum<<endl;
	
	inputFile.close();

	cout<<"Done."<<endl;
    return 0;
}


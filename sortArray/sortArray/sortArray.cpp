//
//  sortArray.cpp
//  sortArray
//
//  Created by Jonathan Springer on 10/8/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void showValues(int values[],int size);
void sortArray(int values[],int size);
void searchArray(int values[],int lowerBound,int upperBound,int key);

int main()
{
	unsigned seed = time(0);
	srand(seed);
	
	const int size=100;
	int values[size];
	int key;
	for (int i=0; i<size; i++) {
		values[i]=rand()%100+1;
	}
	
	sortArray(values, size);
	showValues(values, size);
	cout<<"Enter number: ";
	cin>>key;
	searchArray(values,0,size,key);
	
    return 0;
}

void showValues(int values[],int size) {
	for (int i=0; i<size; i++) {
		cout<<values[i]<<endl;
	}
}

void sortArray(int values[],int size) {
	for (int i=0; i<size; i++) {
		for (int j=0; j<size-1; j++) {
			if (values[j]>values[j+1]) {
				int temp=values[j+1];
				values[j+1]=values[j];
				values[j]=temp;
			}
		}
	}
}

void searchArray(int values[],int lowerBound,int upperBound,int key) {
	
	/*int position;
	
	position=(lowerBound+upperBound)/2;
	
	while (values[position]!=key && lowerBound<=upperBound) {
		if (values[position]>key) {
			upperBound=position-1;
		}
		else {
			lowerBound=position-1;
		}
		position=(lowerBound+upperBound)/2;
	}
	if (lowerBound<=upperBound) {
		cout<<values[position]<<position;
	}
	return;*/
}
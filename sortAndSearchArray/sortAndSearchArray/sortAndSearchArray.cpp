//
//  sortAndSearchArray.cpp
//  sortAndSearchArray
//
//  Created by Jonathan Springer on 10/20/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void generateArray(int array[], int size);
void bubbleSort(int array[], int size);
void sequentialSearch(int array[], int size, int key);
void binarySearch(int array[], int lowerBound, int upperBound, int key);
void output(int array[], int size);

int main() {
	const int size=100;
	int array[size];
	int key;
	
	generateArray(array, size);
	cout<<"Array of random numbers"<<endl;
	output(array, size);
	
	cout<<"Please enter a number to search for: ";
	cin>>key;
	sequentialSearch(array, size, key);
	
	bubbleSort(array, size);
	cout<<"Array of random numbers sorted from least to greatest using bubble sort"<<endl;
	output(array, size);
	binarySearch(array,0,size,key);

    return 0;
}

void generateArray(int array[], int size) {
	srand(time(0));
	
	for (int i=0; i<size; i++) {
		array[i]=(rand()%size)+1;
	}
}

void output(int array[], int size) {
	for (int i=0; i<size; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void bubbleSort(int array[], int size) {
	for (int i=0; i<size; i++) {
		for (int j=0; j<size-1; j++) {
			if (array[j]>array[j+1]) {
				int temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
	}
}

void sequentialSearch(int array[], int size, int key) {
	for (int i=0; i<size; i++) {
		if (key==array[i]) {
			cout<<"Seqential search found the number "<<key<<" at position: "<<i+1<<endl;
		}
	}
}

void binarySearch(int array[], int lowerBound, int upperBound, int key) {
	int position;
	
	position=(lowerBound+upperBound)/2;
	
	while (array[position]!=key && lowerBound<=upperBound) {
		if (array[position]>key) {
			upperBound=position-1;
		}
		if (array[position]<key) {
			lowerBound=position-1;
		}
		position=(lowerBound+upperBound)/2;
	}
	if (lowerBound<=upperBound) {
		cout<<"Binary search found the number "<<key<<" at position: "<<position;
	}
	else {
		cout<<"Binary search did not find the number";
	}
	return;
}
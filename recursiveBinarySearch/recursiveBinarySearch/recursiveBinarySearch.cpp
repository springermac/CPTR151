//
//  recursiveBinarySearch.cpp
//  recursiveBinarySearch
//
//  Created by Jonathan Springer on 11/20/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void random(int array[], const int *size);
void bubbleSort(int array[], const int *size);
int binarySearch(int array[], int key, int low, int high);

int main()
{
	const int size=10;
	int array[size];
	int low=0;
	int high=size-1;
	int position;
	int key;
	
	srand(time(0));
	
	random(array, &size);
	bubbleSort(array, &size);
	for (int i=0; i<size; i++) {
		cout<<array[i]<<endl;
	}
	
	cout<<" ";
	cin>>key;
	
	position=binarySearch(array, key, low, high);
	
	cout<<position;

    return 0;
}

void random(int array[], const int *size) {
	for (int i=0; i<*size; i++) {
		array[i]=rand()%(*size)+1;
	}
}

void bubbleSort(int array[], const int *size) {
	bool swap;
	int temp;
	
	do
	{
		swap = false;
		for (int count = 0; count < (*size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

int binarySearch(int array[], int key, int low, int high) {
	if (high<low) {
		return -1;
	}
	else {
		int mid=(low+high)/2;
		
		if (array[mid]>key) {
			return binarySearch(array, key, low, mid-1);
		}
		else if (array[mid]<key) {
			return binarySearch(array, key, mid+1, high);
		}
		else {
			return mid;
		}
	}
	
	
	return 0;
}
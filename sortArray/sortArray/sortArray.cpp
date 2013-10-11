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

void swapValues(int &v1,int &v2);

int indexOfSmallest(const int a[],int startIndex,int size);

int main()
{
	unsigned seed = time(0);
	srand(seed);
	
	const int size=10000;
	int values[size];
	for (int i=0; i<size; i++) {
		values[i]=rand()%1000+1;
	}
	
	sortArray(values, size);
	showValues(values, size);
	
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
	/*int nextSmallest;
	for (int index=0; index<size-1; index++) {
		nextSmallest=indexOfSmallest(values, index, size);
		swapValues(values[index], values[nextSmallest]);
	}*/
}

void swapValues(int& value1,int& value2) {
	int temp;
	temp=value1;
	value1=value2;
	value2=temp;
}

int indexOfSmallest(const int values[],int startIndex,int size) {
	int min=values[startIndex],indexOfMin=startIndex;
	for (int index=startIndex+1; index<size; index++) {
		if (values[index]<min) {
			min=values[index];
			indexOfMin=index;
		}
	}
	
	return indexOfMin;
}
//
//  twoDimesionalArrays.cpp
//  twoDimesionalArrays
//
//  Created by Jonathan Springer on 10/24/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
	const int size=10;
	int array[size][2];
	
	srand(time(0));
	
	for (int i=0; i<size; i++) {
		for (int j=0; j<2; j++) {
			array[i][j]=rand()%size+1;
		}
	}
	
	for (int i=0; i<size; i++) {
		for (int j=0; j<2; j++) {
			cout.width(2);
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			if (array[j][1]<array[j+1][1]) {
				for (int c=0; c<2; c++) {
					int temp=array[j][c];
					array[j][c]=array[j+1][c];
					array[j+1][c]=temp;
				}
			}
		}
	}
	
	for (int i=0; i<size; i++) {
		for (int j=0; j<2; j++) {
			cout.width(2);
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}


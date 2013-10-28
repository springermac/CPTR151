//
//  sortAndSearchArray.cpp
//  sortAndSearchArray
//
//  Created by Jonathan Springer on 10/20/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//
//  Description: Generate an array of random numbers and display the array. Then search the array for a number input by
//	the user and display the position of the number. Next sort the array from least to greatest and search it again using
//	a different technique for the number the user input and display its position. Average the array and display the result.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void generateArray(int array[], int size); //Function to generate an array populated with random numbers
void bubbleSort(int array[], int size); //Function to run a bubble sort on an array
void sequentialSearch(int array[], int size, int key); //Function to use the sequential search method to find a number\
													   in an unsorted array
void binarySearch(int array[], int lowerBound, int upperBound, int key); //Function to find a number in an array using\
																		 the binary search method
void average(int array[], int size); //Function to calculate the average of an array
void output(int array[], int size); //Function to display all values in an array

int main() {
	char cont;
	
	do {
		const int size=50; //Constant to hold the size of the array
		int array[size]; //Array of "size"
		int key; //Number to be searched for
		
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
		
		average(array,size);
		
		cout<<"Do you want to run again? Y/N "; //Prompt whether to run the program again
		cin>>cont;
	} while (cont=='y'||cont=='Y'); //Loop to the beginning of the program if the user wants to run it again

    return 0;
}

void generateArray(int array[], int size) { //Fill an array with random numbers
	srand(time(0)); //Seed the random number generator once with the current time
	
	for (int i=0; i<size; i++) { //Iterate through the array
		array[i]=(rand()%size)+1;//storing random numbers at each position
	}
}

void bubbleSort(int array[], int size) { //Sort an array using the bubble sort method
	for (int i=0; i<size; i++) { //Iterate through the array
		for (int j=0; j<size-1; j++) { //Iterate through the array
			if (array[j]>array[j+1]) { //Flip the value at the current position with the next positions value if the\
									   current positions value is greater than the next positions value
				int temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
	}
}

void sequentialSearch(int array[], int size, int key) { //Search an array using the sequential search method for the key
	for (int i=0; i<size; i++) { //Iterate through the array until
		if (key==array[i]) {	 //the value at the current position is equal to the key
			cout<<"Sequential search found the number "<<key<<" at position: "<<i+1<<endl;
		}
	}
}

void binarySearch(int array[], int lowerBound, int upperBound, int key) { //Search an array using the binary search\
																		  method for the key
	int position;
	
	upperBound=upperBound-1;
	
	while (lowerBound<=upperBound) { //Check if we have gone through the entire array by checking if the upper and lower\
									 bounds have meet
		position=(lowerBound+upperBound)/2; //Find the center position in the array in-between the upper and lower bound
		if (array[position]==key) { //Check if the center value is the key
			cout<<"Binary search found the number "<<key<<" at position: "<<position+1<<endl;
			break;
		}
		else if (array[position]<key) { //If the value of the center number is less than the key move the lower bound up\
										by one
			lowerBound=position+1;
		}
		else { //If the value of the center number is greater than the key than move the upper bound down by one
			upperBound=position-1;
		}
	}
	return;
}

void average(int array[], int size) { //Compute the average of all the fields in an array
	float average=0;
	
	for (int i=0; i<size; i++) { //Iterate through the arrays
		average=average+array[i]; //Add the current field of the array to the sum of the previous fields
	}
	average=average/size; //Divide the total of all the fields added together by the size of the array
	
	cout<<"The average of the array is "<<average<<endl;
}

void output(int array[], int size) { //Print all the fields of an array to the console
	for (int i=0; i<size; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
//
//  weatherData.cpp
//  weatherData
//
//  Created by Jonathan Springer on 12/4/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <string>
#include <map>
#include <cmath>
using namespace std;

struct WeatherInfo {
	double rain;         // Total rainfall
	double high;         // High temperature
	double low;          // Low temperature
	double monthlyAverageTemp;  // Average temperature
};

void getData(WeatherInfo *, int *, string *, int);
double getInput();
int minMax(WeatherInfo *, const int *, int);
int change(double *);

int main() {
	const int MONTHS = 12;
	WeatherInfo month[MONTHS];
	string nameOfMonths[MONTHS] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	string unitsTable[2][4] = {{"Inches","Inch","Fahrenheit","F"},{"Centimeters","Centimeter","Celsius","C"}};
	map<char, int> test = {{'I',0},{'i',0},{'M',1},{'m',1}};
	
	char units;
	double yearlyAverageTemp = 0.0;
	double totalRainfall = 0.0;
	double averageMonthlyRainfall;
	int highTempMonth;
	int lowTempMonth;
	int unit;

	
	do {
		cout << "Please choose:\nI:\tImperial units (e.g., Inches, Fahrenheit)\nM:\tMetric units (e.g., Centimeters, Celsius)\nI/M: ";
		cin>>units;
		
		units = toupper(units);
		
		unit = test[units];
	} while (!(units == 'M' || units == 'I'));
	
	cout << endl << "Please enter the total rainfall in " << unitsTable[unit][0] << " for ";
	for (int i = 0; i < MONTHS; i++) {
		getData(month, &i, nameOfMonths, 1);
		totalRainfall += month[i].rain;
	}
	cout << endl << "Please enter the high temperature in " << unitsTable[unit][2] << " for ";
	for (int i = 0; i < MONTHS; i++) {
		getData(month, &i, nameOfMonths, 2);
	}
	cout << endl << "Please enter the low temperature in " << unitsTable[unit][2] << " for ";
	for (int i = 0; i < MONTHS; i++) {
		getData(month, &i, nameOfMonths, 3);
		month[i].monthlyAverageTemp=(month[i].high+month[i].low)/2;
		yearlyAverageTemp += month[i].monthlyAverageTemp;
	}
	
	yearlyAverageTemp /= MONTHS;
	averageMonthlyRainfall = totalRainfall/MONTHS;
	highTempMonth = minMax(month, &MONTHS, 1);
	lowTempMonth = minMax(month, &MONTHS, 2);
	
	cout << endl << "The total rainfall for the year is " << round(totalRainfall*100)/100 << " " << unitsTable[unit][change(&totalRainfall)] << "." << endl;
	cout << "The average monthly rainfall for the year is " << round(averageMonthlyRainfall*100)/100 << " " << unitsTable[unit][change(&averageMonthlyRainfall)] << "." << endl;
	cout << "The highest temperature of " << round(month[highTempMonth].high*100)/100 << "˚" << unitsTable[unit][3] << " occured in " << nameOfMonths[highTempMonth] << "." << endl;
	cout << "The lowest temperature of " << round(month[lowTempMonth].low*100)/100 << "˚" << unitsTable[unit][3] << " occured in " << nameOfMonths[lowTempMonth] << "." << endl;
	cout << "The average temperature for the year is " << round(yearlyAverageTemp*100)/100 << "˚" << unitsTable[unit][3] << "." << endl;

    return 0;
}

void getData(WeatherInfo *month, int *i, string nameOfMonths[], int x) {
	cout << nameOfMonths[*i] << ": ";
	switch (x) {
		case 1: {
			month[*i].rain = getInput();
			break;
		}
		case 2: {
			month[*i].high = getInput();
			break;
		}
		case 3: {
			month[*i].low = getInput();
			break;
		}
		default:
			break;
	}
}

double getInput() {
	double input;
	
	while(!(cin >> input)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Please enter a number: ";
	}
	
	return input;
}

int minMax(WeatherInfo *month, const int *MONTHS, int x) {
	switch (x) {
		case 1: {
			double max[2] = {0.0, 0};
			
			max[0] = month[0].high;
			
			for (int i = 0; i < *MONTHS; i++) {
				if (month[i].high > max[0]) {
					max[0] = month[i].high;
					max[1] = i;
				}
			}
			return max[1];
			break;
		}
			
		case 2: {
			double min[2] = {0.0, 0};
			
			min[0] = month[0].low;
			
			for (int i = 0; i < *MONTHS; i++) {
				if (month[i].low < min[0]) {
					min[0] = month[i].low;
					min[1] = i;
				}
			}
			return min[1];
			break;
		}
		default:
			break;
	}
	return -1;
}

int change(double *value) {
	if (*value == 1 || *value == -1) {
		return 1;
	}
	else;
		return 0;
}
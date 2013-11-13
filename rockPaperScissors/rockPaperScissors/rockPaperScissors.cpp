//
//  rockPaperScissors.cpp
//  rockPaperScissors
//
//  Created by Jonathan Springer on 11/7/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void menu(int choice[], string table[][3]);
void getUsersChoice(int choice[]);
void getComputerChoice(int choice[]);
void display(int choice[], string tabel[][3]);


int main()
{
	string table[3][3]={{"Tie","Computer Wins","User Wins"},
						{"User Wins","Tie","Computer Wins"},
						{"Computer Wins","User Wins","Tie"}};
	int choice[2];
	
	srand(time(0));
	
	menu(choice, table);
}

void menu(int choice[], string table[][3]) {
	cout<<"Options"<<endl;
	cout<<"1 Rock"<<endl;
	cout<<"2 Paper"<<endl;
	cout<<"3 Scissors"<<endl;
	cout<<"4 Quit"<<endl;
	cout<<"Please choose: ";
	getUsersChoice(choice);
	if (choice[0]==4) {
		return;
	}
	getComputerChoice(choice);
	display(choice, table);
	menu(choice, table);
}

void getUsersChoice(int choice[]) {
	cin>>choice[0];
	while (choice[0]>4) {
		cout<<"Please enter a valid choice: ";
		cin>>choice[0];
	}
}

void getComputerChoice(int choice[]) {
	choice[1]=(rand()%3)+1;
}

void display(int choice[], string table[][3]) {
	for (int i=0; i<2; i++) {
		if (i==0 && choice[i]<4) {
			cout<<endl<<"User choose ";
		}
		else if (i==1 && choice[i]<4) {
			cout<<"Computer choose ";
		}
		else {
			cout<<"Error "<<endl;
			return;
		}
		switch (choice[i]) {
			case 1:
				cout<<"Rock"<<endl;
				break;
				
			case 2:
				cout<<"Paper"<<endl;
				break;
				
			case 3:
				cout<<"Scissors"<<endl;
				break;
				
			default:
				cout<<"Something is wrong here"<<endl;
				return;
		}
	}
	cout<<table[choice[0]-1][choice[1]-1]<<endl<<endl;
}
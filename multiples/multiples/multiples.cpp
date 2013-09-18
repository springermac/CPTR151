//
//  multiples.cpp
//  multiples
//
//  Created by Jonathan Springer on 9/17/13.
//  Copyright (c) 2013 Jonathan Springer. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    char loop;
    
    do {
        int number;
        int i;
        
        cout<<"Please enter a number: ";
        cin>>number;
        
        for (i=0; i<=number; i=i+2) {
            cout<<i<<" ";
        }
        
        cout<<endl;
        
        while (i>0) {
            cout<<i-2<<" ";
            i=i-2;
        }
        
        cout<<endl<<"Do you want to run again? Y/N ";
        cin>>loop;
        
    } while (loop=='y'||loop=='Y');

    return 0;
}


#include "iostream"
using namespace std;

int main()
{
    int age;//age of individual
    string fname;//first name of individual
    string lastName;//last name of individual
    
    //get the first name of individual
    cout<<"\n\nEnter your first name: ";
    cin>>fname;
    
    //get the age of individual
    cout<<"Enter your age ";
    cin>>age;
    
    //get the last name of the individual
    cout<<"Enter your last name: ";
    cin>>lastName;
    
    
    //display results
    cout<<"\\nHello " <<fname<<""<<lastName;
    cout<<"your age is "<<age<<" Really????";
    cout<<"\n\n\n";
    return 0;
    
}//end main function
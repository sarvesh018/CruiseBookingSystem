#include <bits/stdc++.h>
#include "Passenger.h"
using namespace std;

//set details of passenger
void Passenger::setPassengerDetails(){
    cout<<"\nEnter your name: ";
    cin>>nameOfPassenger;
    cout<<"Enter phone number: ";
    cin>>passengerNumber;

    // Passenger ID will be generated according to name and phone number of Passenger
    for(int i=0; i<3; i++){
        passengerId += toupper(nameOfPassenger[i]);
    }
    passengerId += passengerNumber.substr(0,3);
}


// getter function to get customer's individual details
string Passenger::getPassengerName(){
    return nameOfPassenger;
}
string Passenger::getPassengerID(){
    return passengerId;
}

// show passenger details
void Passenger::showPassengersDetails(){
    cout<<"Name: "<<nameOfPassenger<<endl;
    cout<<"ID: "<<passengerId<<endl;
    cout<<"Phone: "<<passengerNumber<<endl;
}

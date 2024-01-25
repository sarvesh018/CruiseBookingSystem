#include <bits/stdc++.h>
#ifndef PASSENGER
#define PASSENGER
using namespace std;

class Passenger{
    public: 
        string nameOfPassenger;
        string passengerNumber;
        string passengerId;
    public:
        void setPassengerDetails();
        // getter function to get customer's individual details
        string getPassengerName();
        string getPassengerID();

        // display passenger details
        void showPassengersDetails();
};

#endif
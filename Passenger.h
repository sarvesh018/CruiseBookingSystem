#include <bits/stdc++.h>
#include "Cruise.h"
#include "storeDetails.h"
#ifndef PASSENGER
#define PASSENGER
using namespace std;

class Passenger{
    public: 
        // passenger personal details
        string nameOfPassenger;
        string passengerNumber;
        string passengerId;
        
        // cruise details for passenger
        string pCruiseId;
        vector<string> pSeats;
        string pSource, pDestination;
        string pDeparture, pArrival;
        string status;
        string seatType;
        vector<int> waitingList;
        float price;
    public:
        Passenger();
        void setPassengerDetails();
        // getter function to get customer's individual details
        string getPassengerName();
        string getPassengerID();

        // display passenger details
        void showPassengersDetails();
        void showTravelDetails();

        //set passenger journey details
        void fillJourneyDetails(Cruise cruise);

        // book seats of economy
        void bookSeats(Passenger& passenger, Cruise cruise, char type);
        void setSeatsDetails(Passenger& passenger, vector<string> seats, Cruise cruise);

        // write data into passenger database
        void writePassengerData(Passenger passenger);

        // take seat numbers
        void takeSeatNumbers(int size);
};

#endif
#include <bits/stdc++.h>
#include "Passenger.h"
using namespace std;

// constructor
Passenger::Passenger(){
    status = "NIL";
}


//set details of passenger
void Passenger::setPassengerDetails(){
    cout << "\n\tEnter your full name: ";
    cin.ignore();  // Clear the newline character from the buffer
    getline(cin, nameOfPassenger);  // Use getline for full name with spaces
    cout << "\tEnter phone number: ";
    cin >> passengerNumber;

    // Passenger ID will be generated according to name and phone number of Passenger
    passengerId = "";
    for(int i=0; i<3 && i<nameOfPassenger.length(); i++){
        passengerId += toupper(nameOfPassenger[i]);
    }
    passengerId += passengerNumber.substr(0, 3);
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
    cout << "\tName: " << nameOfPassenger << endl;
    cout << "\tID: " << passengerId << endl;
    cout << "\tPhone: " << passengerNumber << endl;
}


void Passenger::showTravelDetails(){
    cout << "\n\t\t\033[32m         Route\t\t\t\tEconomy Price\t   Business Price\tDelux Price\t\tDistance\t  Departure\t\t   Arrival\033[0m" << std::endl;
    cout << "\t\033[33m1) Kochi\t--->\tLakshadweep\t\t  2500 Rs\t\t5630 Rs\t\t9500 Rs\t\t\t448 km\t\t01/02/24 | 13:00\t03/02/24 | 15:00\033[0m" << std::endl;
    cout << "\t\033[34m2) Pondicherry\t--->\tGoa\t\t\t  3520 Rs\t\t6799 Rs\t\t10500 Rs\t\t882 km\t\t03/02/24 | 02:00\t03/02/24 | 17:30\033[0m" << std::endl;
    cout << "\t\033[38;5;208m3) Mumbai\t--->\tLakshadweep\t\t  4350 Rs\t\t6999 Rs\t\t12089 Rs\t\t903 km\t\t05/02/24 | 15:45\t07/02/24 | 03:40\033[0m" << std::endl;

}

// set journey details of passenger
void Passenger::fillJourneyDetails(Cruise cruise){
    pCruiseId = cruise.cruiseID;
    pSource = cruise.source;
    pDestination = cruise.destination;
    pDeparture = cruise.departureTime;
    pArrival = cruise.arrivalTime;
}

// book seats
void Passenger::bookSeats(Passenger& passenger, Cruise cruise, char type){
    if(type == 'e' || type == 'E'){
        passenger.seatType = "Economy";
        cout<<"\n\tSeats: ";
        cruise.displayTypeDetails(cruise.availableE, cruise.bookedE);
        passenger.setSeatsDetails(passenger, cruise.freeE, cruise);
            
    }
    else if(type == 'b' || type == 'B'){
        cout<<"\n\tSeats: ";
        passenger.seatType = "Business";
        cruise.displayTypeDetails(cruise.availableB, cruise.bookedB);
        passenger.setSeatsDetails(passenger, cruise.freeB, cruise);
    }
    else if(type == 'd' || type == 'D'){
        cout<<"\n\tSeats: ";
        passenger.seatType = "Deluxe";
        cruise.displayTypeDetails(cruise.availableD, cruise.bookedD);
        passenger.setSeatsDetails(passenger, cruise.freeD, cruise);          
    }
    else{
        cout<<"\tEnter Valid Character"<<endl;
        return;
    } 
}

// take seat numbers
void Passenger::takeSeatNumbers(int size){
    cout<<"\n\t-----Enter seat numbers-----"<<endl;
        for(int i=0; i<size; i++){
            string s;
            cout<<"\tEnter seat number "<<(i+1)<<" : ";
            cin>>s;
            pSeats.push_back(s);
        }
}


// set passengers seat
void Passenger::setSeatsDetails(Passenger& passenger, vector<string> seats, Cruise cruise){
    storeDetails database;
    database.name = passenger.nameOfPassenger;
    database.phnNumber = passenger.passengerNumber;
    database.id = passenger.passengerId;
    database.cruiseId = passenger.pCruiseId;
    
    database.source = passenger.pSource;
    database.destination = passenger.pDestination;
    database.departure = passenger.pDeparture;
    database.arrival = passenger.pArrival;
    database.seatType = passenger.seatType;
    cout<<"\n\tEnter number of seats required: ";
    int num;
    cin>>num;
    if(num <= seats.size()){
        // code for booking
        passenger.takeSeatNumbers(num);

        // update passenger status
        passenger.status = "Booked :)";

        //updating seat numbers in database
        database.seats = passenger.pSeats;
        database.status = passenger.status;
        
        cout<<"\n\t\033[32mBooking Successfull :)\t\033[0m"<<endl;

        // write passenger booking details in file
        database.seatsRequired = num;
        database.takeData();

        // update cruise details
        string id = passenger.pCruiseId;
        if(passenger.seatType == "Economy"){
            cruise.updateSeatStatus('E', passenger.pSeats, cruise.freeE, cruise.bookedE, id);
        }
        else if(passenger.seatType == "Business"){
            cruise.updateSeatStatus('B', passenger.pSeats, cruise.freeB, cruise.bookedB, id);
        }
        else{
            cruise.updateSeatStatus('D', passenger.pSeats, cruise.freeD, cruise.bookedD, id);
        }

        // updating passenger status 
        
    }
    else{
        cout<<"\n\tSeats not available, do you want to continue with waiting list (y/n): ";
        char ch;
        cin>>ch;
        if(ch=='Y' || ch=='y'){
            // code for waiting list
            cout<<"\n\t\033[32mSeats Confirmed will be: "<<(seats.size())<<"\033[0m";
            cout<<"\t|\t\033[31mSeats in Waiting List: "<<(num - seats.size())<<"\033[0m"<<endl;
            
            if(seats.size() > 0){
                // take available seats 
                passenger.takeSeatNumbers(seats.size());
                database.seats = passenger.pSeats;

                // update confirmed seat deatails in cruise file
                string id = passenger.pCruiseId;
                if(passenger.seatType == "Economy"){
                    cruise.updateSeatStatus('E', passenger.pSeats, cruise.freeE, cruise.bookedE, id);
                }
                else if(passenger.seatType == "Business"){
                    cruise.updateSeatStatus('B', passenger.pSeats, cruise.freeB, cruise.bookedB, id);
                }
                else{
                    cruise.updateSeatStatus('D', passenger.pSeats, cruise.freeD, cruise.bookedD, id);
                }
            }

            storeDetails sd;
            sd.seatsRequired = num;
            database.seatsRequired = num;
            // updating passenger object in waiting list queue
            int currentWaitingList = sd.findWaitingNumber(passenger.pCruiseId, passenger.seatType)+1; // fetch from file

            // int temp = (num - seats.size()) + currentWaitingList;
            for(int i=0; i<num-seats.size(); i++){
                passenger.waitingList.push_back(currentWaitingList);
                currentWaitingList++;
            }
            passenger.status = "Waiting List";

            // update waiting list status in database
            database.status = passenger.status;
            database.waitingNo = passenger.waitingList;
            
            database.takeData();
        }
        else{
            return;
        }
    }
}

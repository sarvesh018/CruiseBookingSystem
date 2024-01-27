#include <bits/stdc++.h>
#include "Passenger.h"
#include "Admin.h"
using namespace std;

int main() {

     Admin admin;
     storeDetails passengerDatabase;
     admin.welcome();

     while(true){
          Passenger passenger;
          cout<<"\n\t---Enter B for bookings "<<"| Enter C for cancelling bookings "<<"| Enter S for checking status "<<"| Enter F for checking cruise status | Exit (E)---"<<endl;
     
          char ch;
          cout<<"\n\tEnter character to proceed: ";
          cin>>ch;

          // query handling
          if(ch == 'e' || ch == 'E') break;
          else if(ch=='b' || ch=='B'){
               passenger.showTravelDetails();
               cout<<"\n\tChoose Journey: ";
               int ind;
               cin>>ind;

               string filename = "cruise"+to_string(ind)+".txt";
               
               // getting cruise details which user has selected
               Cruise cruise(filename);
               passenger.pCruiseId = cruise.cruiseID;
               // displaying cruise details for passenger
               cruise.displayCruiseDetails();
               string temp;
               cout<<"\n\tContinue Booking (y/n): ";
               cin>>temp;

               // show details of types chosen by passenger
               if(temp=="y"){
                    passenger.setPassengerDetails();

                    cout<<"\n\t------Type: Economy(e) | Business(b) | Delux(d)------"<<endl;
                    cout<<"\tChoose type: ";
                    
                    char type;
                    cin>>type;
                    // fill passenger journey details
                    passenger.fillJourneyDetails(cruise);

                    // take number of seats by passenger and checking if booking is possible or not
                    passenger.bookSeats(passenger, cruise, type);
                    
                    
               }
               else{
                    continue;
               }

          }
          else if(ch=='s' || ch=='S'){
               string name, id;
               cout<<"\n\tEnter Name: ";
               cin.ignore();
               getline(cin, name);

               cout<<"\tEnter Booking ID: ";
               cin>>id;
               passengerDatabase.displayFileDetails(id, name);
          }
          cout<<"\n\n";
     }
     return 0;
}
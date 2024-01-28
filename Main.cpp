#include <bits/stdc++.h>
#include <conio.h>
#include "Passenger.h"
#include "Admin.h"
#include "handleWaitingList.h"
using namespace std;

int main() {

     Admin admin;
     storeDetails passengerDatabase;
     admin.welcome();

     while(true){
          Passenger passenger;
          cout<<"\n\t\033[1m\033[33m---Enter B for bookings "<<"| Enter C for cancelling bookings "<<"| Enter S for checking status "<<"| Enter F for checking cruise status | Exit (E)---\033[0m"<<endl;
     
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

                    cout<<"\n\t\033[1m\033[33m------Type: Economy(e) | Business(b) | Delux(d)------\033[0m"<<endl;
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

               char check;
               cout<<"\n\t\033[35mHey \033[1m\033[3m"<<passenger.nameOfPassenger<<"\033[0m\033[35m! Do you want to check booking details (y/n): \033[0m";
               cin>>check;
               if(check=='Y' || check=='y'){
                    passengerDatabase.displayFileDetails(passenger.passengerId, passenger.nameOfPassenger);
               }
               else{
                    continue;
               }
          }

          // code for showing booking status of passenger
          else if(ch=='s' || ch=='S'){
               string name, id;
               cout<<"\n\tEnter Name: ";
               cin.ignore();
               getline(cin, name);

               cout<<"\tEnter Booking ID: ";
               cin>>id;
               passengerDatabase.displayFileDetails(id,name);
               // passengerDatabase.displayAllDetails();
          }

          // code for cancelling booking of passenger
          else if(ch=='c' || ch=='C'){
               string pid, cid;
               cout<<"\n\tEnter your booking ID: ";
               cin>>pid;
               cout<<"\tEnter cruise ID: ";
               cin>>cid;   

               string cruiseFileName;
               string passFileName = "passengerDetails.txt";
               if(cid == "TO125"){
                    cruiseFileName = "cruise1.txt";
               }
               else if(cid == "IND026"){
                    cruiseFileName = "cruise2.txt";
               }
               else if(cid == "BHT220"){
                    cruiseFileName = "cruise3.txt";
               }
               HandleData data;
               int lineNum = data.findLineNumber(pid, passFileName);
               string seats = data.readLineFromFile(passFileName, lineNum+5);
               vector<string> passSeats = data.getDataAfterColon(seats);
               
               // delete seats booked by passenger
               Cruise cruise(cruiseFileName);
               for(auto x: passSeats){
                    cruise.deleteBooking(x);
               }

               // delete passenger data from database
               storeDetails sd;
               sd.deleteData(pid);
               cout<<"\n\t\033[32mBooking Cancelled !!\033[0m"<<endl;
          }
          else if(ch=='f' || ch=='F'){
               Admin admin;
               string user, pass;
               cout<<"\n\tEnter Username: ";
               cin>>user;
               
               string password;
               char ch;
               cout << "\tEnter password: ";

               // Loop until Enter is pressed
               while ((ch = _getch()) != '\r' && ch != '\n') {
                    password.push_back(ch);
                    std::cout << '*';  // Display '*' instead of the actual character
               }

               if(admin.authenticate(user, password)){
                    passengerDatabase.displayAllDetails();
               }
               else{
                    cout<<"\n\t\033[31mAuthentication Failed!\033[0m"<<endl;
               }
          }
          cout<<"\n\n";
     }
     return 0;
}
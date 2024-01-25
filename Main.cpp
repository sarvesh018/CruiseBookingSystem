#include <bits/stdc++.h>
#include "Passenger.h"
#include "Data.h"
using namespace std;

int main() {

    const string filename = "Passengers.txt";
    
    while(true){
        cout<<"\n--------Choose 1 for bookings | Choose 2 for cancle | Choose 0 to exit---------"<<endl;
        cout<<"Press Number: ";
        int x;
        cin>>x;
        if(x == 0) break;

        Data data(filename);

       if(x == 1){
            Passenger p1;
            p1.setPassengerDetails();
            p1.showPassengersDetails();

            data.updateNames(p1.getPassengerName());
            data.updateID(p1.getPassengerID());

            // updating details
            string newIDs = data.getIDs();
            data.updateNameDetailsInFile(filename, 5, newIDs);
            string newNames = data.getNames();
            data.updateNameDetailsInFile(filename, 2, newNames);
       }
       else if(x == 2){
            cout<<"-----------Booking Cancellation------------"<<endl;
            string str;
            cout<<"Enter Name: ";
            cin>>str;
            data.deletePassenger(str, filename);

            cout<<data.getNames()<<endl;
            cout<<data.getIDs()<<endl;
       }
        
    }
       

    return 0;
}

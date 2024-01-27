#include <bits/stdc++.h>
#include "storeDetails.h"
using namespace std;

storeDetails::storeDetails() : name(" "), phnNumber(" "), id(" "), cruiseId(" "),source(" "), destination(" "),
            departure(" "), arrival(" "), status(" "), waitingNo(0), totalFare(0.0),passengerFile("passengerDetails.txt") {}

// ___________________________Store Data in file__________________________
void storeDetails::takeData() {
    if (id == " " && cruiseId == " ") {
        cout << "Not Initialized" << endl;
        return;
    }

    ofstream fout(passengerFile, ios::app);
    if (!fout.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    fout << "Passenger Id: \t\t\t";
    fout << id << endl;
    fout << "Cruise Id: \t\t\t\t";
    fout << cruiseId << endl;
    fout << "Name: \t\t\t\t\t";
    fout << name << endl;
    fout << "Phone number: \t\t\t";
    fout << phnNumber << endl;
    fout << "Seats Booked: \t\t\t";
        for (int i = 0; i < seats.size(); i++) {
            fout<<seats[i]<<" ";
        }
    fout<<endl;
    fout<<"Seat Type: \t\t\t\t"<<seatType<<endl;
    fout << "Journey: \t\t\t\t";
    fout << source << " ---> " << destination << endl;
    fout << "Duration: \t\t\t\t";
    fout << departure<<" ---> " << arrival << endl;
    if(waitingNo.size() != 0){
        fout << "Status: \t\t\t\t";
        fout << status << " | " ;
        fout << "Waiting Number: \t\t\t\t";
        for(int i=0; i<waitingNo.size(); i++){
            fout << waitingNo[i]<<" ";
        }
    }else{
        fout << "Status: \t\t\t\t";
        fout << status << endl;
    }
    fout << "-------------------------------------------------------------------"<<endl;
    cout<<endl;
}

void storeDetails::displayFileDetails(const string& I, const string& n){
    ifstream fin(passengerFile);
    if(!fin)
        cout << "\nFile not found" << endl;
    else{
        string line;
        while(getline(fin,line)){
            if(line.find("Passenger Id: \t\t\t\t" + I) != string::npos){
                cout<<"___________________________________________________" << endl;      
                cout<<endl;
                cout <<"            "<< line << endl;                                                             //12
                while (getline(fin, line) && line.find("-------------------------------------------") == string::npos) {
                    cout << "            " << line << endl;
                }
                cout<<"___________________________________________________" << endl;
                break;
            }
        }
    }
    fin.close();
}


void storeDetails::deleteData(const string& d) {
    ifstream fin(passengerFile);
    if (!fin) {
        cout << "\nFile not found" << endl;
        return;
    }

    ofstream fout("tempfile.txt", ios::out);
    string line;
    bool skipNextLines = false;
    int c=9;
    int linesSkipped=0;


    while (getline(fin, line)) {
        if (skipNextLines) {
            linesSkipped++;
            if (linesSkipped >= c) {
                skipNextLines = false;
                linesSkipped = 0;
            }
        }
        else if (line.find("Passenger Id: " + d) == string::npos){
            fout << line << endl;
        }
        else
            skipNextLines = true;
    }

    fin.close();
    fout.close();

    remove("storeDetails.txt");
    rename("tempfile.txt", "passengerFile.txt");
}

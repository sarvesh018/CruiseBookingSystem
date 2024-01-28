// storeDetails.h
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class storeDetails {
public:
    string name;
    string phnNumber;
    string id;
    string cruiseId, seatType;
    vector<string> seats;
    int seatsRequired;
    string source, destination;
    string departure, arrival;
    string status;
    vector<int> waitingNo;
    float totalFare;

    storeDetails();

    void takeData();
    void deleteData(const string& d);
    void displayFileDetails(const string& I, const string& n);
    void displayAllDetails();
    float calculateFare(string cruiseId, string seatType, int seats);
    int findWaitingNumber(const string& cId, const string& type);
    void updatingAfterWaitingNo(const string& cId, const string& type, vector<string> v, int w);
};

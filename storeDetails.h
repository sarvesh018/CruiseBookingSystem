#include <bits/stdc++.h>
using namespace std;

class storeDetails {
    public:
        // passenger personal details
            string name;
            string phnNumber;
            string id;
            
            // cruise details for passenger
            string cruiseId;
            vector<string> seats;
            string source, destination;
            string departure, arrival;
            string status;
            vector<int> waitingNo;
            float totalFare;
            string passengerFile;

        storeDetails();
        void setInput();
        // ___________________________Store Data in file__________________________
    void takeData();

    void displayAllDetails();

    void displayFileDetails(const string& I, const string& n);

    void deleteData(const string& d);
};

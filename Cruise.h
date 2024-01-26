#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
 
using namespace std;

class Cruise
{
public:
    string cruiseID;
    string cruiseName;
    string source, destination;
    string departure, arrival;
    vector<string> availableB;
    vector<string> availableE;
    vector<string> availableD;
    vector<string> bookedE;
    vector<string> bookedD;
    vector<string> bookedB;
    vector<string> freeB;
    vector<string> freeE;
    vector<string> freeD;

    Cruise(const string& filename);

    void updateBooking(string a, string filename);

    // display Cruise Details
    void displayTypeDetails(vector<string> available, vector<string> booked);
    void displayCruiseDetails();
};

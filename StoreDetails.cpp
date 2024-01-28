// storeDetails.cpp
#include "storeDetails.h"
#include <fstream>

string passengerFile = "passengerDetails.txt";

storeDetails::storeDetails() : name(" "), phnNumber(" "), id(" "), cruiseId(" "), seatType(" "), source(" "), destination(" "),
                               departure(" "), arrival(" "), status(" "), waitingNo(0), totalFare(0.0), seatsRequired(0) {}

//----------------------Store Details in File------------------------
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
    fout << "Passenger Id: \t\t";
    fout << id << endl;
    fout << "Cruise Id: \t\t\t";
    fout << cruiseId << endl;
    fout << "Name: \t\t\t";
    fout << name << endl;
    fout << "Phone number: \t\t";
    fout << phnNumber << endl;
    fout << "Seat Type: \t\t\t";
    fout << seatType << endl;
    fout << "Seats Booked: \t\t";
        for (int i = 0; i < seats.size(); i++) {
            fout<<seats[i]<<" ";
        }
    fout << endl;
    fout << "Journey: \t\t\t";
    fout << source << " ---> " << destination << endl;
    fout << "Duration: \t\t\t";
    fout << departure<<" ---> " << arrival << endl;
    if(waitingNo.size() != 0){
        fout << "Status: \t\t\t";
        fout << status << " | " ;
        fout << "Waiting Number: ";
        for(int i=0; i<waitingNo.size(); i++){
            fout << waitingNo[i]<<" ";
        }
        fout<<endl;
    }else{
        fout << "Status: \t\t\t";
        fout << status << endl;
    }
    totalFare = calculateFare(cruiseId, seatType, seatsRequired);
    fout << "Total Fare(+GST): \t\t";
    fout << totalFare<<" Rs" << endl;
    fout << "-------------------------------------------"<<endl;
    cout<<endl;
    fout.close();
}

//------------------calculate fare----------------------
float storeDetails::calculateFare(string cruiseId, string seatType, int seats){
    float totalFare = 0;
    if(cruiseId == "TO125"){
        if(seatType == "Economy"){
            totalFare = seats*2500;
        }
        else if(seatType == "Business"){
            totalFare = seats*5630;
        }
        else if(seatType == "Deluxe"){
            totalFare = seats*9500;
        }
    }
    else if(cruiseId == "IND026"){
        if(seatType == "Economy"){
            totalFare = seats*3520;
        }
        else if(seatType == "Business"){
            totalFare = seats*6799;
        }
        else if(seatType == "Deluxe"){
            totalFare = seats*10500;
        }
    }
    else if(cruiseId == "BHT220"){
        if(seatType == "Economy"){
            totalFare = seats*4350;
        }
        else if(seatType == "Business"){
            totalFare = seats*6999;
        }
        else if(seatType == "Deluxe"){
            totalFare = seats*12089;
        
        }
    }
    totalFare += totalFare*0.18;
    return totalFare;
}

//----------------------Delete Data From File--------------------
void storeDetails::deleteData(const string& d) {
    ifstream fin(passengerFile);
    if (!fin) {
        cout << "\nFile not found" << endl;
        return;
    }

    ofstream fout("tempfile.txt", ios::out);
    string line;
    bool skipNextLines = false;
    int c=10;
    int linesSkipped=0;


    while (getline(fin, line)) {
        if (skipNextLines) {
            linesSkipped++;
            if (linesSkipped >= c) {
                skipNextLines = false;
                linesSkipped = 0;
            }
        }
        else if (line.find("Passenger Id: \t\t" + d) == string::npos){
            fout << line << endl;
        }
        else
            skipNextLines = true;
    }

    fin.close();
    fout.close();

    remove("passengerDetails.txt");
    rename("tempfile.txt", "passengerDetails.txt");
}

//-----------------------Display Passenger Details----------------------
void storeDetails::displayFileDetails(const string& I, const string& n) {
    ifstream fin(passengerFile);
    if(!fin)
        cout << "\nFile not found" << endl;
    else{
        string line;
        bool flag = true;
        while(getline(fin,line)){
            if(line.find("Passenger Id: \t\t" + I) != string::npos){
                flag = false;
                cout << "\n\t\t    \033[7m\033[32;1m" << n <<"'s Booking Details" << "\033[0m" << endl;
                cout <<"\t___________________________________________________" << endl;          //50
                cout<<endl;
                cout <<"\033[1m            "<< line <<endl;                                                             //12
                while (getline(fin, line) && line.find("-------------------------------------------") == string::npos) {
                    cout <<"            " << line << endl;
                }
                cout<<"\033[0m";
                cout<<"\t___________________________________________________" << endl;
                break;
            }
        }
        if(flag){
            cout<<"\n\t\033[31mEnter Valid Passenger ID!!"<<endl;
        }
    }
    fin.close();
}

//------------------Display All Details-----------------------
void storeDetails::displayAllDetails() {
    ifstream fin(passengerFile);
    if(!fin)
        cout << "\nFile not found" << endl;
    else{
        string line;
        cout << "\n\n\t\t\033[37;1m" << "|| Passenger Details ||" << endl;
        cout <<"_________________________________________________________________" << "\033[0m" << endl;
        cout<<endl;
        while(getline(fin,line)){
            cout <<"          "<< line << endl;             //10
        }
        cout << "\033[37;1m" <<"_________________________________________________________________" << "\033[0m" << endl;
        cout<<endl;
    }
    fin.close();
}

int storeDetails::findWaitingNumber(const string& cId, const string& type) {
     ifstream fin(passengerFile);
    if (!fin) {
        cout << "\nFile not found" << endl;
        return 0;
    }
    string line;
    int wait=0;
    string l1;
    while(getline(fin, line)){
        start:
        int c=0;
        bool skipLine = false;
        if(line.find("Cruise Id: \t\t\t" + cId) != string::npos){
            skipLine = true;
        } 
        if(skipLine){
            
            while(getline(fin, line)){
                if(c==3){
                    break;
                }         
                else if(line.find(type) != string::npos){
                    c=0;
                    int c2 = 0;
                    while(getline(fin, line)){
                        if(c2==4){
                            c2=0;
                            break;
                        }
                        else if(line.find("Waiting") != string::npos){
                            l1=line;
                            int lastIndex = l1.size() - 1;
                            while (lastIndex >= 0 && isdigit(l1[lastIndex])) {
                                lastIndex--;
                            }
                            while (lastIndex >= 0 && isspace(l1[lastIndex])) {
                                lastIndex--;
                            }
                            // Find the beginning of the last integer
                            int firstIndex = lastIndex;
                            while (firstIndex >= 0 && isdigit(l1[firstIndex])) {
                                firstIndex--;
                            }
                            // Extract the substring containing the last integer
                            string lastIntegerSubstring = l1.substr(firstIndex + 1, lastIndex - firstIndex);

                            // Convert the substring to an integer
                            int lastInteger = stoi(lastIntegerSubstring);
                            wait = max(wait, lastInteger);
                            c2=0;
                            goto start;
                        }else{
                            c2 += 1;
                            skipLine = false;
                        }
                    }
                
                }else{
                    c++;
                    skipLine = false;
                }
            }
        }
    }
    fin.close();
    return wait;
}

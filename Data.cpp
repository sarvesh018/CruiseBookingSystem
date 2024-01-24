#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Passenger{
    public: 
        string nameOfPassenger;
        string passengerNumber;
        string passengerId;
    public:
        void setPassengerDetails(){
            cout<<"Enter your name: ";
            // getline(cin, nameOfPassenger);
            cin>>nameOfPassenger;
            // cout<<endl;
            cout<<"Enter phone number: ";
            cin>>passengerNumber;

            // Passenger ID will be generated according to name and phone number of Passenger
            for(int i=0; i<3; i++){
                passengerId += toupper(nameOfPassenger[i]);
            }
            passengerId += passengerNumber.substr(0,3);
        }

        // getter function to get customer's individual details
        string getPassengerName(){
            return nameOfPassenger;
        }
        string getPassengerNumber(){
            return passengerNumber;
        }

        void showPassengersDetails(){
            cout<<"Name: "<<nameOfPassenger<<endl;
            cout<<"ID: "<<passengerId<<endl;
            cout<<"Phone: "<<passengerNumber<<endl;
        }
};

class Data{
    public:
        vector<string> names;
        vector<string> ids;
        string line;
        int nameNum = 2, idNum = 5;
    public:
        // constructor to fill names and id vectors with data
        Data(const string& filename){
            ifstream file(filename);
            int currentLine = 0;
            if (file.is_open()) {
                while (getline(file, line)) {
                    currentLine++;
                    if (currentLine == nameNum) {
                        istringstream iss(line);
                        string s;
                        while(getline(iss, s, '|')){
                            names.push_back(s);
                        }
                    }
                    else if(currentLine == idNum){
                        istringstream iss(line);
                        string s;
                        while(getline(iss, s, '|')){
                            ids.push_back((s));
                        }
                    }
                }
                file.close();
            } 
            else {
                cerr << "Error opening file!" << std::endl;
            }
        }

        // updating the name and ids
        void updateNames(string newName){
            names.push_back(newName);
        }
        void updateNumbers(string newNum){
            ids.push_back(newNum);
        }
        string getNames(){
            // creating a string of names separated with comma
            string result = "";
            for(auto x: names){
                result += x;
                result += '|';
            }
            return result;
        }
        

        // add updated data into file
        void updateNameDetailsInFile(const string& filename, int lineNumber, const string& newData){
            ifstream inputFile(filename);
            vector<string> lines;
            string line;

            // creating vector<string> of names already present in the file
            while (getline(inputFile, line)) {
                lines.push_back(line);
            }

            inputFile.close();

            //erase the existing line
            lines[lineNumber-1]="";
            lines[lineNumber-1] += newData;

            // save the file with updated data
            ofstream outputFile(filename);
            for(const string& modifiedLine: lines){
                outputFile<<modifiedLine<<"\n";
            }

            outputFile.close();
        }
        
};

int main() {

    const string filename = "temp.txt";
    
    while(true){
        cout<<"\n--------Choose 1 for bookings | Choose 0 to exit---------"<<endl;
        cout<<"Press Number: ";
        int x;
        cin>>x;
        if(x == 0) break;

        Data data(filename);
        cout<<data.getNames()<<endl;

        Passenger p1;
        p1.setPassengerDetails();
        p1.showPassengersDetails();

        data.updateNames(p1.getPassengerName());
        string newNames = data.getNames();
        data.updateNameDetailsInFile(filename, 2, newNames);
    }
    
    // Data data2(filename);
    // cout<<data2.getNames()<<endl;


    return 0;
}

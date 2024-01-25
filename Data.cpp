#include <bits/stdc++.h>
#include "Data.h"
using namespace std;

// constructor to fill names and id vectors with data
Data::Data(const string& filename){
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
                    ids.push_back(s);
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
void Data::updateNames(string newName){
    names.push_back(newName);
}
void Data::updateID(string newNum){
    ids.push_back(newNum);
}
string Data::getNames(){
    // creating a string of names separated with comma
    string result = "";
    for(auto x: names){
        result += x;
        result += '|';
    }
    return result;
}
string Data::getIDs(){
    // creating a string of names separated with comma
    string result = "";
    for(auto x: ids){
        result += x;
        result += '|';
    }
    return result;
}

// delete passenger
void Data::deletePassenger(string name, const string& filename){
    int ind = -1;
    for(int i=0; i<names.size(); i++){
        if(names[i] == name){
            ind = i;
            names.erase(names.begin() + i);
            ids.erase(ids.begin() + i);
            updateNameDetailsInFile(filename, 2, getNames());
            updateNameDetailsInFile(filename, 5, getIDs());
        }

    }
    if(ind == -1){
        cout<<"No Passenger Found!!"<<endl;
    }
    else{
        cout<<"Booking Cancelled Sucessfully"<<endl;
    }

}

// add updated data into file
void Data::updateNameDetailsInFile(const string& filename, int lineNumber, const string& newData){
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
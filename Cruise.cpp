#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Cruise.h"

using namespace std;

Cruise::Cruise(string filename)
{
    this->filename = filename;
    fstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cout << "File not opened" << endl
                << endl;
    }

    int cruiseIdLine = 2;
    int cruiseNameLine = 5;
    int currentLine = 0;
    string line;
    while (getline(inputFile, line))
    {
        currentLine++;
        if (currentLine == cruiseIdLine)
        {
            // cout << "The cruise id is: " << line << endl
            //         << endl;
            cruiseID = line;
        }
        else if (currentLine == cruiseNameLine)
        {
            // cout << "The cruise name is: " << line << endl
            //         << endl;
            cruiseName = line;
        }
        else if (currentLine == 8)
        {
            stringstream ss(line);
            string numberStr;
            // cout << "Business class seats are: ";
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                // cout << number << " ";
                availableB.push_back(number);
            }
            // cout << endl
            //         << endl;
        }
        else if (currentLine == 11)
        {
            stringstream ss(line);
            string numberStr;
            // cout << "Economy class seats are: ";
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                // cout << number << " ";
                availableE.push_back(number);
            }
            // cout << endl
            //         << endl;
        }
        else if (currentLine == 14)
        {
            stringstream ss(line);
            string numberStr;
            // cout << "Deluxe class seats are: ";
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                // cout << number << " ";
                availableD.push_back(number);
            }
            // cout << endl
            //         << endl;
        }
        else if (currentLine == 17)
        {
            stringstream ss(line);
            string numberStr;
            int i = 0;
            // cout << "Business class booked seats are: ";
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                bookedB.push_back(number);
                // cout << bookedB[i++] << " ";
            }
            // cout << endl
            //         << endl;
        }
        else if (currentLine == 20)
        {
            stringstream ss(line);
            string numberStr;
            int i = 0;
            // cout << "Economy class booked seats are: ";
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                bookedE.push_back(number);
                // cout << bookedE[i++] << " ";
            }
            // cout << endl
            //         << endl;
        }
        else if (currentLine == 23)
        {
            stringstream ss(line);
            string numberStr;
            int i = 0;
            // cout << "Deluxe class booked seats are: ";
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                bookedD.push_back(number);
                // cout << bookedD[i++] << " ";
            }
            // cout << endl
            //         << endl;
            // cout << "Business seats available: ";

            for (const auto &element : availableB)
            {
                if (find(bookedB.begin(), bookedB.end(), element) == bookedB.end())
                {
                    freeB.push_back(element);
                    // cout << element << " ";
                }
            }

            // cout << endl
            //         << endl;
            // cout << "Economy seats available: ";

            for (const auto &element : availableE)
            {
                if (find(bookedE.begin(), bookedE.end(), element) == bookedE.end())
                {
                    freeE.push_back(element);
                    // cout << element << " ";
                }
            }

            // cout << endl
            //         << endl;
            // cout << "Deluxe seats available: ";

            for (const auto &element : availableD)
            {
                if (find(bookedD.begin(), bookedD.end(), element) == bookedD.end())
                {
                    freeD.push_back(element);
                    // cout << element << " ";
                }
            }
        }
        else if (currentLine == 26)
        {
            // cout << endl
            //         << endl;
            source = line;
            // cout << "Source is: " << line << endl
            //         << endl;
        }
        else if (currentLine == 29)
        {
            destination = line;
            // cout << "Destination is: " << line << endl
            //         << endl;
        }
        else if (currentLine == 32)
        {
            departureTime = line;
            // cout << "Departure Time is: " << line << endl
            //         << endl;
        }
        else if (currentLine == 35)
        {
            arrivalTime = line;
            // cout << "Arrival Time is: " << line << endl
            //         << endl;
        }
        else if (currentLine == 38)
        {
            priceB = stoi(line);
            // cout << "Price of Business is: " << priceB << endl
            //         << endl;
        }
        else if (currentLine == 41)
        {
            priceE = stoi(line);
            // cout << "Price of Business is: " << priceE << endl
            //         << endl;
        }
        else if (currentLine == 44)
        {
            priceD = stoi(line);
            // cout << "Price of Business is: " << priceD << endl
            //         << endl;
        }
    }
    inputFile.close();
}

void Cruise::deleteBooking(const string &targetString)
{
    // Determine in which vector the element is present
    const vector<string> *targetVector = nullptr;
    int lineNumber = -1;

    if (find(bookedB.begin(), bookedB.end(), targetString) != bookedB.end())
    {
        auto it = std::find(bookedB.begin(), bookedB.end(), targetString);
        bookedB.erase(it);
        freeB.clear();
        for (const auto &element : availableB)
        {
            if (find(bookedB.begin(), bookedD.end(), element) == bookedB.end())
            {
                freeB.push_back(element);
                // cout << element << " ";
            }
        }
        targetVector = &bookedB;
        lineNumber = 16;
    }
    else if (find(bookedE.begin(), bookedE.end(), targetString) != bookedE.end())
    {
        auto it = std::find(bookedE.begin(), bookedE.end(), targetString);
        bookedE.erase(it);
        freeE.clear();
        for (const auto &element : availableE)
        {
            if (find(bookedE.begin(), bookedE.end(), element) == bookedE.end())
            {
                freeE.push_back(element);
                // cout << element << " ";
            }
        }
        targetVector = &bookedE;
        lineNumber = 19;
    }
    else if (find(bookedD.begin(), bookedD.end(), targetString) != bookedD.end())
    {
        // cout << "This hits" << endl;
        auto it = std::find(bookedD.begin(), bookedD.end(), targetString);
        bookedD.erase(it);
        freeD.clear();
        for (const auto &element : availableD)
        {
            if (find(bookedD.begin(), bookedD.end(), element) == bookedD.end())
            {
                freeD.push_back(element);
                // cout << element << " ";
            }
        }
        // cout << "Erased";
        targetVector = &bookedD;
        lineNumber = 22;
    }
    else
    {
        cerr << "\t\033[31mError: Enter Correct Passenger ID" << endl;
        return;
    }

    // Open the file for reading
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "\t\033[31mError: Could not process your request" << endl;
        return;
    }

    // Read lines into a vector
    vector<string> lines;
    string line;
    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }

    // Close the input file
    inputFile.close();

    // Check if the vectors are not empty
    if (targetVector->empty())
    {
        cerr << "\t\033[31mError: Try Again!!" << endl;
        return;
    }

    // Find the line number to update
    // size_t lineNumber = distance(lines.begin(), find(lines.begin(), lines.end(), lines.front()));
    // for (size_t i = 0; i < lines.size(); ++i) {
    //     if (lines[i] == targetVector->front()) {
    //         lineNumber = i;
    //         break;
    //     }
    // }

    // Update the line based on the target vector
    stringstream ss(lines[lineNumber]);
    string currentValue;
    vector<string> values;

    while (getline(ss, currentValue, '|'))
    {
        if (find(targetVector->begin(), targetVector->end(), currentValue) == targetVector->end())
        {
            values.push_back(currentValue);
            if (ss.peek() == '|')
            {
                ss.ignore();
            }
        }
        else
        {
            // Skip the value to be deleted
            if (ss.peek() == '|')
            {
                ss.ignore();
            }
        }
    }

    // Construct the updated line
    string result;

    // Iterate through the vector and concatenate the elements with "|"
    // for (const string &element : targetVector)
    // {
    //     result += element;
    //     if (&element != &targetVector->back())
    //     {
    //         result += "|";
    //     }
    // }
    for (int i = 0; i < targetVector->size(); i++)
    {
        result += targetVector->at(i);
        if (targetVector->at(i) != targetVector->back())
        {
            result += "|";
        }
    }
    // cout << result;

    // Update the line
    lines[lineNumber] = result;

    // Open the file for writing
    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        cerr << "\t\033[31mError: Could not process your request. Try Again!!" << endl;
        return;
    }

    // Write the modified content back to the file
    for (size_t i = 0; i < lines.size(); ++i)
    {
        outputFile << lines[i];
        if (i != lines.size() - 1)
        {
            outputFile << endl; // Add newline unless it's the last line
        }
    }

    // Close the output file
    outputFile.close();

    // cout << "File updated successfully." << endl;
}

void Cruise::displayTypeDetails(vector<string> available, vector<string> booked){
    for(auto x: available){
        bool isBooked = false;
        for(auto y: booked){
            if(x == y){
                isBooked = true;
            }
        }
        cout<<"\t"<<(isBooked ? "\033[31m" : "\033[32m") <<"|"<<x << "|\033[0m";
    }
    cout<<endl;
}

void Cruise::displayCruiseDetails(){
    cout<<"\n\t\t\t\t\033[1m   "<<cruiseName<<" "<<cruiseID<<"\033[0m"<<endl;
    cout << "\n\t\t\033[32m"; // Green color
    cout << "\tGreen: ";
    cout << "\033[0m"; // Reset color
    cout << "\tAvailable Seats | ";
    cout << "\033[31m"; // Red color
    cout << "Red: ";
    cout << "\033[0m"; // Reset color
    cout << "\tBooked Seats" << endl;
    cout<<"\n\tEconomy Class ";
    displayTypeDetails(availableE, bookedE);
    cout<<"\tBusiness Class ";
    displayTypeDetails(availableB, bookedB);
    cout<<"\tDeluxe Class ";
    displayTypeDetails(availableD, bookedD);
    cout<<endl;
}

void Cruise::updateSeatStatus(char ch, vector<string> seats, vector<string> free, vector<string> booked, string id){
    int bookedLineNum;
    if(ch == 'E'){
        bookedLineNum = 20; 
    }
    else if(ch == 'B'){
        bookedLineNum = 17;
    }
    else{
        bookedLineNum = 23;
    }
    
    // erase booked seat from free vector    
    for(int i=0; i<seats.size(); i++){
        string seat = seats[i];
        for(int j=0; j<free.size(); j++){
            if(free[j] == seat){
                free.erase(free.begin()+j);
                break;
            }
        }
        booked.push_back(seat);
    }
         
    string newData = "";
    for(auto x: booked){
        newData += x;
        newData += '|';
    }
    booked.clear();
    free.clear();

    // updating seats into the cruise database
    string filename;
    if(id == "TO125"){
        filename = "cruise1.txt";
    }
    else if(id == "IND026"){
        filename = "cruise2.txt";
    }
    else if(id == "BHT220"){
        filename = "cruise3.txt";
    }
    updateNameDetailsInFile(filename, bookedLineNum, newData);
}

void Cruise::updateNameDetailsInFile(const string& filename, int lineNumber, const string& newData){
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
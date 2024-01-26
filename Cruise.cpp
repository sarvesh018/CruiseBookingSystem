#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Cruise.h"

using namespace std;

Cruise::Cruise(const string& filename)
{
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
            cruiseID = line;
        }
        else if (currentLine == cruiseNameLine)
        {
            cruiseName = line;
        }
        else if (currentLine == 8)
        {
            stringstream ss(line);
            string numberStr;
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                availableB.push_back(number);
            }
        }
        else if (currentLine == 11)
        {
            stringstream ss(line);
            string numberStr;
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                availableE.push_back(number);
            }
        }
        else if (currentLine == 14)
        {
            stringstream ss(line);
            string numberStr;
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                availableD.push_back(number);
            }
        }
        else if (currentLine == 17)
        {
            stringstream ss(line);
            string numberStr;
            int i = 0;
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                bookedB.push_back(number);
            }
        }
        else if (currentLine == 20)
        {
            stringstream ss(line);
            string numberStr;
            int i = 0;
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                bookedE.push_back(number);
            }
        }
        else if (currentLine == 23)
        {
            stringstream ss(line);
            string numberStr;
            int i = 0;
            while (getline(ss, numberStr, '|'))
            {
                string number;
                istringstream(numberStr) >> number;
                bookedD.push_back(number);
            }
            for (const auto &element : availableB)
            {
                if (find(bookedB.begin(), bookedB.end(), element) == bookedB.end())
                {
                    freeB.push_back(element);
                }
            }
            for (const auto &element : availableE)
            {
                if (find(bookedE.begin(), bookedE.end(), element) == bookedE.end())
                {
                    freeE.push_back(element);
                }
            }
            for (const auto &element : availableD)
            {
                if (find(bookedD.begin(), bookedD.end(), element) == bookedD.end())
                {
                    freeD.push_back(element);
                }
            }
        }
        else if (currentLine == 26)
        {
            source = line;
        }
        else if (currentLine == 29)
        {
            destination = line;
        }
        else if (currentLine == 32)
        {
            departure = line;
        }
        else if (currentLine == 35)
        {
            arrival = line;
        }
    }
    inputFile.close();
}

void Cruise::updateBooking(string a, string filename)
{
    int lineNumberToUpdate;
    int availableLine;
    vector<string> valuesToAdd;

    if (a == "BU")
    {
        lineNumberToUpdate = 16;
        availableLine = 8;
        valuesToAdd = this->freeB;
    }
    else if (a == "EU")
    {
        lineNumberToUpdate = 19;
        availableLine = 11;
        valuesToAdd = this->freeE;
    }
    else if (a == "DU")
    {
        lineNumberToUpdate = 22;
        availableLine = 14;
        valuesToAdd = this->freeD;
    }

    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the file." << endl;
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

    // if (lineNumberToUpdate < 0 || lineNumberToUpdate >= lines.size())
    // {
    //     cerr << "Error: Invalid line number." << endl;
    //     return ;
    // }

    // Update the ith line
    if (!valuesToAdd.empty())
    {
        // Extract the existing values from the line
        stringstream ss(lines[lineNumberToUpdate]);
        string value;
        vector<string> existingValues;

        while (ss >> value)
        {
            existingValues.push_back(value);
            if (ss.peek() == '|')
            {
                ss.ignore();
            }
        }

        // Append a value from the vector to the existing values
        existingValues.push_back(valuesToAdd.back());
        if (a == "BU")
        {
            this->bookedB.push_back(valuesToAdd.back());
        }
        else if (a == "EU")
        {
            this->bookedE.push_back(valuesToAdd.back());
        }
        else if (a == "DU")
        {
            this->bookedD.push_back(valuesToAdd.back());
        }

        valuesToAdd.pop_back();

        // Construct the updated line
        stringstream updatedLine;
        for (size_t i = 0; i < existingValues.size(); ++i)
        {
            updatedLine << existingValues[i];
            if (i != existingValues.size() - 1)
            {
                updatedLine << '|';
            }
        }

        // cout << updatedLine.str();

        // Update the line
        lines[lineNumberToUpdate] = updatedLine.str();
    }

    // Open the file for writing
    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        cerr << "Error: Could not open the file for writing." << endl;
        return;
    }

    // Write the modified content back to the file
    for (const string &updatedLine : lines)
    {
        outputFile << updatedLine << endl;
    }

    // Close the output file
    outputFile.close();
    if (a == "BU")
    {
        freeB = valuesToAdd;
    }
    else if (a == "EU")
    {
        freeE = valuesToAdd;
    }
    else if (a == "DU")
    {
        freeD = valuesToAdd;
    }

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
    cout<<"\tDelux Class ";
    displayTypeDetails(availableD, bookedD);
    cout<<endl;
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#ifndef CRUISE1
#define CRUISE1

using namespace std;
class Cruise
{
public:
    string cruiseID;
    string cruiseName;
    vector<string> availableB;
    vector<string> availableE;
    vector<string> availableD;
    vector<string> bookedE;
    vector<string> bookedD;
    vector<string> bookedB;
    vector<string> freeB;
    vector<string> freeE;
    vector<string> freeD;
    string departureTime;
    string arrivalTime;
    string source;
    string destination;
    string filename;
    int priceB;
    int priceE;
    int priceD;


    Cruise(string filename);

    // void updateBooking(string a);

    void deleteBooking(const string &targetString);

    void displayTypeDetails(vector<string> available, vector<string> booked);

    void displayCruiseDetails();

    void updateSeatStatus(char c, vector<string> seats, vector<string> free, vector<string> booked, string id);

    void updateNameDetailsInFile(const string& filename, int lineNumber, const string& newData);
};

#endif


/*
void Cruise::updateBooking(string a)
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
*/
#include<bits/stdc++.h>
#include "handleWaitingList.h"
using namespace std;

int HandleData::findLineNumber(const string& searchString, const string& filename){
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return -1; // Return -1 to indicate an error
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;

        // Check if the line contains the search string
        if (line.find(searchString) != string::npos) {
            file.close();
            return lineNumber;
        }
    }

    file.close();
    return -1; // Return -1 if the string is not found
}

// Function to trim spaces from both ends of a string
string HandleData::trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');

    if (first == string::npos) {
        return "";
    }

    return str.substr(first, (last - first + 1));
}

// Function to get data after the first colon and store each string in a vector
vector<string> HandleData::getDataAfterColon(const string& line) {
    vector<string> result;

    size_t colonPos = line.find(':');
    if (colonPos != string::npos && colonPos < line.length() - 1) {
        string data = line.substr(colonPos + 1);
        
        // Tokenize the string based on spaces
        istringstream iss(data);
        string token;

        while (iss >> token) {
            // Remove spaces from each token
            token = trim(token);
            result.push_back(token);
        }
    }

    return result;
}

// Function to read a particular line from a file
string HandleData::readLineFromFile(const string& filename, int lineNumber) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return ""; // Return an empty string to indicate an error
    }

    string line;
    int currentLineNumber = 0;

    while (getline(file, line)) {
        currentLineNumber++;

        // Check if the current line number matches the desired line number
        if (currentLineNumber == lineNumber) {
            file.close();
            return line;
        }
    }

    file.close();
    return ""; // Return an empty string if the desired line number is not found
}
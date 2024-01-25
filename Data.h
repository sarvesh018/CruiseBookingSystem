#include <bits/stdc++.h>
#ifndef DATA
#define DATA
using namespace std;

class Data{
    public:
        vector<string> names;
        vector<string> ids;
        string line;
        int nameNum = 2, idNum = 5;
    public:
        // constructor to fill names and id vectors with data
        Data(const string& filename);

        // updating the name and ids
        void updateNames(string newName);
        void updateID(string newNum);

        string getNames();
        string getIDs();
        
        // delete passenger
        void deletePassenger(string name, const string& filename);

        // add updated data into file
        void updateNameDetailsInFile(const string& filename, int lineNumber, const string& newData);
};

#endif

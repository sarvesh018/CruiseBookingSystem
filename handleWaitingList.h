#include<bits/stdc++.h>
#ifndef HANDLE
#define HANDLE
using namespace std;

class HandleData{
    public:
        int findLineNumber(const string& searchString, const string& filename);
        string trim(const string& str);
        vector<string> getDataAfterColon(const string& line);
        string readLineFromFile(const string& filename, int lineNumber);
};

#endif
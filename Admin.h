#include<bits/stdc++.h>
using namespace std;

#ifndef ADMIN
#define ADMIN
class Admin{
    private:
        string username;
        string password;
    public:
        Admin();
        void welcome();
        bool authenticate(string user, string pass);
};

#endif
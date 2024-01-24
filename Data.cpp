#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Customer{
    public: 
        string name;
        int id;
        
};

class Data{
    public:
        vector<string> names;
        vector<int> ids;
        string line;
        int nameNum = 2, idNum = 5;
    public:
        Data(const string& filename){
            ifstream file(filename);
            int currentLine = 0;
            if (file.is_open()) {
                while (getline(file, line)) {
                    currentLine++;
                    if (currentLine == nameNum) {
                        istringstream iss(line);
                        string s;
                        while(getline(iss, s, ',')){
                            names.push_back(s);
                        }
                    }
                    else if(currentLine == idNum){
                        istringstream iss(line);
                        string s;
                        while(getline(iss, s, ',')){
                            ids.push_back(stoi(s));
                        }
                    }
                }
                file.close();
            } 
            else {
                cerr << "Error opening file!" << std::endl;
            }
        }
};

int main() {

    Data data("temp.txt");
    cout<<"\n---------Names of Customer--------"<<endl;
    for(int i=0; i<data.names.size(); i++){
        cout<<(i+1)<<") "<<data.names[i]<<endl;
    }    

    cout<<"\n---------ID's of Customer--------"<<endl;
    for(int i=0; i<data.names.size(); i++){
        cout<<(i+1)<<") "<<data.ids[i]<<endl;
    }

    return 0;
}

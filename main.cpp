// C++ implementation to read
// file word by word
#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
#include <sstream>


std::vector<std::string> ipsCsv;
std::vector<std::string> Ips;
// driver code


void text(){
    fstream file;
    string line;
    string substring="IP <";
    string substring2=">";
   
    ifstream infile;
   
    infile.open("cisco-asa-2018-07-27.txt");
    
    if (infile.fail()){
        cout<<"Error opening";
        exit(EXIT_FAILURE);
    }
     while(getline(infile, line)) {
          std::istringstream iss(line);
          if (line.find(substring)!=std::string::npos){
                size_t first=line.find(substring);
                size_t last= line.find(substring2, first);
                string example=line.substr(first+4,last-first-4);
                Ips.push_back(example);
          }
     }
     return;
}


void csv(){
    ifstream ips("Export_allActivity.csv");
    string dummyline;
    getline(ips,dummyline);

    if (!ips.is_open()){
        std::cout<<"ERROR:File Open"<<endl;
    }
    
    string timestamp;
    string session;
    string ip;
    string username;
    string password;
    string success;
    string input;

    while(ips){
        getline(ips,timestamp,',');
        getline(ips,session,',');
        getline(ips,ip,',');
        getline(ips,username,',');
        getline(ips,password,',');
        getline(ips,success,'\n');

        if( ips.eof() ) {break;}

        ipsCsv.push_back(ip);
    }
    
    ips.close();
    return;
}

void compare(){
    for (int i=0;i<ipsCsv.size();i++){
        for (int j=0;j<Ips.size();j++){
            if (ipsCsv[i]==Ips[j]){
                cout<<Ips[j]<<endl;
            }
        
        }
    }
    cout<<"no matches"<<endl;
    
}

int main()
{
    // filestream variable file
    text();
    csv();
    compare();
    return 1;
}

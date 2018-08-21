#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
#include <sstream>
#include <algorithm>
#include<ctime>

std::vector<std::string> ipsCsv;
std::vector<std::string> Ips;
std::vector<std::string> matches;
std::vector<std::string> finalMatches;
std::vector<std::string>sophosSrc;

void text(string filename){
    fstream file;
    string line;
    string substring="IP <";
    string substring2=">";
   
    ifstream infile;
    infile.open( filename.c_str() );
    
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

void csv(string filenameCSV){
    ifstream ips(filenameCSV);
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

void sophos(string filename){
    fstream file;
    string line;
    string substring="srcip";
    string substring2="\" ";
   
    ifstream infile;
    infile.open( filename.c_str() );
    
    if (infile.fail()){
        cout<<"Error opening";
        exit(EXIT_FAILURE);
    }
     while(getline(infile, line)) {
          std::istringstream iss(line);
          if (line.find(substring)!=std::string::npos){
                size_t first=line.find(substring);
                size_t last= line.find(substring2, first);
                string example=line.substr(first+8,last-first-9);
                sophosSrc.push_back(example);
                cout<<example<<endl;
                
          }
     }
     return;
}

void compare(){
    int sizeIpsCsv=ipsCsv.size();
    int sizeIps=Ips.size();
    for (int i=0;i<sizeIpsCsv;i++){
        for (int j=0;j<sizeIps;j++){
            if (ipsCsv[i]==Ips[j]){
                matches.push_back(Ips[j]);
            }
        }
    }
    
    if (matches.size()==0){
        cout<<"No matches"<<endl;
    }

    else{
        // Declaring argument for time()
        time_t estTime;
        // Declaring variable to store return value of localtime()
        struct tm * ti;
        // Applying time()
        time (&estTime);
        // Using localtime()
        ti = localtime(&estTime);
        cout << "Current Day, Date and Time is = "<< asctime(ti);

        ofstream fileWrite;
        fileWrite.open("mymatches.txt");
        std::sort(matches.begin(), matches.end());

        int sizeMatches=matches.size();
        
        for (int t=0; t<sizeMatches-1; t++){
            if (matches[t]!=matches[t+1]){
                finalMatches.push_back(matches[t]);
            }
        }

        finalMatches.push_back(matches[sizeMatches-1]);
        fileWrite<< "Today's date "<< asctime(ti);
        int finalMatchesSize=finalMatches.size();
        for (int n=0; n<finalMatchesSize; n++){
            fileWrite<<finalMatches[n]<<endl;
            cout<<finalMatches[n]<<endl;
        }
        fileWrite.close();
    }
}
  
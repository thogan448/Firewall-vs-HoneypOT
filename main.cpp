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
std::vector<std::string> matches;
// driver code


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

void compare(){
    for (int i=0;i<ipsCsv.size();i++){
        for (int j=0;j<Ips.size();j++){
            if (ipsCsv[i]==Ips[j]){
                matches.push_back(Ips[j]);
                cout<<Ips[j]<<endl;
            }
        
        }
    }
    if (matches.size()==0){
        cout<<"No matches"<<endl;
    }
    
}

int main()
{
    // filestream variable file
    string filename;
    string filenameCSV;

    cout<<"Please enter file name for firewall data: ";
    cin>>filename;

    cout<<"Please enter name of Honeypot CSV: ";
    cin>>filenameCSV;

    cout<<"One moment, matches will be listed below:"<<endl;
    text(filename);
    csv(filenameCSV);
    compare();
    return 1;
}

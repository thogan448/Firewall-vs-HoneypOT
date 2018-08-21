#include <iostream>
#include <string>
using namespace std;
#include "matches.cc"

int main()
{
    string filename;
    string filenameCSV;

    cout<<"Please enter file name for firewall data: ";
    cin>>filename;

    cout<<"Please enter name of Honeypot CSV: ";
    cin>>filenameCSV;

    cout<<"One moment, matches will be listed below:"<<endl;
    text(filename);
    csv(filenameCSV);
    //sophos(filename);
    compare();
    return 1;
}

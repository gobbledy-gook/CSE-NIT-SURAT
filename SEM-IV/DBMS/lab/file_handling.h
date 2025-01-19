#include <iostream>
#include <fstream>
using namespace std;

void fileRead(string path){
    ifstream fptr;
    fptr.open(path);
    string data;
    while(fptr.good()){
        getline(fptr, data);
        cout << data <<"\n";
    }
    fptr.close();
}

void fileWrite(string path){
    ofstream fptr;
    fptr.open(path);
    string data;
    cin >> data;
    fptr << data;
    getline(cin,data);
    fptr << data;
    fptr.close();
}

void fileAppend(string path){
    ofstream fptr;
    fptr.open(path, ios::app);
    string data;
    cin >> data;
    fptr << data;
    getline(cin,data);
    fptr << data;
    fptr.close();
}
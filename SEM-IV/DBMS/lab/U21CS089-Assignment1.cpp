#include <iostream>
#include <fstream>
#include "file_handling.h"
using namespace std;

int main(){
    int n;
    string path;
    path = "/Users/garvitshah/Desktop/College/Current Sem/Subjects/DBMS/lab/Sample.txt";
    while(1){
        cout << "\n------FILE HANDLING------\n1. Read\n2. Write\n3. Append\n0. Exit\n--> ";
        cin >> n;
        if(n == 1){
            fileRead(path);
        }
        else if(n  == 2){
            fileWrite(path);
        }
        else if(n == 3){
            fileAppend(path);
        }
        else if(n == 0){
            break;
        }
    }

}

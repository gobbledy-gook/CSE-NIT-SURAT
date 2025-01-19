#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string encrypt(string s, int k){
    string a = "";
    int ch;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            s[i] = toupper(s[i]);
        }
    }
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            a += ' ';
        }
        else{
            ch = s[i];
            a += (char)((((ch-65) + k) % 26)+65);
        }
    }
    return a;
}

int main(){
    int k = 3;
    string s;
    cout << "Enter the plain text: ";
    getline(cin, s);
    // cout << "\nEnter the key value: ";

    string enc = encrypt(s, k);
    cout << "Encrypted Text - " << enc;
    return 0;
}
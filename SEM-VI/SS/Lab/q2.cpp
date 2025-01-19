#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfa(int state, string a, int pos, int b){
    int n;
    if(state == 1){
        n = 1;
    }
    else{
        n = 2;
    }
    while(pos < a.size()){
        b = b^1;
        // cout << (int)a[pos] << '\n';
        if((int)a[pos] == b){
            state = state^n;
            cout << a[pos] << " - State " <<  state << '\n'; 
        }
        else{
            return 0;
        }
        pos++;
    }
    return 1;
}

int main(){
    string a;
    cout << "Enter the string of 1's and 0's: ";
    int i = 0;
    cin >> a;
    cout << "Starting at State 0 \n";
    int b=(int)a[0];
    if(b == '0'){
        cout << a[0] << " - State 1\n";
        if(dfa(1, a, 1, b)){
            cout << "Valid";
        }
        else{
            cout << "Invalid";
        }
    }
    else if(b == '1'){
        cout << a[0] << " - State 2\n";
        if(dfa(1, a, 1, b)){
            cout << "Valid";
        }
        else{
            cout << "Invalid";
        }
    }
    else{
        cout << "Invalid String.";
        return 0;
    }
    // cout << "Valid String.";
    return 0;
}
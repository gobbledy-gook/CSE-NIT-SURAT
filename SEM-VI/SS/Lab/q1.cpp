#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        string a;
        int i = 0;
        cout << "\nEnter the string: ";
        cin >> a;
        if(a.size() == 0){
            cout << "\nValid String.";
        }
        else{
            int i = 0;
            if(a[i] == 'a'){
                while(a[i] == 'a' && i < a.size()){
                    i++;
                }
            }
            if(a[i] == 'b' && i <a.size()){
                while(a[i] == 'b' && i <a.size()){
                    i++;
                } 
            }
            if(i >= a.size()){
                cout << "\nValid String.";
            }
            else{
                cout << "\nInvalid String.";
            }
        }
    }
    return 0;
}
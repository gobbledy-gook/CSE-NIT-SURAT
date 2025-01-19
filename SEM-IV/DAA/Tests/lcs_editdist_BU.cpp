#include<iostream>
#include <string>
#include<math.h>
#include <vector>
using namespace std;

int led(string a, string b, int m, int n, vector <vector <int>>v){
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <=n; j++){
            if(i==0){
               v[i][j] = j; 
            }
            else if(j == 0){
                v[i][j] = i;
            }
            else if(a[i - 1] == b[j - 1]){
                v[i][j] = min(v[i][j], v[i-1][j-1]);
            }
            else{
                v[i][j] = min({v[i][j], 1 + v[i-1][j], 1 + v[i][j-1]});
            }
        }
    } 
    return v[m][n];
    // if(v[m][n] != -1){
    //     return v[m][n];
    // }
    // int ans=INT_MAX;
    // if(a[m]==b[n]){
    //     ans = min(ans, led(a,b,m - 1,n - 1, v));
    // }
    // ans = min({ans, 1 + led(a,b,m,n-1, v), 1 + led(a,b,m-1,n, v)});
    // return v[m][n]=ans;

}

int main(){
    string a = "garvit";
    string b = "samarth";
    vector<vector<int>> v(a.length() + 1,vector<int> (b.length() + 1, INT_MAX));
    cout << led(a,b,a.length(),b.length(),v);
    return 0;
}
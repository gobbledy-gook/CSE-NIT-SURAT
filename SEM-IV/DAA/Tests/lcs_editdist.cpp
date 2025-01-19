#include<iostream>
#include <string>
#include<math.h>
#include <vector>
using namespace std;

int led(string a, string b, int m, int n, vector <vector <int>>&v){
    if(m<0){
        return n+1; 
    }
    if(n<0){
        return m+1;
    }
    if(v[m][n] != -1){
        return v[m][n];
    }
    int ans=INT_MAX;
    if(a[m]==b[n]){
        ans = min(ans, led(a,b,m - 1,n - 1, v));
    }
    ans = min({ans, 1 + led(a,b,m,n-1, v), 1 + led(a,b,m-1,n, v)});
    return v[m][n]=ans;
}

int main(){
    string a = "garvit";
    string b = "samarth";
    vector<vector<int>> v(a.length(),vector<int> (b.length(),-1)); 
    cout<<led(a,b,a.length()-1,b.length()-1, v);
    return 0;
}
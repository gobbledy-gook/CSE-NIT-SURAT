#include<iostream>
#include <string>
#include<math.h>
#include <vector>
using namespace std;

int led(string a, string b, int m, int n, string &s){
    if(m<0){
        return n+1; 
    }
    if(n<0){
        return m+1;
    }
    // if(v[m][n] != -1){
    //     return v[m][n];
    // }
    int ans=INT_MAX;
    if(a[m]==b[n]){
        s+=a[m];
        ans = min(ans, 1 + led(a,b,m - 1,n - 1,s));
    }
    ans = min({ans, 1 + led(a,b,m,n-1,s+b[n]), 2 + led(a,b,m - 1,n-1, s), 1 + led(a,b,m - 1,n,s)});
    if((a.length() == m+1) && (b.length() == n+1)){
        cout << s << endl;
        reverse(s.begin(),s.end());
        cout << s << endl;
    }
    return ans;
}

int main(){
    string a = "abca";
    string b = "acdb";
    string s = "";
    // vector<vector<int>> v(a.length(),vector<int> (b.length(),-1)); 
    cout<<led(a,b,a.length()-1,b.length()-1, s);
    return 0;
}
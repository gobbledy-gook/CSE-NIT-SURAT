#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int editDistance(string s1, string s2, int m, int n, vector<vector<int>>& dp) {
    // If one of the strings is empty, return the length of the other string
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    // If the result is already computed, return it
    if (dp[m-1][n-1] != -1) {
        return dp[m-1][n-1];
    }

    // If the last characters of the strings match, we don't need to perform any operation
    if (s1[m-1] == s2[n-1]) {
        dp[m-1][n-1] = editDistance(s1, s2, m-1, n-1, dp);
        return dp[m-1][n-1];
    }

    // Otherwise, we take the minimum of the three operations (insertion, deletion, substitution)
    dp[m-1][n-1] = 1 + min({editDistance(s1, s2, m, n-1, dp),    // Insert a character into s1
                    editDistance(s1, s2, m-1, n, dp),    // Delete a character from s1
                    editDistance(s1, s2, m-1, n-1, dp)}); // Substitute a character in s1
    return dp[m-1][n-1];
}

int main()
{
   string s1,s2;
    cout<<"Enter string1: "<<endl;
    cin>>s1;
    cout<<"Enter string2: "<<endl;
    cin>>s2;
    int m = s1.length(), n = s2.length();
    
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "The min no of operations to convert " << s1 << " to " << s2 << " is " << editDistance(s1, s2, m, n, dp) << endl;
    return 0;
}

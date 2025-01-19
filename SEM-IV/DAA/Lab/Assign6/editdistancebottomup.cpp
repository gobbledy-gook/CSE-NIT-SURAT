#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int editDistance(string s1, string s2, int m, int n) {
    // Create a 2D array to store the edit distances
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // Fill the first row and column with the distances to an empty string
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Iterate over the remaining substrings and compute the edit distances
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min({dp[i][j-1],    // Insert a character into s1
                                     dp[i-1][j],    // Delete a character from s1
                                     dp[i-1][j-1]});// Substitute a character in s1
            }
        }
    }

    // The final edit distance is stored in dp[m][n]
    return dp[m][n];
}

int main()
{
    string s1,s2;
    cout<<"Enter string1: "<<endl;
    cin>>s1;
    cout<<"Enter string2: "<<endl;
    cin>>s2;
    int m = s1.length(), n = s2.length();
    cout << "The min no of operations to convert " << s1 << " to " << s2 << " is " << editDistance(s1, s2, m, n) << endl;
    return 0;
}

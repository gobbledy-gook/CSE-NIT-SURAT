#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int longestPalSubseq(string str) {
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: a single character is a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill up the dp table bottom-up
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && len == 2) {
                dp[i][j] = 2;
            }
            else if (str[i] == str[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    cin>>str;

    cout << "The length of the longest palindromic substring is " << longestPalSubseq(str) << endl;
    return 0;
}

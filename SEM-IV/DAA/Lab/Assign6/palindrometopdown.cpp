#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int longestPalSubseq(string str, int start, int end, vector<vector<int>> &dp)
{
    if(dp[start][end] != -1)
        return dp[start][end];

    if(start == end) // Base case: length 1 subsequence
        return dp[start][end] = 1;

    if(str[start] == str[end] && start + 1 == end) // Base case: length 2 subsequence
        return dp[start][end] = 2;

    if(str[start] == str[end]) // Recursive case: include start and end characters
        return dp[start][end] = longestPalSubseq(str, start+1, end-1, dp) + 2;

    // Recursive case: exclude start or end character
    return dp[start][end] = max(longestPalSubseq(str, start+1, end, dp), longestPalSubseq(str, start, end-1, dp));
}

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    cin>>str;
    int n =str.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "The length of the longest palindromic substring is " << longestPalSubseq(str, 0, n-1, dp) << endl;
    return 0;
}

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int longestPalSubseq(string str)
{
    int n = str.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int cl = 2; cl <= n; cl++)
    {
        for (int i = 0; i < n-cl+1; i++)
        {
            int j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
                dp[i][j] = 2;
            else if (str[i] == str[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
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

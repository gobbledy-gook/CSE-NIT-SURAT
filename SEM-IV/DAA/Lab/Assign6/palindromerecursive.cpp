#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int longestPalSubseq(string str, int start, int end)
{
    if(start == end) // Base case: length 1 subsequence
        return 1;

    if(str[start] == str[end] && start + 1 == end) // Base case: length 2 subsequence
        return 2;

    if(str[start] == str[end]) // Recursive case: include start and end characters
        return longestPalSubseq(str, start+1, end-1) + 2;

    // Recursive case: exclude start or end character
    return max(longestPalSubseq(str, start+1, end), longestPalSubseq(str, start, end-1));
}

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    cin>>str;
    int n =str.size();
    cout << "The length of the longest palindromic substring is " << longestPalSubseq(str, 0, n-1) << endl;
    return 0;
}

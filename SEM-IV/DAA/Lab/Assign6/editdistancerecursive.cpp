#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int editDistance(string s1, string s2, int m, int n) {
    // If one of the strings is empty, return the length of the other string
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    // If the last characters of the strings match, we don't need to perform any operation
    if (s1[m-1] == s2[n-1]) {
        return editDistance(s1, s2, m-1, n-1);
    }

    // Otherwise, we take the minimum of the three operations (insertion, deletion, substitution)
    return 1 + min({editDistance(s1, s2, m, n-1),    // Insert a character into s1
                    editDistance(s1, s2, m-1, n),    // Delete a character from s1
                    editDistance(s1, s2, m-1, n-1)}); // Substitute a character in s1
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

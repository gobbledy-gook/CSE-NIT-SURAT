#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum value that can be obtained
// by cutting the rod and selling the pieces separately
int cutRod(vector<int>& price, int n, vector<int>& memo) {
    // Base case
    if (n == 0) {
        return 0;
    }

    // Check if the result is already in the memoization table
    if (memo[n] != -1) {
        return memo[n];
    }

    int maxVal = INT_MIN;

    // Recursively cut the rod in different pieces and
    // compare the maximum value obtained
    for (int i = 1; i <= n; i++) {
        maxVal = max(maxVal, price[i - 1] + cutRod(price, n - i, memo));
    }

    // Memoize the result
    memo[n] = maxVal;

    return maxVal;
}

int main() {
    vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = price.size();

    // Initialize memoization table with -1
    vector<int> memo(n + 1, -1);

    int maxVal = cutRod(price, n, memo);

    cout << "Maximum value that can be obtained is: " << maxVal << endl;

    return 0;
}

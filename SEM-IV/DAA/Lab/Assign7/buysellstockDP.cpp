#include <iostream>
#include <vector>

using namespace std;

    int c(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }
        int ans;
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        if (buy) {
            ans = max(-1 * prices[i] + c(i + 1, 0, prices, dp), c(i + 1, 1, prices, dp));
        }
        else {
            ans = max(prices[i] + c(i + 1, 1, prices, dp), c(i + 1, 0, prices, dp));
        }
        dp[i][buy] = ans;
        return ans;
    }

    int maxProfit(vector<int> prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return c(0, 1, prices, dp);
    }


int main() {
    vector<int> prices = {7, 1, 5, 8, 6, 4};
    int maxPfit = maxProfit(prices);
    cout << "Max Profit: " << maxPfit << endl;
    return 0;
}
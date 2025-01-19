#include <iostream>
#include <vector>

using namespace std;

    int maxProfit(vector<int>& prices) {
        int ans=0;
        int x=prices[0];
        for (int i=1; i<prices.size(); i++) {
            if (x > prices[i]) {
                x = prices[i];
            }
            else {
                ans += prices[i] - x;
                x = prices[i];
            }
        }
        return ans;
    }

int main() {
    vector<int> prices = {7, 1, 5, 3, 1, 2};
    int maxPfit = maxProfit(prices);
    cout << "Max Profit: " << maxPfit << endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices)
{
    int diff, mdiff=INT_MIN;
    int buy=prices[0],sell;
    for(int i=1;i<prices.size();i++)
    {
        sell=prices[i];
        diff=sell-buy;
        mdiff=max(mdiff,diff);
        if(diff<0) buy=prices[i];
    }
    if(mdiff<0) return 0;
    return mdiff;
}
// ...existing code...

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {7,1,5,3,6,4},          // Standard case with profit
        {7,6,4,3,1},            // Decreasing prices, no profit
        {1},                    // Single price
        {1,2},                  // Two prices with profit
        {2,1},                  // Two prices without profit
        {3,3,3,3}              // Same prices
    };

    // Expected results
    vector<int> expected = {5, 0, 0, 1, 0, 0};

    // Run tests
    for(int i = 0; i < testCases.size(); i++) {
        int result = maxProfit(testCases[i]);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Prices: [";
        for(int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j];
            if(j < testCases[i].size() - 1) cout << ",";
        }
        cout << "]\n";
        cout << "Expected Profit: " << expected[i] << "\n";
        cout << "Got Profit: " << result << "\n";
        cout << (result == expected[i] ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}
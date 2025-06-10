#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> leaders(vector<int>& nums) {
    vector<int>res;
    int n=nums.size(),max=nums[n-1];
    res.push_back(nums[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]>max) 
        {
            res.push_back(nums[i]);
            max=nums[i];
        }
    }
    return res;
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {16, 17, 4, 3, 5, 2},        // Multiple leaders
        {1, 2, 3, 4, 5},             // One leader (last element)
        {5, 4, 3, 2, 1},             // All elements are leaders
        {1},                         // Single element
        {2, 2, 2, 2},               // All equal elements
        {1, 7, 4, 3, 9, 2}          // Leaders in middle
    };

    // Expected results (leaders in reverse order)
    vector<vector<int>> expected = {
        {2, 5, 17},
        {5},
        {1, 2, 3, 4, 5},
        {1},
        {2},
        {2, 9}
    };

    cout << "Testing Leaders in Array Implementation\n\n";

    for(int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        
        // Print input
        cout << "Input Array: [";
        for(int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j];
            if(j < testCases[i].size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Get result
        vector<int> result = leaders(testCases[i]);
        reverse(result.begin(), result.end());  // Reverse to match expected order

        // Print expected output
        cout << "Expected Leaders: [";
        for(int j = 0; j < expected[i].size(); j++) {
            cout << expected[i][j];
            if(j < expected[i].size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Print actual output
        cout << "Got Leaders: [";
        for(int j = 0; j < result.size(); j++) {
            cout << result[j];
            if(j < result.size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Verify result
        bool passed = (result == expected[i]);
        cout << (passed ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int>pos,neg;
    int n=nums.size();
    for (int i=0;i<n;i++)
    {
        if(nums[i]>0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }
    int idx=min(pos.size(),neg.size()), rest=max(pos.size(),neg.size());
    for(int i=0;i<idx;i++)
    {
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
        }
    int index=2*idx;
    for(int i=idx;i<rest;i++)
    {
        if(neg.size()>pos.size())
        { nums[index] = neg[i];
        index++;
        }

        else{
        nums[index] = pos[i];
        index++;
        }
    }
    return nums;
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {1, -1, 2, -2, 3, -3},             // Equal positives and negatives
        {1, 2, -3, -1, -2, 3},             // Unordered equal numbers
        {1, 2, 3, -1, -2},                 // More positives than negatives
        {-1, -2, -3, 1, 2},                // More negatives than positives
        {1},                               // Single positive
        {-1, 1, -2, 2, -3, 3, 4}          // Unequal with extra positive
    };

    // Expected results
    vector<vector<int>> expected = {
        {1, -1, 2, -2, 3, -3},
        {1, -3, 2, -1, 3, -2},
        {1, -1, 2, -2, 3},
        {1, -1, 2, -2, -3},
        {1},
        {1, -1, 2, -2, 3, -3, 4}
    };

    cout << "Testing Rearrange Array Implementation\n\n";

    for(int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        
        // Print input
        cout << "Input: [";
        for(int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j];
            if(j < testCases[i].size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Test implementation
        vector<int> result = rearrangeArray(testCases[i]);

        // Print expected output
        cout << "Expected: [";
        for(int j = 0; j < expected[i].size(); j++) {
            cout << expected[i][j];
            if(j < expected[i].size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Print actual output
        cout << "Got: [";
        for(int j = 0; j < result.size(); j++) {
            cout << result[j];
            if(j < result.size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Check if test passed
        bool passed = (result == expected[i]);
        cout << (passed ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}
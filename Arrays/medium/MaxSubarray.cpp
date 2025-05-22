#include<iostream>
#include<vector>
using namespace std;
vector<int> kadanes(vector<int>arr)
{
    vector<int>res;
    int sum=0, maxSum=INT_MIN;
    int l=0,start=0,r;
    for(int i=0;i<arr.size();i++)
    {
        if(sum==0) l=i;
        sum+=arr[i];
        if(sum>maxSum){
            maxSum=sum;
            r=i;
            start=l;
        }
        if (sum<0) sum=0;
    }
    for(int i=start;i<r+1;i++)
    {
        res.push_back(arr[i]);
    }
    return res;
}

// ...existing code...

int main() {
    // Test cases with input arrays
    vector<vector<int>> testCases = {
        {-2, 1, -3, 4, -1, 2, 1, -5, 4},     // Standard case
        {1, 2, 3, 4},                         // All positive
        {-1, -2, -3, -4},                     // All negative
        {-1},                                 // Single negative
        {5},                                  // Single positive
        {1, -2, 3, -4, 5, -6, 7}             // Alternating
    };

    // Expected subarrays
    vector<vector<int>> expected = {
        {4, -1, 2, 1},          // Sum = 6
        {1, 2, 3, 4},           // Sum = 10
        {-1},                   // Sum = -1
        {-1},                   // Sum = -1
        {5},                    // Sum = 5
        {7}                     // Sum = 7
    };

    // Run tests
    for(int i = 0; i < testCases.size(); i++) {
        vector<int> result = kadanes(testCases[i]);
        cout << "Test Case " << i + 1 << ":\n";
        
        // Print input
        cout << "Input: [";
        for(int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j];
            if(j < testCases[i].size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Print expected
        cout << "Expected subarray: [";
        for(int j = 0; j < expected[i].size(); j++) {
            cout << expected[i][j];
            if(j < expected[i].size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Print result
        cout << "Got subarray: [";
        for(int j = 0; j < result.size(); j++) {
            cout << result[j];
            if(j < result.size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Check if arrays match
        bool passed = (result == expected[i]);
        cout << (passed ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}
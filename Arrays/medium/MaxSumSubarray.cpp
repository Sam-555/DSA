#include<iostream>
#include<vector>
using namespace std;
int kadanes(vector<int>arr)
{
    int sum=0, maxSum=INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        maxSum=max(maxSum,sum);
        if (sum<0) sum=0;
    }
    return maxSum;
}

// ...existing code...

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {-2, 1, -3, 4, -1, 2, 1, -5, 4},     // Standard case with mix of positive and negative
        {1, 2, 3, 4},                         // All positive numbers
        {-1, -2, -3, -4},                     // All negative numbers
        {-1},                                 // Single negative element
        {5},                                  // Single positive element
        {1, -2, 3, -4, 5, -6, 7}             // Alternating positive and negative
    };

    // Expected results
    vector<int> expected = {6, 10, -1, -1, 5, 7};

    // Run tests
    for(int i = 0; i < testCases.size(); i++) {
        int result = kadanes(testCases[i]);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Input: [";
        for(int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j];
            if(j < testCases[i].size() - 1) cout << ",";
        }
        cout << "]\n";
        cout << "Expected: " << expected[i] << "\n";
        cout << "Got: " << result << "\n";
        cout << (result == expected[i] ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}
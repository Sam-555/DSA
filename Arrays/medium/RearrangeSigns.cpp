#include<iostream>
#include<vector>
using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int>neg,pos;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i]>0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0) nums[i]=pos[j];
        else 
        {
            nums[i]=neg[j];
            j++;
        }
    }
    return nums;
}

vector<int> rearrangeArrayOptimized(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>res(n,0);
        int pos=0,neg=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                res[pos]=nums[i];
                pos+=2;
            }
            else{
                res[neg]=nums[i];
                neg+=2;
            }
        }
        return res;
    }

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {3,1,-2,-5,2,-4},           // Standard case
        {1,-1},                     // Minimum length case
        {1,2,-3,-4,5,-6},          // Multiple alternating signs
        {-1,-2,3,4,-5,6},          // Different starting order
        {1,-1,2,-2,3,-3}           // Sequential pairs
    };

    // Expected results (alternating positive and negative)
    vector<vector<int>> expected = {
        {3,-2,1,-5,2,-4},
        {1,-1},
        {1,-3,2,-4,5,-6},
        {3,-1,4,-2,6,-5},
        {1,-1,2,-2,3,-3}
    };

    cout << "Testing Rearrange Array Implementations\n\n";

    for(int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        
        // Print input
        cout << "Input: [";
        for(int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j];
            if(j < testCases[i].size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Test both implementations
        vector<int> result1 = rearrangeArray(testCases[i]);
        vector<int> nums2 = testCases[i];  // Create copy for second test
        vector<int> result2 = rearrangeArrayOptimized(nums2);

        // Print results
        cout << "Expected: [";
        for(int j = 0; j < expected[i].size(); j++) {
            cout << expected[i][j];
            if(j < expected[i].size() - 1) cout << ", ";
        }
        cout << "]\n";

        cout << "Method 1: [";
        for(int j = 0; j < result1.size(); j++) {
            cout << result1[j];
            if(j < result1.size() - 1) cout << ", ";
        }
        cout << "] - " << (result1 == expected[i] ? "PASSED" : "FAILED") << "\n";

        cout << "Method 2: [";
        for(int j = 0; j < result2.size(); j++) {
            cout << result2[j];
            if(j < result2.size() - 1) cout << ", ";
        }
        cout << "] - " << (result2 == expected[i] ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}
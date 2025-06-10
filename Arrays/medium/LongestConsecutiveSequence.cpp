#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size(),length=1,maxi=0;
    if(n==0||n==1) return n;
    for(int i=0;i<n-1;i++)
    {
        if(nums[i]+1==nums[i+1]) length++;
        else if (nums[i]==nums[i+1]) maxi=max(maxi,length);
        else length=1;
        maxi=max(maxi,length);        
    }
    return maxi;
}
int longestConsecutive1(vector<int>& nums)
{
    unordered_set<int> st;
    if(nums.size()==0) return 0;
    int maxi=1;
    for (int i : nums) st.insert(i);
    for(int i: st)
    {
        int cnt=0;
        if(st.find(i-1)==st.end())
        {
            cnt++;
            int curr=i;
            while(st.find(curr+1)!=st.end()){
                cnt++;
                curr++;
            }
            maxi=max(maxi,cnt);
        }
    }
    return maxi;
}


int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {100,4,200,1,3,2},          // Basic case with gap
        {0,3,7,2,5,8,4,6,0,1},      // Continuous sequence with duplicate
        {1,2,3,4,5},                // Continuous sequence
        {1},                        // Single element
        {1,1,1,1},                  // All same elements
        {9,1,4,7,3,-1,0,5,8,-1,6}   // Negative numbers included
    };

    // Expected results
    vector<int> expected = {4, 9, 5, 1, 1, 7};

    cout << "Testing Longest Consecutive Sequence Implementations\n\n";

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
        vector<int> test1 = testCases[i];
        vector<int> test2 = testCases[i];
        int result1 = longestConsecutive(test1);
        int result2 = longestConsecutive1(test2);

        cout << "Expected Length: " << expected[i] << "\n";
        cout << "Sorting Method: " << result1 << " - " 
             << (result1 == expected[i] ? "PASSED" : "FAILED") << "\n";
        cout << "Set Method: " << result2 << " - " 
             << (result2 == expected[i] ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}
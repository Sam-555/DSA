#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> nextPermutation(vector<int>& nums) {
    vector<int>x;
    long digit=0;
    for(int i=0;i<nums.size();i++){
        digit+=pow(10,nums.size()-1-i)*nums[i];
    }
    sort(nums.begin(),nums.end(),greater<int>());
    long maxi=0;
    for(int i=0;i<nums.size();i++){
        maxi+=pow(10,nums.size()-1-i)*nums[i];
    }
    if(digit==maxi) {
        sort(nums.begin(),nums.end());
        return nums;
    }
    for(int i=digit+1;i<maxi;i++)
    {
        int n=i;
        while(n>0)
        {
            x.push_back(n%10);
            n=n/10;
        }
        vector<int>a=x;
        sort(x.begin(),x.end(),greater<int>());
        reverse(a.begin(),a.end());
        if (nums==x) {
            nums=a;
            break;
        }
        x.clear();
    }  
    return nums;
}

vector<int> nextPermutation2(vector<int>& nums) {
    int break_p=INT_MIN,idx;
    for(int i=nums.size()-1;i>0;i--)
    {
        if(nums[i]>nums[i-1]) {
            idx=i-1;
            break_p=nums[i-1];
            cout<<"bp"<<break_p<<endl;
            break;
        }
    }
    
    if (break_p==INT_MIN) {
        reverse(nums.begin(),nums.end());
        return nums;
    }
    else{
        int mini=9999999,indi;
        for(int i=idx+1;i<nums.size();i++)
        {
            if(nums[i]>nums[idx])
            {
                 mini=min(nums[i],mini);
            indi=i;
            cout<<mini<<endl;
            }
        }
        int temp;
        temp=nums[idx];
        nums[idx]=mini;
        nums[indi]=temp;
        sort(nums.begin()+idx+1,nums.end());
        return nums;
    }
}




int main() {
    // Test cases remain the same
    vector<vector<int>> testCases = {
        {1, 2, 3},          // Basic case
        {3, 2, 1},          // Descending order
        {1, 1, 5},          // Duplicate numbers
        {1},                // Single element
        {1, 3, 2},          // Middle change needed
        {2, 3, 1}           // Complex rearrangement
    };

    vector<vector<int>> expected = {
        {1, 3, 2},          // Next permutation of 123 is 132
        {1, 2, 3},          // Next permutation of 321 is 123 (cycles back)
        {1, 5, 1},          // Next permutation of 115 is 151
        {1},                // Single element stays same
        {2, 1, 3},          // Next permutation of 132 is 213
        {3, 1, 2}           // Next permutation of 231 is 312
    };

    cout << "Testing Next Permutation Implementations\n\n";

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
        vector<int> result1 = nextPermutation(test1);
        vector<int> result2 = nextPermutation2(test2);

        // Print expected output
        cout << "Expected: [";
        for(int j = 0; j < expected[i].size(); j++) {
            cout << expected[i][j];
            if(j < expected[i].size() - 1) cout << ", ";
        }
        cout << "]\n";

        // Print results from both implementations
        cout << "Method 1 (Original): [";
        for(int j = 0; j < result1.size(); j++) {
            cout << result1[j];
            if(j < result1.size() - 1) cout << ", ";
        }
        cout << "] - " << (result1 == expected[i] ? "PASSED" : "FAILED") << "\n";

        cout << "Method 2 (Optimized): [";
        for(int j = 0; j < result2.size(); j++) {
            cout << result2[j];
            if(j < result2.size() - 1) cout << ", ";
        }
        cout << "] - " << (result2 == expected[i] ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}
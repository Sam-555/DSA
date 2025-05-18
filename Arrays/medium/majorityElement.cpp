#include<iostream>
#include<vector>
#include<map>
#include <cmath>
using namespace std;
int majorityElement(vector<int>& nums) {
    map<int,int>mpp;
    int n=nums.size();
    for (int i=0;i<n;i++)
    {
        mpp[nums[i]]+=1;
    }
    for(auto& p:mpp)
    {
        if(p.second>floor(n/2))
        {
            return p.first;
        }
    }
    return -1;
}

int majorityElementMooreVoting(vector<int>& nums) {
        int cnt=0;
        int el;
        for (int i=0;i<nums.size();i++)
        {
            if(cnt==0){
                el=nums[i];
                cnt++;
            }
            else if(el==nums[i]) cnt++;
            else cnt--;
        }
        int c=0;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]==el) c++;
        }
        if (c>(nums.size()/2)) return el;
        return -1;
    }

int main() {
    // Test Case 1: Clear majority element
    vector<int> nums1 = {3, 3, 4, 2, 3, 3, 3};
    cout << "Test Case 1: " << majorityElement(nums1) << " (Expected: 3)" << endl;
    cout << "Test Case 1: " << majorityElementMooreVoting(nums1) << " (Expected: 3)" << endl;

    // Test Case 2: No majority element
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test Case 2: " << majorityElement(nums2) << " (Expected: -1 or any default value)" << endl;
    cout << "Test Case 2: " << majorityElementMooreVoting(nums2) << " (Expected: -1 or any default value)" << endl;

    // Test Case 3: All elements are the same
    vector<int> nums3 = {5, 5, 5, 5};
    cout << "Test Case 3: " << majorityElement(nums3) << " (Expected: 5)" << endl;
    cout << "Test Case 3: " << majorityElementMooreVoting(nums3) << " (Expected: 5)" << endl;

    // Test Case 4: Single element
    vector<int> nums4 = {10};
    cout << "Test Case 4: " << majorityElement(nums4) << " (Expected: 10)" << endl;
    cout << "Test Case 4: " << majorityElementMooreVoting(nums4) << " (Expected: 10)" << endl;

    // Test Case 5: Mixed positive and negative numbers
    vector<int> nums5 = {-1, -1, -1, 2, 2, -1};
    cout << "Test Case 5: " << majorityElement(nums5) << " (Expected: -1)" << endl;
    cout << "Test Case 5: " << majorityElementMooreVoting(nums5) << " (Expected: -1)" << endl;

    // Test Case 6: Majority element at the end
    vector<int> nums6 = {1, 2, 3, 3, 3, 3};
    cout << "Test Case 6: " << majorityElement(nums6) << " (Expected: 3)" << endl;
    cout << "Test Case 6: " << majorityElementMooreVoting(nums6) << " (Expected: 3)" << endl;

    return 0;
}
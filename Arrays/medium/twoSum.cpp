#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<int>twoSum(vector<int>& nums, int target) {
    map<int,int> mpp;
    
    for (int i=0;i<nums.size();i++)
    {
        int comp=target-nums[i];
        if(mpp.find(comp)!=mpp.end())
        {
            return {mpp[comp],i};
        }
        else
        {
            mpp[nums[i]]=i;
        }
    }
    return {};
}

vector<int> twoSum2pointer(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;
    vector<int>res;
    vector<int> n(nums);
    sort(nums.begin(),nums.end());
    while(left<right)
    {
        if ((nums[left]+nums[right])>target)
        {
            right--;
        }
        else if ((nums[left]+nums[right])<target)
        {
            left++;
        }
        else 
        {
            cout<<"l:"<<left<<"right:"<<right<<endl;
            auto st = find(n.begin(), n.end(), nums[left]);
            auto nd = find(n.rbegin(), n.rend(), nums[right]);
            int index1 = distance(n.begin(), st);
            int index2 = n.size() - 1 - distance(n.rbegin(), nd);
            res.push_back(index1);
            res.push_back(index2);
            break;
        }
    }
    return res;
}


int main() {
    // Test Case 1: Basic case
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    
    cout << "Test Case 1:\n";
    cout << "Hash Map Solution: ";
    vector<int> result1 = twoSum(nums1, target1);
    cout << "[" << result1[0] << "," << result1[1] << "]\n";
    
    cout << "Two Pointer Solution: ";
    vector<int> result1_2p = twoSum2pointer(nums1, target1);
    cout << "[" << result1_2p[0] << "," << result1_2p[1] << "]\n\n";

    // Test Case 2: Numbers in different order
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    
    cout << "Test Case 2:\n";
    cout << "Hash Map Solution: ";
    vector<int> result2 = twoSum(nums2, target2);
    cout << "[" << result2[0] << "," << result2[1] << "]\n";
    
    cout << "Two Pointer Solution: ";
    vector<int> result2_2p = twoSum2pointer(nums2, target2);
    cout << "[" << result2_2p[0] << "," << result2_2p[1] << "]\n\n";

    // Test Case 3: Same number used twice
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    
    cout << "Test Case 3:\n";
    cout << "Hash Map Solution: ";
    vector<int> result3 = twoSum(nums3, target3);
    cout << "[" << result3[0] << "," << result3[1] << "]\n";
    
    cout << "Two Pointer Solution: ";
    vector<int> result3_2p = twoSum2pointer(nums3, target3);
    cout << "[" << result3_2p[0] << "," << result3_2p[1] << "]\n";

    return 0;
}
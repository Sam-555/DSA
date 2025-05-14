#include<iostream>
#include<vector>
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
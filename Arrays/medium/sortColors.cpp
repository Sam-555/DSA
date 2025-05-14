#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sortColors(vector<int>& nums) {
        
    for (int i=1;i<nums.size();i++)
    {
        int j=i;
        while(j>0 && nums[j-1]>nums[j])
        {
            swap(nums[j-1],nums[j]);
            j--;
        }
    }
}
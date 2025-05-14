#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
           int count=0;
            int len=nums.size();
            map<int,int>mpp;
            for(int i=0;i<len;i++)
            {
                mpp[nums[i]]+=1;
            }
            for(auto it:mpp)
            {
                cout<<it.first<<" "<<it.second<<endl;
            }
            int index=0;
            for(auto it:mpp)
            {
                nums[index]=it.first;
                index++;
            }
            return mpp.size();
        }
        int remo(vector<int>&nums)
        {
            int count=0;
            int j=1;
            int i=0;
            while(j<nums.size()&&i<nums.size())
            {
                if(nums[i]!=nums[j])
                {
                    nums[i+1]=nums[j];
                    i++;
                }
                j++;
            }
            return i+1;
        }
    };
    int main() {
        Solution sol;
    
        // Example 1
        vector<int> nums1 = {1, 1, 2};
        int k1 = sol.remo(nums1);
        cout << "Output: " << k1 << ", nums = ";
        for (int i = 0; i < k1; i++) {
            cout << nums1[i] << " ";
        }
        cout << endl;
    
        // Example 2
        vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int k2 = sol.removeDuplicates(nums2);
        cout << "Output: " << k2 << ", nums = ";
        for (int i = 0; i < k2; i++) {
            cout << nums2[i] << " ";
        }
        cout << endl;
    
        return 0;
    }
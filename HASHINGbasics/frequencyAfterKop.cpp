#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1838. Frequency of the Most Frequent Element
//Given an array of integers nums and an integer k.In one operation, you can choose an index of nums and increment the element at that index by 1..
//Example 1:    Input: nums = [1,2,4], k = 5    Output: 3
//Example 2:    Input: nums = [1,4,8,13], k = 5    Output: 2
//Example 3:    Input: nums = [3,9,6], k = 2    Output: 1
class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            int len=nums.size()-1;
            if (len==0) return 0;
            int count =1;
            sort(nums.begin(),nums.end());
            while(len>-1)
            {
                int op=k;
                int ct=0;
                for(int i=len;i>=0;i--)
                {
                    if(nums[len]-nums[i]<=op)
                    {
                        op=op-(nums[len]-nums[i]);
                        if(op<0) break;
                        ct++;
                    }
                }
                count=max(count,ct);
                len--;
            }
            return count;
        }
    };
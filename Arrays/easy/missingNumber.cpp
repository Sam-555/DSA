#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n=nums.size();
            vector<int>hsh(n+1,0);
            for(int i=0;i<n;i++)
            {
                hsh[nums[i]]+=1;
            }
            int  miss;
            for(int i=0;i<n+1;i++)
            {
                if(hsh[i]==0)
                {
                    miss= i;
                }
    
            }
            return miss;
        }
        int SumOptimal(vector<int>& nums) {
            int numSum=0;
            int n=nums.size();
            int summ=(n*(n+1))/2;
            for(int i:nums)
            {
                numSum+=i;
            }
            if(summ==numSum) return 0;
            else return summ-numSum;
    
        }
    };
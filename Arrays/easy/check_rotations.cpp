#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        void rotate(vector<int>& nums,int n)
        {
            vector<int>arr;
            arr.insert(arr.begin(),nums.begin(),nums.end());
            int len=nums.size();
            for(int i=0;i<len-n;i++)
            {
                nums[i]=arr[i+n];
            }
            for(int i=0;i<n;i++)
            {
                nums[len-n+i]=arr[i];
            }
        }
        bool check(vector<int>& nums) {
            int rotations=0;
            vector<int>arr;
            arr.insert(arr.begin(),nums.begin(),nums.end());
            sort(arr.begin(),arr.end());
            int cnt;
            while(rotations<nums.size())
            {
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]==arr[i])
                    {
                        cnt++;
                    }
                }
                if(cnt==nums.size()) return true;
                rotations++;
                rotate(nums,1);
                for(int i: nums) cout<<i<<" ";
                cout<<endl;
                cnt=0;
            }
            return false;
        }
    };
    int main() {
    Solution sol;
    vector<int> nums = {3,4,5,1,2};
        
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
        
    bool isRotatedSorted = sol.check(nums);
        
    cout << "Is the array a rotated sorted array? " << (isRotatedSorted ? "Yes" : "No") << endl;
        
    return 0;
    }
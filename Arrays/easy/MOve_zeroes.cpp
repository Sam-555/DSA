#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public: 
        void moveZeroes(vector<int>& nums) {
            int n=nums.size();
            vector<int>zeroes;
            int j=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0) 
                {
                    zeroes.push_back(i-j);   
                    j++;  
                }           
            }
            int len=zeroes.size();
            for(int i:zeroes)
            {
                for(int k=i+1;k<n;k++)
                {
                    swap(nums[k-1],nums[k]);
                }
            }
        }
        void move0(vector<int>&nums)
        {
            int n=nums.size();
            int count =0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0) 
                {
                    count++;
                    cout<<" if i: "<<i<<" count: "<<count<<endl;
                }
                else{
                    cout<<"else i: "<<i<<" count: "<<count<<endl;
                    int k=i;
                    for(int j=count;j>0;j--)
                    {
                        swap(nums[k-1],nums[k]);
                        k--;
                        printVector(nums);
                    }
                }
            }
            
        }
        void optimal(vector<int>&nums)
        {
            int j=0;
            for(int i=1;i<nums.size();i++)
            {
                if(nums[j]==0)
                {
                    if(nums[i]!=0)
                    {
                        swap(nums[i],nums[j]);
                        j++;
                    }
                    
                } 
            }
        }
        void printVector(const vector<int>& nums) {
            for (int num : nums) {
                cout << num << " ";
            }
            cout << endl;
        }
    };
 
int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    sol.optimal(nums1);
    cout << "Test Case 1: ";
    sol.printVector(nums1); // Output: [1, 3, 12, 0, 0]
    
    // Test Case 2
    vector<int> nums2 = {0};
    sol.optimal(nums2);
    cout << "Test Case 2: ";
    sol.printVector(nums2); // Output: [0]
    
    // Test Case 3
    vector<int> nums3 = {0, 0, 1};
    sol.optimal(nums3);
    cout << "Test Case 3: ";
    sol.printVector(nums3); // Output: [1, 0, 0]
    
    return 0;
}  
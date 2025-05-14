#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    if(n==0) return;
    k=k%n;
    reverse(nums.begin(),nums.begin()+n-k);
    reverse(nums.end()-k,nums.end());
    reverse(nums.begin(),nums.end());
}
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 1;
    rotate(nums1, k1);
    cout << "Test Case 1: ";
    printVector(nums1); // Output: [5, 6, 7, 1, 2, 3, 4]

    // Test Case 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    rotate(nums2, k2);
    cout << "Test Case 2: ";
    printVector(nums2); // Output: [3, 99, -1, -100]

    // Test Case 3
    vector<int> nums3 = {1};
    int k3 = 0;
    rotate(nums3, k3);
    cout << "Test Case 3: ";
    printVector(nums3); // Output: [1]

     // Test Case 4
     vector<int> nums4 = {1, 2};
     int k4 = 3;
     rotate(nums4, k4);
     cout << "Test Case 4: ";
     printVector(nums4); // Output: [2, 1]
 
     // Test Case 5: No rotation
     vector<int> nums5 = {1, 2, 3, 4, 5};
     int k5 = 0;
     rotate(nums5, k5);
     cout << "Test Case 5: ";
     printVector(nums5); // Output: [1, 2, 3, 4, 5]
 
     // Test Case 6: Rotation equal to array size
     vector<int> nums6 = {1, 2, 3, 4, 5};
     int k6 = 5;
     rotate(nums6, k6);
     cout << "Test Case 6: ";
     printVector(nums6); // Output: [1, 2, 3, 4, 5]
 
     return 0;
 }
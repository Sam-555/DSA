#include<iostream>
#include<vector>
using namespace std;
bool searchInSorted(vector<int>& arr, int k) {

    // Your code here
    int left=0;
    int right=arr.size()-1;
    int mid;
    while(right>=left)
    {
        mid=left+(right-left)/2;
        if(arr[mid]==k) return true;
        else if(arr[mid]>k) right=mid-1;
        else left=mid+1;
    }
    return false;
}
int main() {
    // Test Case 1: Element is present in the array
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 3;
    cout << "Test Case 1: " << (searchInSorted(arr1, k1) ? "Found" : "Not Found") << endl; // Output: Found

    // Test Case 2: Element is not present in the array
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 6;
    cout << "Test Case 2: " << (searchInSorted(arr2, k2) ? "Found" : "Not Found") << endl; // Output: Not Found

    // Test Case 3: Empty array
    vector<int> arr3 = {};
    int k3 = 1;
    cout << "Test Case 3: " << (searchInSorted(arr3, k3) ? "Found" : "Not Found") << endl; // Output: Not Found

    // Test Case 4: Single element array, element is present
    vector<int> arr4 = {1};
    int k4 = 1;
    cout << "Test Case 4: " << (searchInSorted(arr4, k4) ? "Found" : "Not Found") << endl; // Output: Found

    // Test Case 5: Single element array, element is not present
    vector<int> arr5 = {1};
    int k5 = 2;
    cout << "Test Case 5: " << (searchInSorted(arr5, k5) ? "Found" : "Not Found") << endl; // Output: Not Found

    // Test Case 6: Element is the first element in the array
    vector<int> arr6 = {1, 2, 3, 4, 5};
    int k6 = 1;
    cout << "Test Case 6: " << (searchInSorted(arr6, k6) ? "Found" : "Not Found") << endl; // Output: Found

    // Test Case 7: Element is the last element in the array
    vector<int> arr7 = {1, 2, 3, 4, 5};
    int k7 = 5;
    cout << "Test Case 7: " << (searchInSorted(arr7, k7) ? "Found" : "Not Found") << endl; // Output: Found

    return 0;
}
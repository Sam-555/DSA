#include<iostream>
using namespace std;
int second_largest(int arr[],int n)
{
    //for arrays with only positive integers
    if (n<2) return -1;
    int maxi=arr[0];
    int sec=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxi)
        {
            sec=maxi;
            maxi=arr[i];
        }
        else if(arr[i]>sec && arr[i]<maxi)
        {
            sec=arr[i];
        }
    }
    return sec;
}
int main() {
    // Test Case 1
    int arr1[] = {12, 35, 1, 10, 34, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Test Case 1: " << second_largest(arr1, n1) << endl; // Output: 34

    // Test Case 2
    int arr2[] = {10, 5, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Test Case 2: " << second_largest(arr2, n2) << endl; // Output: 5

    // Test Case 3
    int arr3[] = {10, 10, 10};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Test Case 3: " << second_largest(arr3, n3) << endl; // Output: -1

    // Additional Test Case 4: Single element
    int arr4[] = {10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Test Case 4: " << second_largest(arr4, n4) << endl; // Output: -1

    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
int* BubbleSort(int arr[], int n)
{
    while(n)
    {
        int didSwap=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]>arr[i]){
                swap(arr[i-1],arr[i]);
                didSwap=1;
            }
        }
        if(didSwap==0) break;
        n--;
    }
    return arr;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void testBubbleSort() {
    // Test Case 1: Random Order
    int arr1[] = {64, 25, 12, 22, 11};
    int expected1[] = {11, 12, 22, 25, 64};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    BubbleSort(arr1, n1);
    cout << "Test Case 1: ";
    printArray(arr1, n1);

    // Test Case 2: Already Sorted
    int arr2[] = {1, 2, 3, 4, 5};
    int expected2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    BubbleSort(arr2, n2);
    cout << "Test Case 2: ";
    printArray(arr2, n2);

    // Test Case 3: Reverse Order
    int arr3[] = {5, 4, 3, 2, 1};
    int expected3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    BubbleSort(arr3, n3);
    cout << "Test Case 3: ";
    printArray(arr3, n3);

    // Test Case 4: Single Element
    int arr4[] = {10};
    int expected4[] = {10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    BubbleSort(arr4, n4);
    cout << "Test Case 4: ";
    printArray(arr4, n4);

    // Test Case 5: All Elements are the Same
    int arr5[] = {7, 7, 7, 7, 7};
    int expected5[] = {7, 7, 7, 7, 7};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    BubbleSort(arr5, n5);
    cout << "Test Case 5: ";
    printArray(arr5, n5);

    // Test Case 6: Negative Numbers
    int arr6[] = {-3, -1, -7, -5, -2};
    int expected6[] = {-7, -5, -3, -2, -1};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    BubbleSort(arr6, n6);
    cout << "Test Case 6: ";
    printArray(arr6, n6);
}

int main() {
    testBubbleSort();
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
void quickSort(int arr[],int low,int high)
{
    if(low>=high) return;
    int pivot=arr[low];
    int i=low, j=high;
    while(j>=i)
    {
        if(arr[i]>pivot&&arr[j]<pivot) 
        {
            swap(arr[i], arr[j]);
        }
        if(arr[i]<=pivot) i++;
        if(arr[j]>=pivot) j--;
    }
    swap(arr[low], arr[j]);
    quickSort(arr,low,j-1);
    quickSort(arr,j+1,high);
}
int Partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while(i<j)
    {   
        while(arr[i]<=pivot&&i<high) i++;
        while(arr[j]>=pivot&&j>low) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void qS(int arr[],int low,int high)
{
    if(low<high){
        int pIndex=Partition(arr,low,high);
        qS(arr,low,pIndex-1);
        qS(arr,pIndex+1,high);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void testQuickSort() {
    // Test Case 1: Random Order
    //int arr1[] = {64, 25, 12, 22, 11};
    int arr1[]={4,6,2,5,7,9,1,3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    qS(arr1, 0, n1 - 1);
    cout << "Test Case 1: ";
    printArray(arr1, n1);

    // Test Case 2: Already Sorted
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    quickSort(arr2, 0, n2 - 1);
    cout << "Test Case 2: ";
    printArray(arr2, n2);

    // Test Case 3: Reverse Order
    int arr3[] = {5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    quickSort(arr3, 0, n3 - 1);
    cout << "Test Case 3: ";
    printArray(arr3, n3);

    // Test Case 4: Single Element
    int arr4[] = {10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    quickSort(arr4, 0, n4 - 1);
    cout << "Test Case 4: ";
    printArray(arr4, n4);

    // Test Case 5: All Elements are the Same
    int arr5[] = {7, 7, 7, 7, 7};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    quickSort(arr5, 0, n5 - 1);
    cout << "Test Case 5: ";
    printArray(arr5, n5);

    // Test Case 6: Negative Numbers
    int arr6[] = {-3, -1, -7, -5, -2};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    quickSort(arr6, 0, n6 - 1);
    cout << "Test Case 6: ";
    printArray(arr6, n6);
}

int main() {
    testQuickSort();
    return 0;
}

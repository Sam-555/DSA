#include<iostream>
#include<algorithm>
using namespace std;
void m1(int arr[],int low,int mid,int high)
{
    int p1=low,p2=mid+1;
    int* temp=new int[high-low+1];
    int i=0;
    while(p1<mid+1 && p2<high+1)
    {
        if(arr[p1]<=arr[p2])
        {
            temp[i++]=arr[p1++];    
        }
        else{
            temp[i++]=arr[p2++];
        }
    }
    while(p1<=mid )
    {
        temp[i++]=arr[p1++];
    }
    while(p2<=high )
    {
        temp[i++]=arr[p2++];
    }
    for(int j=0;j<i;j++)
    {
        arr[low+j]=temp[j];
    }
    delete[] temp;
}
void mergeSort(int arr[],int low,int high)
{
    if(low==high) return;
    int mid =(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    m1(arr,low,mid,high);
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void testMergeSort() {
    // Test Case 1: Random Order
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    mergeSort(arr1, 0, n1 - 1);
    cout << "Test Case 1: ";
    printArray(arr1, n1);

    // Test Case 2: Already Sorted
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    mergeSort(arr2, 0, n2 - 1);
    cout << "Test Case 2: ";
    printArray(arr2, n2);

    // Test Case 3: Reverse Order
    int arr3[] = {5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    mergeSort(arr3, 0, n3 - 1);
    cout << "Test Case 3: ";
    printArray(arr3, n3);

    // Test Case 4: Single Element
    int arr4[] = {10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    mergeSort(arr4, 0, n4 - 1);
    cout << "Test Case 4: ";
    printArray(arr4, n4);

    // Test Case 5: All Elements are the Same
    int arr5[] = {7, 7, 7, 7, 7};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    mergeSort(arr5, 0, n5 - 1);
    cout << "Test Case 5: ";
    printArray(arr5, n5);

    // Test Case 6: Negative Numbers
    int arr6[] = {-3, -1, -7, -5, -2};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    mergeSort(arr6, 0, n6 - 1);
    cout << "Test Case 6: ";
    printArray(arr6, n6);
}

int main() {
    testMergeSort();
    return 0;
}

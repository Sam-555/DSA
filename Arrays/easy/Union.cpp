#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> findUnion(vector<int> &a, vector<int> &b) {
    // Your code here
    // return vector with correct order of elements
    vector<int>u;
    int i=0,j=0;
    while(i<a.size()&& j<b.size())
    {
        if(a[i]<=b[j])
        {
            //if(a[i]==b[j]) j++;
            if(u.empty() ||u.back()!=a[i])
            {
                u.push_back(a[i]);
            }
            i++;
            
        }
        else{
            if(u.empty() ||u.back()!=b[j])
            {
                u.push_back(b[j]);
            }
            j++;
        }
        
    }
    while(j<b.size())
    {
        if(u.back()!=b[j])
        {
            u.push_back(b[j]);
        }
        j++;
    }
    while(i<a.size())
    {
        if(u.back()!=a[i])
        {
            u.push_back(a[i]);
        }
        i++;
    }
    return u;
}
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    // Test Case 1
    vector<int> a1 = {1, 2, 3, 4, 5};
    vector<int> b1 = {2, 3, 5, 7};
    vector<int> res1 = findUnion(a1, b1);
    cout << "Test Case 1: ";
    printVector(res1); // Output: [1, 2, 3, 4, 5, 7]

    // Test Case 2
    vector<int> a2 = {1, 1, 1, 1, 1};
    vector<int> b2 = {2, 2, 2, 2, 2};
    vector<int> res2 = findUnion(a2, b2);
    cout << "Test Case 2: ";
    printVector(res2); // Output: [1, 2]

    // Test Case 3
    vector<int> a3 = {1, 3, 5, 7};
    vector<int> b3 = {2, 4, 6, 8};
    vector<int> res3 = findUnion(a3, b3);
    cout << "Test Case 3: ";
    printVector(res3); // Output: [1, 2, 3, 4, 5, 6, 7, 8]

    // Test Case 4
    vector<int> a4 = {6};
    vector<int> b4 = {1, 2, 3};
    vector<int> res4 = findUnion(a4, b4);
    cout << "Test Case 4: ";
    printVector(res4); // Output: [1, 2, 3]

    // Test Case 5
    vector<int> a5 = {1, 2, 3};
    vector<int> b5 = {3};
    vector<int> res5 = findUnion(a5, b5);
    cout << "Test Case 5: ";
    printVector(res5); // Output: [1, 2, 3]

    vector<int> a6 = {1, 1, 2, 3, 4, 5};
    vector<int> b6 = {2, 3, 4, 4, 5, 6};
    vector<int> res6 = findUnion(a6, b6);
    cout << "Test Case 6: ";
    printVector(res6); // Output: [1, 2, 3, 4, 5, 6]

    return 0;
}
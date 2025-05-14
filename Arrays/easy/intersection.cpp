#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
      vector<int> intersection(vector<int>& a, vector<int>& b) {
          vector<int>intersection;
          int i=0,j=0;
          while(i<a.size()&&j<b.size())
          {
              if(a[i]==b[j])
              {
                  if(intersection.empty()||intersection.back()!=a[i])
                  {
                      intersection.push_back(a[i]);
                  }
                  i++;
                  j++;
              }
              else if(a[i]<b[j]) i++;
              else j++;
          }
          return intersection;
      }
      vector<int> intersectionWdup(vector<int>& a, vector<int>& b) {
        vector<int>intersection;
        int i=0,j=0;
        while(i<a.size()&&j<b.size())
        {
            if(a[i]==b[j])
            {
                intersection.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]<b[j]) i++;
            else j++;
        }
        return intersection;
    }
  };
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
Solution sol;

    // Test Case 1: intersection
    vector<int> a1 = {1, 2, 2, 3, 4};
    vector<int> b1 = {2, 2, 3, 5};
    vector<int> res1 = sol.intersection(a1, b1);
    cout << "Test Case 1 (intersection): ";
    printVector(res1); // Output: [2, 3]

    // Test Case 2: intersectionWdup
    vector<int> res2 = sol.intersectionWdup(a1, b1);
    cout << "Test Case 2 (intersectionWdup): ";
    printVector(res2); // Output: [2, 2, 3]

    // Test Case 3: intersection
    vector<int> a3 = {1, 2, 3, 4, 5};
    vector<int> b3 = {6, 7, 8, 9, 10};
    vector<int> res3 = sol.intersection(a3, b3);
    cout << "Test Case 3 (intersection): ";
    printVector(res3); // Output: []

    // Test Case 4: intersectionWdup
    vector<int> res4 = sol.intersectionWdup(a3, b3);
    cout << "Test Case 4 (intersectionWdup): ";
    printVector(res4); // Output: []

    // Test Case 5: intersection
    vector<int> a5 = {1, 1, 1, 1, 1};
    vector<int> b5 = {1, 1, 1, 1, 1};
    vector<int> res5 = sol.intersection(a5, b5);
    cout << "Test Case 5 (intersection): ";
    printVector(res5); // Output: [1]

    // Test Case 6: intersectionWdup
    vector<int> res6 = sol.intersectionWdup(a5, b5);
    cout << "Test Case 6 (intersectionWdup): ";
    printVector(res6); // Output: [1, 1, 1, 1, 1]

    return 0;
}
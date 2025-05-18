#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sortColorsInsertion(vector<int>& nums) { //insertion sort 
        
    for (int i=1;i<nums.size();i++)
    {
        int j=i;
        while(j>0 && nums[j-1]>nums[j])
        {
            swap(nums[j-1],nums[j]);
            j--;
        }
    }
}

void sortColorsDutch(vector<int>& nums) {
        
    int low=0, mid=0, high =nums.size()-1;
    while(mid<=high)
    {
        if (nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {2,0,2,1,1,0},
        {2,0,1},
        {0},
        {1,1,0,2,1,0}
    };

    // Expected results
    vector<vector<int>> expected = {
        {0,0,1,1,2,2},
        {0,1,2},
        {0},
        {0,0,1,1,1,2}
    };

    cout << "Testing Insertion Sort Method:\n";
    for(int i = 0; i < testCases.size(); i++) {
        vector<int> test = testCases[i];
        sortColorsInsertion(test);
        cout << "Test " << i+1 << ": " << (test == expected[i] ? "PASSED" : "FAILED") << endl;
    }

    cout << "\nTesting Dutch National Flag Method:\n";
    for(int i = 0; i < testCases.size(); i++) {
        vector<int> test = testCases[i];
        sortColorsDutch(test);
        cout << "Test " << i+1 << ": " << (test == expected[i] ? "PASSED" : "FAILED") << endl;
    }

    return 0;
}
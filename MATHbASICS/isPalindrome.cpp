#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
        bool isPalindrome(int x) {
            string s=to_string(x);
            int left=0;
            int right=size(s)-1;
            while(left<right)
            {
                if (s[left]!=s[right])
                {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
    };
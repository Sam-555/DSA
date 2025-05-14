#include<iostream> 
#include<vector>
#include<cmath>
using namespace std;
bool isArmstrong(int num) {
    // Write your code here
    bool res;
    int count=0;
    int n=num;
    vector<int>digits;
    while(n!=0)
    {
        digits.push_back(n%10);
        n=n/10;
        count++;
    }
    int n2=0;
    for (int i=0;i<count;i++)
    {
        n2+=round(pow(digits[i],count));
    }
    if (n2==num) return true;
    return false;
}
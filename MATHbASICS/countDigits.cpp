#include<iostream>
using namespace std;
int CountDigits(int n) {
    int num=n;
    int count=0;
    while(n!=0)
    {
        n=n/10;
        count++;
    }
    return count;
}
int main()
{
    int res=CountDigits(2446);
    cout<<res;
    return 0;
}
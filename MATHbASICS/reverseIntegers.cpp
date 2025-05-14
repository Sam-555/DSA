#include<iostream>
using namespace std;
int reverseIntegers(int num)
{
    int n=num;
    int revNUm=0;
    while(n!=0)
    {
        int digit;
        digit=n%10;
        revNUm=revNUm*10+digit;
        n=n/10;
    }
    return revNUm;
}
int main()
{
    int res=reverseIntegers(2446);
    cout<<res;
    return 0;
}
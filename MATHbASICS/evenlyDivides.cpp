#include<iostream>
#include<vector>
using namespace std;
int evenlyDivides(int n) {
        vector<int> digit;
        int num=n;
        while(n!=0)
        {
            digit.push_back(n%10);
            cout<<n%10;
            n=n/10;
        }
        int count=0;
        for(int i:digit)
        {
            if(i!=0)
            {
                if (num%i==0)
                {
                    count++;
                }
            }
            
        }
        return count;
}
int main()
{
    int res=evenlyDivides(2446);
    cout<<res;
    return 0;
}
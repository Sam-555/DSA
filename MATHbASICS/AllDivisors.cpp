#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
set<int>allDivisors(int num)
{
    set<int>divisors;
    for (int i=1;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            divisors.insert(i);
            divisors.insert(int(num/i));
        }
    }
    return divisors;
}
vector<int>divisors1(int num){
    vector<int>allDivisors;
    for(int i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            allDivisors.push_back(i);
            if(num/i!=i) allDivisors.push_back(num/i);
        }
        sort(allDivisors.begin(),allDivisors.end());
    }
    return allDivisors;
}
int main()
{
    vector<int>res=divisors1(0);
    for(int i:res)
    {
        cout<<i<<endl;
    }
}
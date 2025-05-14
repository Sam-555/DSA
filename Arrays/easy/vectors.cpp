#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(1);
    auto first=v.begin();
    v.push_back(2);
    auto second=v.begin();
    cout << &(*first)<< " "<<&(*second);
    return 0;
}
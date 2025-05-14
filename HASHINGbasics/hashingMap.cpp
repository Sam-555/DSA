#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    map<int,int>mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]+=1;
    }
    int queries;
    cin>>queries;
    while(queries--)
    {
        int num;
        cin>>num;
        cout<<"number of times "<<num<<" appears "<<mpp[num]<<endl;
    }
    for(auto it:mpp)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }
}
#include<iostream>
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
    int hashh[13]={0};
    for(int i=0;i<n;i++)
    {
        hashh[arr[i]]+=1;
    }
    int queries;
    cin>>queries;
    while(queries--)
    {
        int num;
        cin>>num;
        cout<<"number of times"<<num<<"appears"<<hashh[num]<<endl;
    }
}
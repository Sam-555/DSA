#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //for lowercase only
    string s;
    cin>>s;
    int hashh[26]={0};
    for(int i=0;i<s.size();i++)
    {
        hashh[s[i]-'a']+=1;
    }
    int queries;
    cin>>queries;
    while(queries--)
    {
        char ch;
        cin>>ch;
        cout<<"number of times "<<ch<<"appears "<<hashh[ch-'a']<<endl;
    }
}
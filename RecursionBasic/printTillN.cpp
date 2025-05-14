#include<iostream>
using namespace std;
void printNos(int n) {
    // Your code here
    
    if(n==0) return;
    printNos(n-1);
    cout<<n<<" ";
}
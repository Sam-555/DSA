#include<iostream>
using namespace std;
int sumOfSeries(int n) {
    // code here
    if (n==0) return 0;
    return n*n*n + sumOfSeries(n-1);
}
//Input: n = 7
//Output: 784
//Explanation: 13 + 23 + 33 + 43 + 53 + 63 + 73 = 784
#include<iostream>
#include<vector>
using namespace std;
long long factorial(int n)
    { 
        if (n==1||n==0) return 1;
        return n*factorial(n-1);
    }
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<long long>facts;
        for(int i=1;n>=factorial(i);i++)
        {
            facts.push_back(factorial(i));   
        }
        return facts;
    }
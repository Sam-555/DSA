#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int>divisors1(int num){
    num=abs(num);
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

vector<int> euclidean(int a , int b)
{
    vector<int> hcf;
    int gcd,lcm=0,n1,n2;
    n1=max(a,b);
    n2=min(a,b);
    while(n2!=0)
    {
        n1=n1%n2;
        if(n2>n1) 
        {
            n1=n1+n2;
            n2=n1-n2;
            n1=n1-n2;
        }
    }
    gcd=n1;
    lcm=(a*b)/gcd;
    hcf.push_back(lcm);
    hcf.push_back(gcd);
    return hcf;    
}

vector<int> euclidean2(int a , int b)
{
    vector<int> hcf;
    int gcd,lcm=0,n1,n2;
    while(n2>0 && n1>0)
    {   
        if (n1>n2) n1=n1%n2;
        else n2=n2%n1;
    }
    if (n2==0)gcd=n1;
    else gcd=n2;
    lcm=(a*b)/gcd;
    hcf.push_back(lcm);
    hcf.push_back(gcd);
    return hcf;    
}


vector<int>gcdANDlcm(int a,int b){
    int gcd=0,lcm;
    vector<int>GandL,aFactors,bFactors;
    if (a==0||b==0)
    {
        if(a==0) gcd=b;
        else gcd=a;
    }
    else
    {
        aFactors=divisors1(a);
        bFactors=divisors1(b);
        if(aFactors.size()>bFactors.size()) aFactors.swap(bFactors);
        for(int i=aFactors.size()-1;i>-1;i--)
        {
            for(int j=bFactors.size()-1;j>-1;j--)
            {
                if (aFactors[i]==bFactors[j])
                {
                    gcd=max(gcd,bFactors[j]);
                    break;
                }
            }
        }
    }
    if(gcd!=0){
        lcm=(a*b)/gcd;
        GandL.push_back(lcm);
        GandL.push_back(gcd);
    } 
    return GandL;
}

void printResult(int n1, int n2, vector<int> result) {
    cout << "Euclidean(" << n1 << ", " << n2 << ") -> ";
    cout << "LCM: " << result[0] << ", GCD: " << result[1] << endl;
}
int main()
{
    int testCases[][2] = {
        {3, 7},    // Both numbers are prime
        {5, 10},   // One prime, one composite
        {6, 6},    // Both numbers are the same
        {1, 9},    // One number is 1 (Edge Case)
        {0, 8},    // One number is 0 (Edge Case)//
        {12, 18},  // Composite numbers with a common factor//
        {8, 15},   // Two co-prime numbers (GCD should be 1)
        {101, 103} // Large prime numbers (Performance Test)
    };
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTests; i++) {
        int n1 = testCases[i][0];
        int n2 = testCases[i][1];
        vector<int> result = euclidean(n1, n2);  
        printResult(n1, n2, result); 
    }
    return 0;
}
#include<iostream>
using namespace std;
bool isPrime(int n)
{
    if(n<2) return false;
    else if(n==2) return true;
    else 
    {
        for (int i=2;i<(n/2+1);i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
}
bool better(int num)
{
    if (num<1) return false;
    else{
        int count=0;
        for(int i=1;i*i<=num;i++)
        {
            if(num%i==0)
            {
                count++;
                if(num/i!=i) count++;
            }
        }
        if(count!=2) return false;
        else return true;
    }
}
int main()
{
    int primeNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int nonPrimeNumbers[] = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30,32, 35, 40, 50};
    /*for (int i:primeNumbers)
    {
        cout<<isPrime(i)<<" ";
    }
    cout<<"\n";
    for (int i:nonPrimeNumbers)
    {
        cout<<isPrime(i)<<" ";
    }
    cout<<"\n";
    for (int i:primeNumbers)
    {
        cout<<better(i)<<" ";
    }
    cout<<"\n";*/
    for (int i:nonPrimeNumbers)
    {
        cout<<better(i)<<" ";
    }
    return 0;
    
} 
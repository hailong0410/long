#include <bits/stdc++.h>
using namespace std;
int countOddDigits(int n)
{
    if(n<0)
    {
    n = -n;
    }   
    else if(n==0){
    return 0;
    }

    else
    {
    if(n%2==1){
    return 1+countOddDigits(n/10);
    }
    else
    {
    return countOddDigits(n/10);
    }   
    }
}
int countEvenDigits(int n)
{
    if(n<0)
    {
    n = -n;
    }   
    else if(n==0){
    return 0;
    }

    else
    {
    if(n%2==0){
    return 1+countEvenDigits(n/10);
    }
    else
    {
    return countEvenDigits(n/10);
    }   
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<countOddDigits(n);
    cout<< endl;
    cout<<countEvenDigits(n);
    return 0;
}

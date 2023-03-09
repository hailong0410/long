#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) 
    {
        for(int j=i+1;j<=n;j++)
        {
            if(gcd(a[i],a[j])==1)
            {
                 cout <<a[i]<< " " <<a[j]<<" ";
                 cout<< endl;
                 
            }
        }
    }
}

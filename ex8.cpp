#include<bits/stdc++.h>
using namespace std;
bool check1(int n)
{
    int a=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        a++;
    }
    if(a==2)
    {
        return true;
    }
    else rerturn false;
}
bool checksphenic(int n)
{
    int a=0;
    int b=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            a+=1;
        }
        if(check1(i)==true)
        {
            b+=1;
        }
    }
    if(a==8&&b==3)
    {
        return true;
    }
    else return false;
}
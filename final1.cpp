#include<bits/stdc++.h>
using namespace std;
void prime(int n, int f=2)
{
    if(n<2)
        return ;
    if(n%f==0)
    {  prime(n/f,f);
        cout<< " " << f;
    }
    else
        prime(n,f+1);
}
int main()
{
    int n;
    cin>>n;
    prime(n);
}

//time complexity la 2^n, truong hop dep nhat la n<2, time... la 1, con la se la 2^n

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    float a[100];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int kq=0;
    for(int i=1;i<=n;i++)
    {
        kq+=a[i];
    }
    printf("%0.1f", kq/n);
}
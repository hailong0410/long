#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>n>>m;
    int a[100][100];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int f[1000][1000];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=1e5;

        }
    }
    f[1][1]=a[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(1<=i+1&&i+1<=n&&1<=j&&j<=m)
            {
                if(a[i+1][j]!=-1)
                {
                    f[i+1][j]=min(f[i][j]+a[i+1][j],f[i+1][j]);
                }
            }
            if(1<=i&&i<=n&&1<=j+1&&j+1<=m)
            {
                if(a[i][j+1]!=-1)
                {
                    f[i][j+1]=min(f[i][j]+a[i][j+1],f[i][j+1]);
                }
            }
            if(1<=i+1&&i+1<=n&&1<=j+1&&j+1<=m)
            {
                if(a[i+1][j+1]!=-1)
                {
                    f[i+1][j+1]=min(f[i][j]+a[i+1][j+1],f[i+1][j+1]);
                }
            }
        }
    }
    
    cout<<f[n][m];
}

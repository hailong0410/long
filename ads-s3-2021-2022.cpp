#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>> n;
    int a[100];
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(a[i]==a[j]*a[k])
                {
                    cout<<a[i]<< " " <<a[j]<<" "<<a[k]<< " ";
                    cout<< endl;
                }
            }
        }
   }
}

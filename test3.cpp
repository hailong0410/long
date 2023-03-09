#include<bits/stdc++.h>
using namespace std;
void insertionsort(int a[], int n)
{
    int j, key, i;
    for( i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j]=a[j+1];
            j=j-1;
        }
        a[j+1]=key;
    }
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
        cout<< endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    insertionsort(a,n);
    print(a,n);
    return 0;
}
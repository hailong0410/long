#include <bits/stdc++.h>
using namespace std;
void insertionsort(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int b=a[i];
		j = i - 1;
		stack<int> c;
		while (j >= 0 && a[j] >b)
		{
			c.push(a[j]);
			j = j - 1;
		}
		for(int k=j+2;k<=i;k++)
		{
			a[k]=c.top();
			c.pop();
		}
		a[j + 1] = b;
	}
}
void printarray(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	insertionsort(a, n);
	printarray(a, n);
	return 0;
}

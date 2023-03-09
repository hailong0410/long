
#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void selectionSort(int a[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (a[j] < a[min_idx])
			min_idx = j;
		if(min_idx!=i)
			swap(&a[min_idx], &a[i]);
	}
}
void printArray(int a[], int n)
{
	int i;
	for (i=0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
	selectionSort(a, n);
	printArray(a, n);
	return 0;
}

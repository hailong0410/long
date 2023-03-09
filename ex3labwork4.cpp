#include <bits/stdc++.h>
using namespace std;


int cnt(int n, int u)
{
  for (int i = u+1; i <= n; ++i)
    if (n%i == 0)
      return 1 + cnt(n/i,i);
  if (n == 1)
    return 0;
  return 4;
}

int main()
{
  int n;
  cin >> n;

  if (cnt(n,1) == 3)
    cout << "Yes\n";
  else cout << "No\n";
}
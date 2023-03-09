#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int cnt(int n, int u)
{
  for (int i = u+1; i <= n; ++i)
    if (n%i == 0&&is_prime(i)==true)
      return 1 + cnt(n/i,i);
  if (n == 1)
    return 0;
  return 4;
}
// vi du voi cnt(30,1), 30 chia het cho 2 sau do chay vong for thi 30/2=15
// 15 viet duoc bao so nt, tiep voi(15,2), ko co len (15,3) duoc 5 tiep den la (5,3) duoc 5 la het
// for tu u vi u la so nguyen to truoc do r 
int main()
{
  int n;
  cin >> n;

  if (cnt(n,1) == 3)
    cout << "Yes\n";
  else cout << "No\n";
}
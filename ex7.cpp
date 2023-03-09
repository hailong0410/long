#include<bits/stdc++.h>
using namespace std;
int cal(int n)
{
    int ans=n%10;
    if (n==0) 
        return ans;
    return ans+cal(n/10);
}
int main()
{
    int n;
    cin >>n;
    cout<< cal(n);

}
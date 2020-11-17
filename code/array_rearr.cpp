#include <bits/stdc++.h>
// https://codeforces.com/contest/1445/problem/A
using namespace std;
const int MX = 50;
int n,x;
int a[MX],b[MX];
inline void solve()
{
    cin >> n >> x;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[n-i-1];
    int p=0;
    bool k = true;
    while(k && p < n)
    {
        if(a[p] + b[p] > x)
            k = false;
        p++;
    }
    cout << ((k)? "Yes":"No") << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t-- > 0)
        solve();
    return 0;
}

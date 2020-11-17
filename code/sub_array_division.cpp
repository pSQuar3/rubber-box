#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::memset;
const int MX = 100;
int n,d,m,sm,ct;
//int D[MX+1][MX+1];
int a[MX];
void solve()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> d >> m;
    sm = 0;
    for(int i=0;i<m;i++)
        sm += a[i];
    ct = 0;
    if(sm == d)
        ct++;
    for(int i=m;i<n;i++)
    {
        sm -= a[i-m];
        sm += a[i];
        if(sm == d)
            ct++;
    }
    cout << ct << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t-- > 0)
        solve();
    return 0;
}

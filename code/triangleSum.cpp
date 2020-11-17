#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long int

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::max;
const int MX = 100;
int n,t;
int D[MX+1][MX+1];
int a[MX][MX];

void solve()
{
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            cin >> a[i][j];
    for(int i=0;i<=n;i++)
    {
        D[i][0] = 0;
        D[0][i] = 0;
        D[i][i+1] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            D[i][j] = a[i-1][j-1] + max(D[i-1][j-1],D[i-1][j]);
        }
    }
    int mx = -1;
    for(int i=1;i<=n;i++)
        mx = max(mx,D[n][i]);
    cout << mx << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t-- > 0)
        solve();
    return 0;
}

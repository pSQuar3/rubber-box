#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int INF = 10000;
const int MX = 100000;
const int MOD = 1000000009;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    while(t--)
    {
        int n,m,r,c;
        cin >> n >> m >> r >> c;
        c = max(c-1,m-c);
        r = max(r-1,n-r);
        cout << (r + c) << "\n";
    }
    return 0;
}

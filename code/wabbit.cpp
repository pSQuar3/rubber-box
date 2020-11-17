#include <bits/stdc++.h>

#define lli long long
#define ull unsigned long long int

using std::cin;
using std::cout;
using std::endl;
using std::abs;
//int D[MX+1][MX+1];
//int D[MX+1];
//int a[MX];

inline void solve()
{
    lli x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 || y1 == y2)
        cout << (abs(x1 - x2) + abs(y1 - y2)) << endl;
    else
        cout << (abs(x1-x2) + abs(y1-y2) + 2) << endl;
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

//https://codeforces.com/problemset/problem/1519/A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);int t;
    cin >> t;
    long long int r,b,d,mx,mn;
    while(t--)
    {
        cin >> r >> b >> d;
        mx = max(r,b);
        mn = min(r,b);
        if(mx > mn*(d + 1))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

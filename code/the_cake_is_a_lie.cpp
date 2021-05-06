//https://codeforces.com/problemset/problem/1519/B
#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    int n,m,k;
    while(t--)
    {
        cin >> n >> m >> k;
        if(n*m-1 == k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

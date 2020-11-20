#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long int

using namespace std;
int n;
vector<int> buildSieve()
{
    vector<int> sieve;
    sieve.resize(n+1);
    for(int i=0;i<=n;i++)
        sieve[i] = 0;
    for(int i = 2; i <= n;i++)
    {
        if(sieve[i])
            continue;
        for(int j = 2*i;j <= n;j += i)
            sieve[j] = i;
    }
    return sieve;
}
inline void solve()
{
    cin >> n;
    vector<int> sieve = buildSieve();
    for(int i=0;i<(int)sieve.size();i++)
        cout << i << " -> " << sieve[i] << "\n";
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

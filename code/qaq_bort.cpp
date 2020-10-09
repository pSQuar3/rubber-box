#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long
#define MX 100000

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
int n;
int D[101][101];
string s;
int solve(int l,int r)
{
    //  code does not work
    if(D[l][r] > 0)
        return D[l][r];
    if(l >= r)
        return 0;
    while(l < n && s[l] != 'Q')
        l++;
    while(r > 0 && s[r] != 'Q')
        r--;
    int f=0;
    for(int i=l;i<=r;i++)
    {
        if(s[i] == 'A')
            f++;
    }
    D[l][r] = f + solve(l,r);
    return D[l][r];
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = (int)s.size();
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            D[i][j] = 0;
    cout << solve(0,n-1) << endl;
    return 0;
}

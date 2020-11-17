#include <bits/stdc++.h>
#define lli long int
using std::cin;
using std::cout;
using std::endl;
const int LMX = -1;
const int LMN = 1000000001;
const int MX = 300000;
int n;
//int D[MX+1][MX+1];
//int D[MX+1];
lli a[MX];
lli poles[MX];
inline void solve()
{
    cin >> n;
    int indx = -1;
    lli mx = LMX,mn = LMN;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] >= mx)
            mx = a[i];
        if(a[i] < mn)
            mn = a[i];
    }
    poles[0] = 0;
    if(a[0] > a[1])
        poles[0] = 1;
    poles[n-1] = 0;
    if(a[n-1] > a[n-2])
        poles[n-1] = 1;
    for(int i=1;i<n-1;i++)
    {
        poles[i] = 0;
        if(a[i-1] < a[i] || a[i] > a[i+1])
            poles[i] = 1;
    }
    for(int i=0;indx == -1 && i < n;i++)
    {
        if(a[i] == mx && poles[i] == 1)
            indx = i+1;
    }
    cout << indx << "\n";
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

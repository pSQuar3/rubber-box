#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int MX = 100000;
int a[MX];
void solve()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int lth[n+1];
    lth[0] = 1;
    int mx = -1;
    int r=0;
    for(int i=1;i<n;i++)
    {
        lth[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(a[j] < a[i])
                lth[i] = max(lth[i],lth[j]+1);
        }
        mx = max(mx,lth[i]);
        if(mx == lth[i])
            r = i;
    }
    cout << mx << "\n";
    stack<int> s;
    while(r >= 0)
    {
        if(lth[r] == mx)
        {
            s.push(a[r]);
            mx--;
        }
        r--;
    }
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

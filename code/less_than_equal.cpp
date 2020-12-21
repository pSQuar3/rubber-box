#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int MX = 100000;
int a[MX];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    //cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        if(k == 0)
            cout << 0 << "\n";
        else if(a[k-1] == a[k])
            cout << -1 << "\n";
        else
            cout << a[k-1] << "\n";
    }
    return 0;
}

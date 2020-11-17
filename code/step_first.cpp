#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::max;
const int MX = 100000;
int n;
long a[MX];
void solve()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    long mx = 1;
    long prev,curr;
    for(int l=1;l<=n-1;l++) 
    {
        prev = 1;
        for(int r=l+1;r<=n;r++)
        {
            if(a[r-1] >= a[r-2])
            {
                curr = prev + 1;
                if(curr > mx)
                    mx = curr;
            }
            else
                curr = 1;
            prev = curr;
        }
    }
    cout << mx << endl;
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

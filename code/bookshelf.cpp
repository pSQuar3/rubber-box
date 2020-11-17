#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;
int n;
//int D[MX+1][MX+1];
//int D[MX+1];
//int a[MX];
bitset<1> a[50];
inline void solve()
{
    cin >> n;
    int c1=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] == 1)
            c1++;
    }
    int frnt=0,bck=0;
    for(int i=0;a[i] == 0;i++)
        frnt++;
    for(int i=n-1;a[i] == 0;i--)
        bck++;
    cout << (n-frnt-bck-c1) << "\n";
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

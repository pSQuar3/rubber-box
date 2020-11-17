#include <bits/stdc++.h>
// wrong solutiointo the problem
#define lli long long int
#define ull unsigned long long int

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::min;
using std::string;
using std::memset;
const int MX = 100000;
string s;
void solve()
{
    cin >> s;
    int n = (int)s.size();
    int a[26];
    memset(a,0,sizeof(a));
    int mn = n;
    cerr << "mn = " << mn << endl;
    for(int i=0;i<n;i++)
        a[s[i] - 'a']++;
    for(int i=0;i<26;i++)
    {
        cerr << "a["<<(char)(i+97)<<"] = " << a[i] << endl;
        if(a[i] > 0)
            mn = min(mn,a[i]);
    }
    int red = 0;
    cerr << "mn = " << mn << endl;
    for(int i=0;i<26 && red < 2;i++)
    {
        if(a[i] > mn)
            red++;
    }
    if(red <= 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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

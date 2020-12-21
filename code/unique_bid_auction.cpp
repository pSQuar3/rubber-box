#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int MX = 200000;
int a[MX];
inline int find_min(vector<int> &k)
{
    int m=INT_MAX;
    for(int i=0;i<(int)k.size();i++)
    {
        if(k[i] < m)
            m = k[i];
    }
    return m;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[a[i]]++;
        vector<int> k;
        for(auto i=mp.begin();i != mp.end();i++)
        {
            if(i->second == 1)
                k.push_back(i->first);
        }
        int i, x = find_min(k);
        for(i=0;i<n;i++)
        {
            if(a[i] == x)
                break;
        }
        if(k.size() == 0 || i == n)
            cout << -1 << "\n";
        else
            cout << i+1 << "\n";
    }
    return 0;
}

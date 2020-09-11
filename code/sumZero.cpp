// problem statement: zero sum subarray problem
#include <bits/stdc++.h>
#define sp2(a,b), cout << a << " " << b << endl;
#define sp1(k), cout << k << endl;
using std::cin;
using std::cout;
using std::vector;
using std::ios_base;
using std::unordered_map;
using std::queue;
using std::pair;
using std::endl;

void solve()
{
    int n,current=0;
    cin >> n;
    int a[n];
    unordered_map<int, vector<int>>sm;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        current += a[i];
        sm[current].push_back(i);
    }
    for(auto i = sm.begin();i!=sm.end();i++)
    {
        if(sm[i->first].size() == 2)
        {
            int i1 = sm[i->first][0];
            int i2 = sm[i->first][1];
            for(int k=i1+1;k<=i2;k++)
                cout << a[k] << " ";
            cout << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

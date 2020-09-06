#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::ios;
using std::vector;
using std::endl;
using std::unordered_map;
unordered_map<int, vector<int>> g;
unordered_map<int, bool> che;
int n,m;
bool checkEdges(int i)
{
    che[i] = true;
    bool b = true;
    for(auto p = g[i].begin();b && p!= g[i].end();p++)
    {
        if(che[*p] == true)
            b = false;
        else
            b = checkEdges(*p);
    }
    che.erase(i);
    return b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    int r,s;
    for(int i=0;i<m;i++)
    {
        cin >> r >> s;
        g[r].push_back(s);
    }
    bool b = true;
    for(int i=0;b && i<n;i++)
        b = checkEdges(i);
    cout << !b << endl;
    return 0;
}

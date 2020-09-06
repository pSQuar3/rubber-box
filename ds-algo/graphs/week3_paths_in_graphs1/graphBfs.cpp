#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;
using std::ios;
using std::unordered_map;
using std::endl;
unordered_map<int, vector<int>> gph;
int n,m;
unordered_map<int,bool> vst;
int bfsLevelSearch(int i,int s,int nCall)
{
    int v = -1;
    vst[i] = true;
    //cout << "find block, node = " << i << endl;
    for(auto k = gph[i].begin();v == -1 && k!=gph[i].end();k++)
    {
        if(*k == s && vst[*k] != true)
            v = nCall;
    }
    if(v == -1 && !gph[i].empty())
    {
        for(auto k=gph[i].begin();v == -1 && k!=gph[i].end();k++)
            if(vst[*k] != true)
                v = bfsLevelSearch(*k,s,nCall+1);
    }
    return v;
}
void solve()
{
    int x,y;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        gph[i] = {};
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }
    //cout << "accepted" << endl;
    if(n != 0 && m != 0)
    {
        cin >> x >> y;
        cout << bfsLevelSearch(x,y,1) << endl;
    }
    else
        cout << -1 << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

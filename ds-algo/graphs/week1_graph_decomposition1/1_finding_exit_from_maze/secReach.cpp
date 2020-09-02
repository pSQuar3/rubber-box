#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::ios;
using std::unordered_map;
using std::vector;
using std::pair;
using std::endl;
int n,m,x,y,c=1;
unordered_map<int, vector<int>> g;
unordered_map<int, bool> rch;
void check(int current)
{
    rch[current] = true;
    cout << current << " ";
    for(auto i=g[current].begin();i!=g[current].end();i++)
    {
        if(rch[*i] == false && *i != x)
            return check(*i);
    }
}
bool checkGr(int current)
{
    //cout << "node = " << current<< endl;
    rch[current] = true;
    //cout << current << " ";
    bool b = false;
    if(current == y)
        b = true;
    for(auto i=g[current].begin();!b && i!=g[current].end();i++)
    {
        if(rch[*i] == false)
            b = b + checkGr(*i);
    }
    return b;
}
void solve()
{
    std::cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        g[i] = {};
        rch[i] = false;
    }
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> x >> y;
    //cout << "direct connections to the node to be searched:" << endl;
    //for(auto i=g[x].begin();i!=g[x].end();i++)
    //    cout << *i << endl;
    //cout << "displayed accessible elements of graph from x:" << endl;
    //check(x);
    //cout << "\nis accessible?" << endl;
    cout << checkGr(x); 
}
int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

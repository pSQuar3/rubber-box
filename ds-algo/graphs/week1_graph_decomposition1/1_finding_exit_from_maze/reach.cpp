#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;
using std::ios;
using std::endl;
int n,m,x,y;
unordered_map<int, vector<int>> g;
unordered_map<int, bool> rch;
void check(int current)
{
    //cout << "node = " << current<< endl;
    rch[current] = true;
    cout << current << " ";
    //if(current == y)
    //   return true;
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
    if(current == y)
        return true;
    for(auto i=g[current].begin();i!=g[current].end();i++)
    {
        if(rch[*i] == false)
            return checkGr(*i);
    }
    return false;
}

bool isConnected(int q)
{
    rch[q] = true;
    bool b = true;
    for(auto i=g[q].begin();i!=g[q].end();i++)
    {
        //cout << "*i = " << endl;
        if(*i == y)
            return true;
        if(rch[*i] == false)
            return isConnected(*i);
    }
    return false;
}
void solve()
{
    std::cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        rch[x] = false;
        rch[y] = false;
        g[y].push_back(x);
    }
    cin >> x >> y;
    cout << "displayed accessible elements of graph from x:" << endl;
    check(x);
    cout << "\nis accessible?" << endl;
    cout << checkGr(x);
}
int main()
{
    std::ios::sync_with_stdio(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
#define sp2(a,b), cout << a << " " << b << endl;
#define sp1(k), cout << k << endl;
using std::cin;
using std::cout;
using std::vector;
using std::ios;
using std::unordered_map;
using std::stack;
using std::endl;
stack<int> order;
unordered_map<int,vector<int>> g;
int n,m;
unordered_map<int,bool> checked;
void toposort(int i)
{
    checked[i] = true;
    for(auto p=g[i].begin();p != g[i].end();p++)
    {
        if(!checked[*p])
            toposort(*p);
    }
    order.push(i);
}
void solve()
{
    cin >> n >> m;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(!checked[i])
            toposort(i);
    }
    while(!order.empty())
    {
        cout << order.top() << " ";
        order.pop();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> graph;
vector<int> v;
void stackDFS(int d, stack<int> &s)
{
    v[d] = 1;
    for(int i=0;i < (int)graph[d].size();i++)
    {
        if(!v[graph[d][i]])
            stackDFS(graph[d][i],s);
    }
    s.push(d);
}
stack<int> toposort()
{
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(!v[i])
            stackDFS(i,s);
    }
    return s;
}
void solve()
{
    cin >> n >> m;
    graph.resize(n);
    v.resize(n,0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        graph[x-1].push_back(y-1);
    }
    stack<int> s = toposort();
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}

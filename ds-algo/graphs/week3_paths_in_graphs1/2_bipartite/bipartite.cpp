#include <bits/stdc++.h>
using std::vector;
using std::queue;
using std::cin;
using std::cout;
using std::endl;
int n,m;

void bipartite(vector<vector<int> > &adj)
{
    //write your code here
    int x,y,u;
    cin >> x >> y;
    vector<int> dist,prev;
    for(int i=0;i<n;i++)
    {
        dist[i] = -1;
        prev[i] = -1;
    }
    dist[x-1] = 0;
    queue<int> qu;
    qu.push(x-1);
    bool b = false;
    while(!qu.empty())
    {
        u = qu.front();
        qu.pop();
        //cout << "discovered edge = " << u << endl;
        for(auto r = adj[u].begin();!b && r!=adj[u].end();r++)
        {
            if(dist[*r] == -1)
            {
                qu.push(*r);
                dist[*r] = dist[u]+1;
                prev[*r] = u;
            }
            if(*r == y-1)
                b = true;
        }
    }
}
vector<int> Reconstruct(int S, int u, vector<int> &prev)
{
    vector<int>  res;
    while(u != S)
    {
        res.push_back(u);
        u = prev[u];
    }
    return res;
}
int main()
{
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    bipartite(adj);
    vector<int>
    return 0;
}

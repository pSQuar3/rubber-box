#include <bits/stdc++.h>
using std::vector;
int n,m;

bool negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost)
{
    long long int dist[n];
    for(int i=0;i<n;i++)
        dist[i] = INT_MAX;
    dist[0] = 0;
    bool ceck = false;
    for(int v = 0;v < n-1;v++)
    {
        ceck = false;
        for(size_t i = 0;i < (long unsigned int)adj.size();i++)
        {
            for(size_t j = 0;j < (long unsigned int)adj[i].size();j++)
            {
                if(dist[adj[i][j]] > dist[i] + cost[i][j])
                {
                    dist[adj[i][j]] = dist[i] + cost[i][j];
                    ceck = true;
                }
            }
        }
    }
    return ceck;
}

int main()
{
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> cost(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cout << negative_cycle(adj, cost);
}

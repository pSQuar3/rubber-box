#include <bits/stdc++.h>
using std::vector;
int n,m;

int negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost)
{
    //write your code here
    int dist[n];
    int x;
    std::cin >> x;
    for(int i=0;i<n;i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    /*for(int e=0;e<n;e++)
    {*/
    for(int v = 0;v < n-1;v++)
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j < (int)adj[i].size();i++)
            {
                //  i -> value of the node
                std::cout << "i = " << i << " node = " << adj[i][j] << std::endl;
                if(dist[adj[i][j]] > dist[i] + cost[i][j])
                {
                    dist[adj[i][j]] = dist[i] + cost[i][j];
                }
            }
        }
    //}
    std::cout << "distance = " << dist[x] << std::endl;
    return 0;
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

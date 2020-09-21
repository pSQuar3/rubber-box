#include <bits/stdc++.h>

using namespace std; 
int V,E;
int graph[10000][3];
int BellmanFord(int src) 
{ 
    int dis[V]; 
    for (int i = 0; i < V; i++) 
        dis[i] = INT_MAX; 
    dis[src] = 0; 
    for (int i = 0; i < V - 1; i++)
    { 
        for (int j = 0; j < E; j++)
        {
            if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]) 
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2]; 
        } 
    } 
    for (int i = 0; i < E; i++)
    {
        int x = graph[i][0]; 
        int y = graph[i][1]; 
        int weight = graph[i][2]; 
        if (dis[x] != INT_MAX && dis[x] + weight < dis[y]) 
            return 1;
    } 
//    cout << "Vertex Distance from Source" << endl; 
//    for (int i = 0; i < V; i++) 
//        cout << i << "\t\t" << dis[i] << endl; 
    return 0;
} 
int main() 
{ 
    std::cin >> V >> E;
    //int graph[E][3];
    for(int i=0;i<E;i++)
    {
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }
    cout << BellmanFord(0) << endl;
    return 0; 
} 

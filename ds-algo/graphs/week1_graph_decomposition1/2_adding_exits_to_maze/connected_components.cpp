#include <bits/stdc++.h>
#include <unordered_map>
using std::cin;
using std::cout;
using std::unordered_map;
using std::vector;
using std::pair;
using std::endl;
unordered_map<int, vector<int> > adj;
unordered_map<int,int> grouper;
int fC=0;
void numcomp(int current)
{
    grouper[current] = fC;
    for(auto i=adj[current].begin();i!=adj[current].end();i++)
    {
        if(grouper[*i] == -1)
            numcomp(*i);
    }
}
int main()
{
    int n, m;
    std::ios::sync_with_stdio(0);
    std::cin >> n >> m;
    for(int i=0;i<n;i++)
        grouper[i] = -1;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    for(int i=0;i<n;i++)
    {
        if(grouper[i] == -1)
        {
            numcomp(i);
            fC++;
        }
    }
    std::cout << fC << endl;
    return 0;
}

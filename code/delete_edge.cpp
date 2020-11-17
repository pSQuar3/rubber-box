#include <bits/stdc++.h>
/*  
 *  Problem Statement: Given a tree with n nodes and m undirected edges, each node having a weight associated with it.
 *  Delete 1 edge in the tree, such the difference between the weights of the 2 subtrees formed will be minimised.
 *
 *  INPUTS: first line contains n(1 <= n <= 10^5) and m(1 <= m <= n(n-1)/2)
 *          next n lines contain weights of the nodes. The i-th line contains weight of node i (1 <= i <= n)
 *          next m lines contain 2 integers x and y on each line, denoting an edge between nodes x and y (1 <= x,y <= n)
 *          
 *  OUTPUT: Print the nodes that the edge connects and the value of the sum of the 2 subtrees
 *
 *  (Uber '20)
 */
using namespace std;
vector<vector<int>> tree;
vector<int> sums;
vector<int> v;
vector<int> weights;
int m,n;
int s=0,m1=INT_MAX,n1=-1,n2=-1;
int DFS(int node)
{
    v[node] = 1;
    sums[node] = weights[node];
    for(int i=0;i<(int)tree[node].size();i++)
    {
        if(!v[tree[node][i]])
            sums[node] += DFS(tree[node][i]);
    }
    return sums[node];
}
void checkDFS(int d)
{
    v[d] = 1;
    for(int i=0;i<(int)tree[d].size();i++)
    {
        if(!v[tree[d][i]])
        {
            if(s-sums[tree[d][i]] < m1)
            {
                m1 = s-sums[tree[d][i]];
                n1 = d;
                n2 = tree[d][i];
            }
            checkDFS(tree[d][i]);
        }
    }
}
void solve()
{
    cin >> n >> m;
    tree.resize(n);
    weights.resize(n);
    sums.resize(n,0);
    v.resize(n,0);
    for(int i=0;i<n;i++)
        cin >> weights[i];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        tree[x-1].push_back(y-1);
        tree[y-1].push_back(x-1);
    }
    s = DFS(0);
    for(int i=0;i<n;i++)
        v[i] = 0;
    checkDFS(0);
    cout << "Nodes: " << n1 << ", " << n2 << "\nweight of sub-trees = " << m1 << ", " << (s-m1) << "\n";
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

#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long int

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::floor;
using std::ceil;
using std::vector;
using std::unordered_map;
using std::map;
using std::stack;
using std::queue;
using std::max;
using std::min;
using std::deque;
using std::priority_queue;
using std::bitset;
using std::set;
using std::sort;
using std::hash;
using std::pair;
using std::make_pair;
using std::string;
using std::swap;
const int MX = 100000;
int n;
//int D[MX+1][MX+1];
//int D[MX+1];
//int a[MX];
int E,V;
vector<vector<int>> node;
vector<vector<int>> cost;
vector<pair<int,int>> dist;
int town,college,S;
inline void accept()
{
    cin >> V >> E;
    node.resize(V);
    cost.resize(V);
    dist.resize(V);
    for(int i=0;i<V;i++)
        dist[i] = make_pair(INT_MAX,0);
    int x,y,z;
    for(int i=0;i<E;i++)
    {
        cin >> x >> y >> z;
        node[x-1].push_back(y-1);
        cost[x-1].push_back(z);
    }
    cin >> town >> college >> S;
    town--;
    college--;
}
void dijkstra()
{
    dist[town] = make_pair(0,town);
    auto cmp = [](pair<int,int> left, pair<int,int> right)
    {
        return(left.first > right.first || left.first == right.first);
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> mh(cmp);
    mh.push(make_pair(0,town));
    int i = 1;
    // first in heap contains the distance and second contains the node
    while(!mh.empty())
    {
        mh.pop();
        int s = mh.top().first, e = mh.top().second;
        for(int k=0; k < (int)node[e].size(); k++)
        {
            int d = cost[e][i] + dist[e].first;
            if(dist[node[e][i]].first > d)
            {
                dist[node[e][i]] = make_pair(d,i);
                mh.push(make_pair(dist[node[e][i]].first,node[e][i]));
            }
        }
    }
}

inline void solve()
{
    accept();
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t-- > 0)
        solve();
    return 0;
}

#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long int
#define MX 100000
#define M 10000000000000000
using std::cin;
using std::cout;
using std::cerr;
using std::floor;
using std::ceil;
using std::vector;
using std::unordered_map;
using std::map;
using std::endl;
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
using std::hash;
int n,m;
vector<vector<int>> graph;
vector<vector<ull>> cost;

void calculate(int startnode)
{
    auto cmp = [](pair<ull,int> left, pair<ull,int> right)
    {
        return(left.first < right.first || left.first == right.first);
    };
    priority_queue<pair<ull,int>, vector<pair<ull,int>>, decltype(cmp)> min_heap(cmp);
    min_heap.push(make_pair(M,startnode));
    ull dist[n];
    bool c[n];
    for(int i=0;i<n;i++)
    {
        dist[i] = M;
        c[i] = true;
    }
    dist[startnode] = 0;
    int nd;
    ull dst;
    while(!min_heap.empty())
    {
        nd = min_heap.top().second;
        min_heap.pop();
        //d = min_heap.top().first;
        for(int i = 0;c[nd] && i < (int)graph[nd].size(); i++)
        {
            dst = dist[nd] + cost[nd][i];
            if(dst < dist[graph[nd][i]])
            {
                dist[graph[nd][i]] = dst;
                min_heap.push(make_pair(dst,graph[nd][i]));
            }
        }
        //if destination node is  given as variable end_node, uncomment following for a faster implementation:
        //if(nd == end_node)
        //    break;
        c[nd] = false;
    }
    for(int i=0;i < n;i++)
        cout << dist[i] << " ";
    cout << endl;
}
/*
6 7
0 1 3
0 3 1
1 2 7
1 4 1
3 4 9
5 2 9
4 5 1
0 5
*/
void acceptGraph()
{
    cin >> n >> m;
    graph.resize(n);
    cost.resize(n);
    int fr,to;
    ull dst;
    for(int i=0;i<m;i++)
    {
        cin >> fr >> to >> dst;
        graph[fr].push_back(to);
        cost[fr].push_back(dst);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    acceptGraph();
    int s;
    cin >> s;
    calculate(s);
    return 0;
}

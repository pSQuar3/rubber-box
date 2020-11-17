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
const int MX = 300000;
vector<vector<int>> graph;
int n;
int a[MX];
inline int checkOut()
{
    int c = 0;
    for(int i=0;i<n;i++)
    {
        if(graph[i].size() == 0)
            c++;
    }
    return c;
}
void dfs(int i)
{

}
inline void solve()
{
    cin >> n;
    graph.resize(n);
    char c;
    for(int i=0;i < n;i++)
    {
        cin >> c;
        if(c == '>')
            graph[i].push_back((i+1)%n);
        else if(c == '<')
            graph[(i+1)%n].push_back(i);
        else
        {
            graph[i].push_back((i+1)%n);
            graph[(i+1)%n].push_back(i);
        }
    }
    cout << (n - checkOut()) << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t-- > 0)
        solve();
    return 0;
}

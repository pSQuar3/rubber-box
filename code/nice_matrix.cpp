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
const int MX = 100;
int n,m;
int a[MX][MX];
//int D[MX];
//int a[MX];

inline void solve()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    
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

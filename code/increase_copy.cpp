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
long int n,x;
//int D[MX+1][MX+1];
//int D[MX+1];
//int a[MX];

//void  

inline void solve()
{
    cin >> n;
    int ct = 0;
    while(n > 0)
    {
        x = n/2;
        if(n%2 == 0)
            ct += 1;
        else
            ct += 2;
        n = x;
    }
    cout << ct << "\n";
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

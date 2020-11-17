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
//int D[MX+1][MX+1];
//int D[MX+1];
//int a[MX];
inline lli fast_power(int x, int y)
{
    if(y <= 1)
        return x;
    lli k = fast_power(x,y/2);
//    cerr << n/2 << " " << k << endl;
    k = k*k;
    if(y%2 == 1)
        k = k*x;
    return k;
}

inline void solve()
{
    int n,a;
    cin >> a >> n;
    lli k = fast_power(a,n);
    cout << k << endl;
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

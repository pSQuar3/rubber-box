#include <bits/stdc++.h>

#define lli long int
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
const int MX = 31;
int n;
//int D[MX+1][MX+1];
//int D[MX+1];
//int a[MX];
lli x,y;
inline void solve()
{
    cin >> x >> y;
    bitset<MX> a(x);
    bitset<MX> b(y);
    for(int i=0;i <= 30;i++)
    {
        if(a[i] == 1 && b[i] == 1)
        {
            a[i] = 0;
            b[i] = 0;
        }
    }
    lli k = a.to_ulong() + b.to_ulong();
    cout << k << endl;
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

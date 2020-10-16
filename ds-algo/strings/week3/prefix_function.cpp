#include <bits/stdc++.h>
// time complexity = O(n)
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
int s[MX];//contains the prefix function
string p;
void solve()
{
    cin >> p;
    s[0] = 0;
    int border = 0;
    n = (int)p.size();
    //  linear time, not quadratic
    for(int i=1;i<=n-1;i++)
    {
        while(border > 0 && p[i] != p[border])
            border = s[border-1];
        if(p[i] == p[border])
            border++;
        else
            border = 0;
        s[i] = border;
    }
    for(int i=0;i<n;i++)
        cout << s[i] << " ";
    cout << endl;
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

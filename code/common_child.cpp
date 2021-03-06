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
const int MX = 5000;
int n;
int D[MX+1][MX+1];
//int D[MX+1];
//int a[MX];
string a,b;
inline void solve()
{
    cin >> a >> b;
    int x = (int)a.size(), y = (int)b.size();
    for(int i=0;i<=x;i++)
        D[0][i] = 0;
    for(int j=0;j<=y;j++)
        D[j][0] = 0;
    int mx = 0,col_max=0,w=0;
    for(int i=1;i<=x;i++)
    {
        mx = 0;
        for(int j=1;j<=y;j++)
        {
            D[i][j] = 0;
            if(a[i-1] == b[j-1] && j > w)
                D[i][j] = col_max + 1;
            mx = max(mx,D[i][j]);
            if(D[i][j] > mx)
            {
                mx = D[i][j];
                w = j;
            }
        }
        col_max = mx;
    }
    cout << mx << endl;
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

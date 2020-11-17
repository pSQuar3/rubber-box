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
using std::abs;
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
const int MX = 500;
int n,r;
struct Celebrity
{
    int time, x,y;
    Celebrity(int t,int r1, int r2)
    {
        time = t;
        x = r1;
        y = r2;
    }
};
Celebrity *a[100000];
inline int dist(int x1,int x2,int y1, int y2)
{
    return (abs(x1-x2) + abs(y1-y2));
}
inline int D(int p, int q)
{
    return dist(p,1,q,1);
}
inline void accept()
{
    cin >> r >> n;
    int t,p,q,c=0;
    for(int i=0;i<n;i++)
    {
        // if the time taken by me to reach the celeb is less than the shortest distance
        // then add to the list;
        // else break
        cin >> t >> p >> p;
        if(D(p,q) <= t)
        {
            Celebrity *g = new Celebrity(t,p,q);
            a[c++] = g;
        }
    }
}

inline void solve()
{
    accept();
    /*
     *  
     * 
     *
     */
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

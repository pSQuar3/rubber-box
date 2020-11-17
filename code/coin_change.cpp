#include <bits/stdc++.h>
/*
 * maximum number of ways:
 * 8 3 1 2
 * 1: {1}
 * 2: {1 1} {2}
 * 3: {1 1 1} {1 2} {3}
 * 4: {1 1 1 1} {1 1 2} {2 2} {3 1}
 * 5: {1 1 1 1 1} {1 1 1 2} {1 2 2} {2 3} {3 1 1}
 * 6: {1 1 1 1 1 1} {1 1 1 1 2} {1 1 2 2} {2 2 2} {3 3} {1 1 1 3} {1 2 3} 
 */
#define lli long long int
#define ull unsigned long long
#define MX 100000

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
long D[251];
int c[50];

void solve()
{
    cin >> n >> m;
    int mn = -1;
    for(int i=0; i<m;i++)
    {
        cin >> c[i];
        mn = min(mn,c[i]);
    }
    for(int i=mn;i<=n;i++)
        D[i] = 0;
    for(int i=0;i<mn;i++)
        D[i] = 0;
    for(int i=1;i<=n;i++)
    {
        int mx = 0;
        for(int j=0;j<m;j++)
        {
            if(i >= c[j])
                mx = max(mx,c[j]);
//            if(i == c[j])
//                mx++;;
        }
        D[i] = D[mx]+1;
        cerr << "D[" << i << "] = " << D[i] << endl;
    }
    cout << D[n] << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

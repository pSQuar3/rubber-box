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
const int MX = 1000000;
int n;
//int D[MX+1][MX+1];
int D[MX+1];

void solve()
{
    cin >> n;
    int x,y,z;
    for(int i=0;i<n;i++)
        D[i] = INT_MAX;
    D[0] = 0;
    D[1] = 0;
    for(int i=2;i<=n;i++)
    {
        x=INT_MAX,y=INT_MAX,z=D[i-1];
        if(i%2 == 0)
            x = D[i/2];
        if(i%3 == 0)
            y = D[i/3];
        D[i] = min(x,min(y,z)) + 1;
    }
    cout << D[n] << endl;
    int i = n;
    stack<int> opt;
    while(i > 0)
    {
        opt.push(i);
        x=INT_MAX,y=INT_MAX,z=D[i-1];
        if(i%2 == 0)
            x = D[i/2];
        if(i%3 == 0)
            y = D[i/3];
        int h = min(x,min(y,z));
        if(h == x)
            i = i/2;
        else if(h == y)
            i = i/3;
        else
            i = i-1;
    }
    while(!opt.empty())
    {
        cout << opt.top() << " ";
        opt.pop();
    }
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

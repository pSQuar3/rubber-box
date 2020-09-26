#include <bits/stdc++.h>

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
int n,k;
char s[100];
char t[2];
void solve()
{
    int D[n+1][k+1];
    bool found_first=false,found_second=false;
    for(int i=0;i<=k;i++)
        D[0][i] = 0;
    int crval=0;
    for(int i=0;i<=n;i++)
    {
        //relevant index of search is from 1 to i;
        if(i > 1)//1 = t.size
        {
            if(s[i-1] == t[1] && s[i-2] == t[0])
            {
                D[i][0] = crval;
                crval++;
            }
        }
        else
            D[i][0] = crval;
        if(s[i-1] == t[0])
            found_first = true;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> s[i];
    cin >> t[0];
    cin >> t[1];
    solve();
    return 0;
}

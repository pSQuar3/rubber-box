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


int commonLength(string a, string b)
{
    int n = (int)a.size();
    int m = (int)b.size();
    int L[n+1][m+1];
    int r = -1;
    L[0][0] = 0;
    for(int i=0;i<=m;i++)
        L[0][i] = 0;
    for(int i=0;i<=n;i++)
        L[i][0] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1] == b[j-1])
            {
                L[i][j] = L[i-1][j-1] + 1;
                r = max(r,L[i][j]);
            }
            else
                L[i][j] = 0;
        }
    }
    return r;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1,s2;
    cin >> s1;
    cin >> s2;
    cout << commonLength(s1,s2) << endl;
    return 0;
}

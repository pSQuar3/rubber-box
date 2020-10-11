#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long
#define MX 1000

using std::cin;
using std::cout;
using std::cerr;
//using std::floor;
//using std::ceil;
//using std::vector;
//using std::unordered_map;
//using std::map;
using std::endl;
using std::stack;
//using std::queue;
using std::max;
//using std::min;
//using std::deque;
//using std::priority_queue;
//using std::bitset;
//using std::set;
//using std::sort;
//using std::hash;
using std::pair;
using std::make_pair;
//using std::string;
//using std::swap;
//using std::hash;
int n,m;
int D[MX+2][MX+2];
int a[MX][MX];

void solve()
{
    int mx = -1,cns_i=0,cns_j=0;
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            D[i][j]= max(D[i-1][j-1],max(D[i+1][j-1],D[i][j-1])) + a[i-1][j-1];
            if(D[i][j] > mx)
            {
                mx = D[i][j];
                cns_i = i;
                cns_j = j;
            }
        }
    }
    cout << mx << endl;
    //correct up to this part
    int t,i = cns_i;
    stack<pair<int,int>> st;
    while(cns_j > 0)
    {
//        cerr << D[i][cns_j] << " -> (" << i-1 << ", " << cns_j-1 << ")" << endl;
        st.push(make_pair(i-1,cns_j-1));
        t = D[i][cns_j] - a[i-1][cns_j-1];
        if(t == D[i-1][cns_j-1])
            i = i - 1;
        else if(t == D[i+1][cns_j-1])
            i = i + 1;
        cns_j--;
    }
    while(!st.empty())
    {
        cout << "(" << st.top().first << ", " << st.top().second << ")";
        st.pop();
        if(!st.empty())
            cout << " -> ";
    }
}
int main()
{
    /*
     * gold mine problem
     * https://www.geeksforgeeks.org/gold-mine-problem/?ref=lbp
     */
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m;j++)
            D[i][j] = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    solve();
    return 0;
}

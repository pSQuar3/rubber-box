#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int MX = 1000;
int n,m;
bitset<1> graph[MX][MX];
int path[MX];
bool checkValid(int d,int pos)
{
    if(graph[path[pos-1]][d] == 0)
        return false;
    for(int i=0;i<pos;i++)
        if(path[i] == d)
            return false;
    return true;
}
bool hamiltonian(int pos)
{
    if(pos == n)
    {
        if(graph[pos-1][path[0]] == 1)
            return true;
        else
            return false;
    }
    for(int v=1;v<n;v++)
    {
        if(checkValid(v,pos))
        {
            path[pos] = v;
            if(hamiltonian(pos+1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
void printsol()
{
    for(int i=0;i<n;i++)
        cout << path[i] << " ";
    cout << "\n";
}
void find_ham_cycle()
{
    for(int i=0;i<n;i++)
        path[i] = -1;
    path[0] = 0;
    if(hamiltonian(1))
    {
        printsol();
        return;
    }
    cout << "Not available\n";
}
void solve()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j] = 0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1;
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}

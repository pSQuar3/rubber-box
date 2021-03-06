#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
template<typename A,typename B>
inline A fast_power(A x,B y){if(y<=1)return x;A k=fast_power(x,y/2);k=k*k;if(y%2==1)k=k*x;return k;}
template<typename A>
inline int gcd(A a,A b){A t;while((a!=0)&&(b!=0)){t=a%b;a=b;b=t;}return a+b;}
template<typename A,typename B>
inline lli ncr(A x,B r){lli top=1,bot=1;while(r>=1){top*=(x-r+1);bot*=r;r--;} return top/bot;}
template<typename A>
inline pair<A,int> kadane(A x[], int n) {
    A max_so_far = -9999999999999, max_ending_here = 0; int h = 0;
    for(int i=0;i<n;i++) { max_ending_here += x[i];
        if(max_so_far < max_ending_here) { max_so_far = max_ending_here; h = i; }
        if(max_ending_here < 0) max_ending_here = 0;}
    return make_pair(max_so_far,h);
}
struct custom_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    { auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second); return hash1 ^ hash2; }
    template <typename T1>
    size_t operator()(const T1& p) const
    { auto hash1 = hash<T1>{}(p); return hash1;
        /* auto hash2 = hash<T1>{}(p.first); return hash1^hash2; */ }
};
int n,m;
unordered_map<string,int> mp;
vector<vector<int>> graph;
vector<int> dist;
vector<bitset<1>> visit;
vector<vector<int>> transpose;
void topoOrder(int d,stack<int> &s)
{
    visit[d] = 1;
    for(int i=0;i<(int)graph[d].size();i++)
    {
        if(visit[graph[d][i]] == 0)
            topoOrder(graph[d][i],s);
    }
    s.push(d);
}
void traverseDFS(int d,int ind)
{
    visit[d] = 1;
    for(int i=0;i<(int)transpose[d].size();i++)
    {
        if(visit[transpose[d][i]] == 0)
            traverseDFS(transpose[d][i],ind);
    }
}
void solve()
{
    cin >> n >> m;
    string x,y;
    int ind = 0;
    graph.resize(n);
    transpose.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        if(mp.find(x) == mp.end())
            mp[x] = ind++;
        if(mp.find(y) == mp.end())
            mp[y] = ind++;
        graph[mp[x]].push_back(mp[y]);
        transpose[mp[y]].push_back(mp[x]);
    }
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(visit[i] == 0)
            topoOrder(i,s);
    }
    int id = 0;
    vector<vector<int>> scc;
    vector<int> cc;
    for(int i=0;i<n;i++)
        visit[i] = 0;
    while(!s.empty())
    {
        int k = s.top();
        s.pop();
        for(int i=0;i < (int)transpose[k].size();i++)
        {
            if()
        }
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

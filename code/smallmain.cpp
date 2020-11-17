#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
template<typename A,typename B>
inline A fast_power(A x,B y){if(y<=1)return x;A k=fast_power(x,y/2);k=k*k;if(y%2==1)k=k*x;return k;}
template<typename A>
inline int gcd(A a,A b){A t;while((a!=0)&&(b!=0)){t=a%b;a=b;b=t;}return a+b;}
template<typename A>
inline pair<A,int> kadane(A x[], int n) {
    A max_so_far = -9999999999999, max_ending_here = 0; int h = 0;
    for(int i=0;i<n;i++) { max_ending_here += x[i];
        if(max_so_far < max_ending_here) { max_so_far = max_ending_here; h = i; }
        if(max_ending_here < 0) max_ending_here = 0;
    }
    return make_pair(max_so_far,h);
}
struct custom_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    { auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second); return hash1 ^ hash2; }
    template <typename T1>
    size_t operator()(const T1& p) const
    {
        auto hash1 = hash<T1>{}(p);
        //change T1 to class name if mapping object to another quantity
        //similar to hash_pair - map each elements of a class separately
        /*
        auto hash2 = hash<T1>{}(p.first);
         */
        return hash1;
    }
};
template <typename A,typename B>
struct Graph
{
    int n,m; unordered_map<A,int,custom_hash> mp; vector<bool> visit; 
    vector<vector<int>> graph; vector<vector<B>> cost; vector<B> dist;
//    Graph(int x,int b) { n = x; m = b; graph.resize(x); }
    void reset_visit() { visit.resize(n,false); }
    void reset_dist() { dist.resize(n,999999999999); }
    void accept_nodes() { A x; for(int i=0;i<n;i++) { cin >> x; mp[x] = i; } }
    void accept() {A x,y; int nd = 0;// accepts the graph with any data type
        for(int i=0;i<m;i++) {cin >> x >> y; if(mp.find(x) == mp.end()) { mp[x] = nd++; }
            if(mp.find(y) == mp.end()) { mp[y] = nd++; } graph[mp[x]].push_back(mp[y]); }
    }
    void dfs(int d,int fnd) { visit[d] = true;
        for(int i = 0; !visit[fnd] && i < graph[d].size(); i++)
            if(!visit[graph[d][i]]) { dfs(graph[d][i]); }
    }
    int bfs(int start, int fnd) { queue<pair<int,int>> q; q.push(make_pair(start,0));
        while(!q.empty() && q.front().first != fnd) { pair<int,int> p = q.front(); q.pop();
            for(int i=0;i<graph[p.first].size();i++) q.push(make_pair(graph[p.first][i],p.second+1));
        } return q.front().second;
    }
    void transpose(int d, vector<vector<int>> &rev) {
        visit[d] = true;
        for(int i=0;i<graph[d].size();i++)
        {rev[graph[d][i]].push_back(d);if(!visit[graph[d][i]]){transpose(graph[d][i],rev);}}
    }
    void first_dfs(int i,stack<int> &s) {
        visit[i] = true;
        for(int j=0;j<graph[i].size();j++) if(!visit[graph[i][j]]) { first_dfs(graph[i][j],s); }
        s.push(i);
    }
    void second_dfs(int v,int ind,vector<vector<int>> &cc,vector<int> &scc) {
        cc[ind].push_back(v); scc[v] = ind; visit[v] = true;
        for(vector<int>::iterator i = graph[v].begin();i != graph[v].end();i++)
            if(!visit[*i]) second_dfs(*i,ind,cc,scc);
    }
    pair<vector<vector<int>>,vector<int>> kosaraju() {
        stack<int> s; reset_visit(); reset_dist();
        for(int i=0;i<n;i++)
            if(!visit[i])
                first_dfs(i,s);
            reset_visit();vector<vector<int>> rev(n);
        for(int i=0;i<n;i++)
            if(!visit[i])
                transpose(i,rev);
        vector<vector<int>> cc(n); vector<int> scc(n); int v,ind=0;
        while(!s.empty())
        {
            v = s.top();
            s.top();
            if(!visit[v])
            {
                second_dfs(v,ind,cc,scc);
                ind++;
            }
        }
        reset_visit(); return make_pair(cc,scc);
        //after this operation scc maps a node to corresponding scc
        //cc maps scc component to nodes
    }
    void dfsSCC(int d,vector<int> &scc,vector<vector<int>> &c) 
    {
        visit[d] = true;
        for(int i=0;i<graph[d].size();i++)
        {
            if(scc[d] != scc[graph[d][i]])
                c[scc[d]].push_back(scc[graph[d][i]]);
            if(!visit[graph[d][i]])
                dfsSCC(graph[d][i],scc,c);
        }
    }
    vector<vector<int>> constructSCCGraph()
    {
        pair<vector<vector<int>>,vector<int>> p = kosaraju();
        vector<vector<int>> cc = p.first;
        vector<int> scc = p.second;
        reset_visit();
        vector<vector<int>> connect(cc.size());
        for(int i=0;i<n;i++)
            if(!visit[i])
                dfsSCC(i,scc,connect);
        for(int i=0;i<connect.size();i++)
        {
            vector<int> k = connect[i];
            connect[i].clear();
            unordered_map<int,bool> ch;
            for(int j=0;j<k.size();j++)
            {
                if(ch.find(k[j]) == ch.end())
                {
                    connect[i].push_back(k[j]);
                    ch[k[j]] = true;
                }
            }
            ch.clear();
        }
        return connect;
    }
};
const int MX = 100000;
int a[MX];
void solve()
{

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << "Hello\n";
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}

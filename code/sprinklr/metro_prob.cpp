#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
template<typename A,typename B>
inline A fpow(A x,B y){if(y<=1)return x;A k=fpow(x,y/2);k=k*k;if(y%2==1)k=k*x;return k;}
template<typename A>
inline int gcd(A a,A b){A t;while((a!=0)&&(b!=0)){t=a%b;a=b;b=t;}return a+b;}
template<typename A,typename B>
inline lli ncr(A x,B r){lli top=1,bot=1;while(r>=1){top*=(x-r+1);bot*=r--;}return top/bot;}
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
    { auto hash1=hash<T1>{}(p.first);auto hash2=hash<T2>{}(p.second);return hash1^hash2;}
};
auto comp = [](pair<int,int> left, pair<int,int> right)
{ return(left.second < right.second); };
vector<vector<int>> graph;
vector<bool> v;
vector<int> num;
int n,m;
void dfs(int d)
{
    v[d] = true;
    num[d] = (int)graph[d].size();
    for(int i=0;i<(int)graph[d].size();i++)
    {
        if(!v[graph[d][i]])
        {
            dfs(graph[d][i]);
            num[d] += num[graph[d][i]];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    //cin >> t;
    /*
     *  PLAN:
     *  Run kosaraju and find scc
     *  num_scc -> nodes in scc
     *  nodes_in_scc -> num_scc
     *  create unordered map mapping pair to bool containing connections between SCC
     *  create the adj. list of SCC graph (DAG, no need to worry about cycles)
     *  initialise value of every node i in each SCC with no. of components in its SCC - 1.
     *  traverse the SCC graph with DFS and calculate the number of nodes accessible from every SCC node and store them in an array
     *  for every node in the original graph, add the nodes reachable from the SCCs to the 
     */

    return 0;
}

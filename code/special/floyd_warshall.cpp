#include <bits/stdc++.h>
/*
 * Floyd Warshall Algorithm: Given the adjacency matrix representation of a graph,
 * find the minimum distance between all pairs of nodes in the graph.
 * Ex: Given nodes: 1,2,3,4
 * Find the distances between 1-2,1-3,1-4,2-3,2-4,3-4
 *
 * Sol: Current solution is made for undirected graph
 * */
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
auto cmp = [](pair<int,int> left, pair<int,int> right)
{ return(left.second < right.second); };
const int MX = 10000;
int D[MX][MX];
int n,m;
int graph[MX][MX];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j] = 0;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        graph[x-1][y-1] = w;
        graph[y-1][x-1] = w;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == j)
                D[i][j] = 0;
            else if(graph[i][j])
                D[i][j] = graph[i][j];
            else
                D[i][j] = MX;
        }
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                D[i][j] = min(D[i][j],D[i][k] + D[k][j]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << D[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

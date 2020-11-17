#include <bits/stdc++.h>
/*  
 *  Problem Statement: Given a board of snakes and ladders with snakes and ladders connecting
 *  different boxes similar to an actual snakes and ladders board game
 *
 *  Find the minimum number of throws a player needs to make in order to wih the game
 *  INPUT:  first line contains 3 integers n, s and l
 *          
 *
 */
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
vector<bool> v;
int s,l,n;
vector<vector<int>> link;
void solve()
{
    int m=6;
    cin >> n >> s >> l;
    v.resize(n,false);
    link.resize(n);
    int x,y;
    for(int i=0;i<s;i++)
    {
        cin >> x >> y;
        link[x-1].push_back(y-1);
    }
    for(int i=0;i<l;i++)
    {
        cin >> x >> y;
        link[x-1].push_back(y-1);
    }
    // use BFS to get to n-1
    queue<pair<int,int>> q;
    pair<int,int> a;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        if(a.first == n-1)
            break;
        for(int i=a.first+1;i<=min(a.first+m,n-1);i++)
        {
            if(!v[i])
            {
                pair<int,int> r;
                r.second = a.second + 1;
                v[i] = true;
                if(link[i].size() > 0)
                    r.first = link[i][0];
                else
                    r.first = i;
                q.push(r);
            }
        }
    }
    cout << a.second << "\n";
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

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
const int MX = 200000;
int a[MX];
int st[MX],to[MX],from[MX];
int n,q1,q2,g;
void preprocess()
{
    for(int i=0;i<n;i++)
        st[i] = i+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(__gcd(i,j) > g)
            {
                int f = min(st[j-1],st[i-1]);
                st[j-1] = f;
            }
        }
    }
}
vector<bool> solve()
{
    cin >> n >> g;
    cin >> q1;
    if(g == 0)
    {
        vector<bool> k(q1,true);
        return k;
    }
    preprocess();
    for(int i=0;i<q1;i++)
        cin >> from[i];
    cin >> q2;
    for(int i=0;i<q2;i++)
        cin >> to[i];
    vector<bool> b(q1,false);
    for(int i=0;i<q1;i++)
    {
        if(st[from[i]] == st[to[i]])
            b[i] = true;
    }
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        vector<bool> b = solve();
        for(int i=0;i<(int)b.size();i++)
            cout << b[i] << " ";
        cout << "\n";
    }
    return 0;
}

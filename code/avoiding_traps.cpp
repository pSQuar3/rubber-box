#include <bits/stdc++.h>
// Sprinklr Test Question
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
const int MX = 100000;
char a[MX];
int sieve[MX+1];
int D[MX];
int mx=-1;
void solve()
{
    int n,r1,r2;
    cin >> r1 >> r2 >> n;
    double x = (double)r1/(double)r2;
    for(int i=mx+1;i<=n;i++)
        sieve[i] = 0;
    for(int i = max(2,mx); i <= n;i++)
    {
        if(sieve[i])
            continue;
        for(int j = 2*i;j <= n;j += i)
            sieve[j] = i;
    }
    mx = max(mx,n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        D[i] = INT_MAX;
    }
    int A = 0;
    if(a[n-1] == '*')
    {
        cout << "No way!\n";
        return;
    }
    D[0] = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == '*')
            continue;
        if(i < n-1 && a[i+1] == '#')
            D[i+1] = min(D[i+1],D[i] + 1);
        if(i < n-2 && a[i+2] == '#')
            D[i+2] = min(D[i+2],D[i] + 1);
        if(!sieve[i+1])
            A++;
        if((double)A/(double)(i+1) >= x && i+1+A < n)
            D[i+A] = min(D[i+A],D[i] + 1);
    }
    if(D[n-1]-MX > 0)
        cout << "No way!\n";
    else
        cout << max(-1,D[n-1]) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

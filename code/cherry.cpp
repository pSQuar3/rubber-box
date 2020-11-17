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
    { auto hash1=hash<T1>{}(p.first); auto hash2=hash<T2>{}(p.second); return hash1^hash2; }
    template <typename T1>
    size_t operator()(const T1& p) const
    { auto hash1 = hash<T1>{}(p); return hash1;
        /* auto hash2 = hash<T1>{}(p.first); return hash1^hash2; */ }
};
const int MX = 1000;
int a[MX][MX];
int n;
void dpsolve()
{
    int i,j,D[n+1][n+1];
    for(i=0;i<n-1;i++)
    {
        if(a[0][i] == -1)
            a[0][i+1] = -1;
        if(a[i][0] == -1)
            a[i+1][0] = -1;
    }
    for(i=1;i<n;i++)
        for(j=1;j<n;j++)
            if(a[i-1][j] == -1 && a[i][j-1] == -1)
                a[i][j] = -1;
    for(i=0;i<=n;i++)
    {
        D[i][0] = -1;
        D[0][i] = -1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i == 1 || j == 1)
            {
                if(a[0][j-2] == -1)
                {
                    a[0][j-1] = -1;
                    D[0][j] = -1;
                }
                if(a[i-2][0] == -1)
                {
                    a[i-1][0] = -1;
                    D[i][0] = -1;
                }
                continue;
            }
            if(a[i-2][j-1] == -1 && a[i-1][j-2] == -1)
            {
                a[i-1][j-1] = -1;
                D[i][j] = -1;
            }
            else
                D[i][j] = a[i-1][j-1] + max(D[i-1][j],D[i][j-1]);
        }
    }
    i = n;j = n;
    while(i != 1 || j != 1)
    {
        a[i-1][j-1] = 0;
        if(D[i-1][j] > D[i][j-1])
            i = i - 1;
        else
            j = j - 1;
    }
    for(i=n;i>=1;i--)
    {
        for(j=n;j>=1;j--)
        {
            if(i == n || j == n)
            {
                if(a[n-1][j-2] == -1)
                {
                    a[n-1][j-1] = -1;
                    D[n][j] = -1;
                    continue;
                }
                if(a[i-1][n-1] == -1)
                {
                    a[i-2][n-1] = -1;
                    D[i][n] = -1;
                    continue;
                }
                else if(i == n)
                    D[i][j] = a[i-1][j-1] + 
            }
            if(a[i][j-1] == -1 && a[i-1][j] == -1)
            {
                a[i-1][j-1] = -1;
                D[i][j] = -1;
            }
            else
                D[i][j] = a[i-1][j-1] 
        }
    }
}
void solve()
{
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    dpsolve();

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

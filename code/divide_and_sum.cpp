#include <bits/stdc++.h>
#define lli unsigned long long 
#define ull unsigned long long int
using namespace std;
template<typename A,typename B>
inline A fast_power(A x,B y){if(y<=1)return x;A k=fast_power(x,y/2);k=k*k;if(y%2==1)k=k*x;return k;}
template<typename A>
inline int gcd(A a,A b){A t;while((a!=0)&&(b!=0)){t=a%b;a=b;b=t;}return a+b;}
template<typename A,typename B>
inline lli ncr(A x,B r){lli top=1,bot=1;while(r>=1){top*=(x-r+1);bot*=r;r--;} return top/bot;}
const int MX = 150000;
int a[MX];
void solve()
{
    int n;
    cin >> n;
    for(int i=0;i<2*n;i++)
        cin >> a[i];
    sort(a,a+2*n);
    long long int r=0,l=0;
    for(int i=0;i<n;i++)
        l += (lli)a[i];
    for(int i=n;i<2*n;i++)
        r += (lli)a[i];
    cout << (abs(r-l)*ncr<lli,lli>(2*n,n))%998244353 << "\n";
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

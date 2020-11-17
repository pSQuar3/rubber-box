#include <bits/stdc++.h>
// Google Coding test (Internship)
// https://leetcode.com/discuss/interview-question/396646/Google-or-OA-Summer-Intern-2020-or-Maximum-Number-of-Strawberries/357180
// solution is wrong ( all test cases do not pass )
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
int a[MX];
int D[MX+1];
int n,k;
int solve()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    if(n == 0)
        return -1;
    if(n == 1)
        return (a[0] <= k)? a[0]:(-1);
    D[0] = 0;
    D[1] = a[0];
    int mx=-1;
    int f = -1;
    for(int i=2;i<=n;i++)
    {
        mx = -1;
        for(int j=i-1;j>=1;j--)
        {
            if(D[j-1] + a[i-1] <= k && mx < D[j-1] + a[i-1])
                mx = D[j-1] + a[i-1];
            if(mx == k)
                return k;
        }
        D[i] = mx;
        f = max(f,mx);
    }
    return f;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        cout << solve() << "\n";
    return 0;
}

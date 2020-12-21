#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
template<typename A,typename B>
inline A fpow(A x,B y){if(y<=1)return x;A k=fpow(x,y/2);k=k*k;if(y%2==1)k=k*x;return k;}
template<typename A>
inline int gcd(A a,A b){A t;while((a!=0)&&(b!=0)){t=a%b;a=b;b=t;}return a+b;}
template<typename A,typename B>
inline lli ncr(A x,B r)
{
    lli top=1,bot=1;
    while(r>=1)
    {
        top*=(x-r+1);
        bot*=r--;
    }
    return top/bot;
}
template<typename A>
inline pair<A,int> kadane(A x[], int n) {
    A max_so_far = -9999999999999, max_ending_here = 0; int h = 0;
    for(int i=0;i<n;i++) { max_ending_here += x[i];
        if(max_so_far < max_ending_here) { max_so_far = max_ending_here; h = i; }
        if(max_ending_here < 0) max_ending_here = 0;}
    return make_pair(max_so_far,h);
}
const int INF = 10000;
const int MX = 10000;
int sieve[MX+1],mxkq=0;
inline void buildSieve(int xw) {
    for(int i=mxkq;i<=max(xw,mxkq);i++) sieve[i] = 0;
    for(int i = max(2,mxkq); i <= xw;i++) {
        if(sieve[i]) continue;
        for(int j = 2*i;j <= xw;j += i) sieve[j] = i;
    } mxkq = max(mxkq,xw); }
struct custom_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    { auto hash1=hash<T1>{}(p.first);auto hash2=hash<T2>{}(p.second);return hash1^hash2;}
};
auto comp = [](pair<int,int> left, pair<int,int> right)
{ return(left.second < right.second); };
lli D[MX][MX];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 1;
    int k = 15;
    while(n != k)
    {
        D[0][0] = 1;
        for(int i=0;i<n;i++)
        {
            D[i][0] = 1;
            D[0][i] = 1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                D[i][j] = D[i-1][j] + D[i][j-1];
            }
        }
        cerr << "n = " << n << " DP algo = " << D[n-1][n-1] << " ";
        if(n == 1)
            cout << "Calculated = 1\n";
        else
            cout << "Calculated = " << ncr<int,int>(2*n-2, n-1) << "\n";
        n++;
    }
    return 0;
}

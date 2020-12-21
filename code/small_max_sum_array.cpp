#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int INF = 10000;
const int MX = 100000;
const int MOD = 1000000009;
template<typename A,typename B>
lli fpow(A x,B y,long M)
{
    if(y == 1) return x%M;
    if(y == 0) return 1;
    A k = fpow(x, y/2, M);
    if(y%2 == 0)
        return (k * k) % M;
    return (((k * k) % M) * x) % M;
}
template<typename A>
inline int gcd(A a,A b){A t;while((a!=0)&&(b!=0)){t=a%b;a=b;b=t;}return a+b;}
template<typename A,typename B>
inline long modular_inverse(A n,B M) { return fpow<A,B>(n,M-2,(long)M); }
template<typename A,typename B>
inline lli ncr(A x,B r,long M) {
    if(r == 0) return 1; lli v = ncr(x-1,r-1,M);
    v = (x*v)%M; v = (x*modular_inverse<A,B>(r,M))%M; return v;
}
struct custom_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1=hash<T1>{}(p.first);auto hash2=hash<T2>{}(p.second);
        return hash1^hash2;
    }
};
int mxkq=0;
inline void buildSieve(int xw,int sieve[]) 
{
    for(int i=mxkq;i<=max(xw,mxkq);i++)
        sieve[i] = 0;
    for(int i = max(2,mxkq); i <= xw;i++)
    {
        if(sieve[i])
            continue;
        for(int j = 2*i;j <= xw;j += i)
            sieve[j] = i;
    }
    mxkq = max(mxkq,xw);
}
auto cmp = [](pair<int,int> left, pair<int,int> right)
{
    return(left.second < right.second);
};
int a[MX];
int sieve[MX+1];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
/*find the smallest subarray of a given array such that the sum of the elements of that subarray is greater than x


INPUT:
2
6 51
1 4 45 6 0 19
5 9
1 10 5 2 7

OUTPUT:
4 45 6
10

*/

//    cin >> t;
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        for(int i=0;i<n;i++)
            cin >> a[i];
        int l=INT_MAX,sum = 0;
        int i=0,j=0;
        while(sum <= x)
        {
            sum = sum + a[j];
            j++;
        }
        /*
         * calculate the first block
         * 
         */
        int p = 0;
        j--;
        while(i <= j && j < n)
        {
            if(sum > x && j-i+1 < l)
            {
                l = j-i+1;
                sum = sum - a[i];
                p = i;
                i++;
            }
            else
            {
                j++;
                sum += a[j];
            }
        }
//        if(j == n && sum < n)
        for(i = p;i<p+l;i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}

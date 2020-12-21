#include <bits/stdc++.h>
/*
 *  Problem Statement: https://codeforces.com/contest/1437/problem/D
 *
 *  Problem statement is pretty long, couldn't paste here
 */
#define lli long long int
#define ull unsigned long long
using namespace std;
const int INF = 10000;
const int MX = 200000;
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
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        int c = 0;
        int i = 1;
        queue<int> q;
        q.push(1);
        unordered_map<int,bool> mp;
        mp[1] = true;
        while(i < n)
        {
            int w = q.front();
            q.pop();
            q.push(a[i]);
            i++;
            while(a[i] >= a[i-1])
            {
                q.push(a[i]);
                i++;
            }
            if(mp.find(w) != mp.end())
            {
                mp[a[i-1]] = true;
                c++;
            }
        }
        if(mp.find(a[i-1]) == mp.end())
            c++;
        cout << c << "\n";
        mp.clear();
    }
    return 0;
}

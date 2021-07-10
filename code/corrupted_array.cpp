// https://codeforces.com/problemset/problem/1512/D
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
int b[MX+2];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    while(t--)
    {
        int n,s=0,x=0,bn=0,ind=-1;
        cin >> n;
        unordered_map<int,int> mp;
        for(int i=0;i<n+2;i++)
        {
            cin >> b[i];
            s += b[i];
            mp[b[i]] = i;
        }
        for(int i=0;i<n+2 && !bn;i++)
        {
            int g = s - b[i];
            if(g%2)
                continue;
            else if(mp.find(g/2) != mp.end())
            {
                ind = mp[g/2];
                bn = g/2;
                b[ind] = -1;
            }
        }
        s = s - bn;
        for(int i=0;i<n+2 && !x;i++)
        {
            if(s-b[i] == bn)
            {
                x = b[i];
                b[i] = -1;
            }
        }
        if(bn == 0 || x == 0)
            cout << "-1\n";
        else
        {
            for(int i=0;i<n+2;i++)
            {
                if(b[i] > 0)
                    cout << b[i] << " ";
            }
            cout << "\n";
        }
        

        /*
        unordered_map<int,int> x;
        for(int i=0;i<n+2;i++)
        {
            cin >> b[i];
            s += b[i];
            x[b[i]]++;
        }
        for(int i=0;i<n+2 && !fin;i++)
        {
            g = (s - b[i]);
            if(g%2)
                continue;
            g = g/2;
            if(x.find(g) != x.end())
            {
                fin = g;
                g = b[i];
            }
        }
        if(fin == 0)
        {
            cout << "-1\n";
            continue;
        }
        for(unordered_map<int,int>::iterator i = x.begin();i != x.end();i++)
        {
            int h = i->second;
            if(i->first == fin || i->first == g)
            {
                h = h-1;
                if(fin == g)
                    h = h-1;
            }
            while(max(0,h--))
                cout << i->first << " ";
        }
        cout << "\n";
        */
    }
    return 0;
}

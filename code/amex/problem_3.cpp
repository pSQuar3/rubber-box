#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int INF = 10000;
const int MX = 100000;
const int MOD = 1e9;
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
inline bool checkVowel(char c)
{
    return(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
lli fact(int n)
{
    lli x= 1;
    for(int i=1;i<=n;i++)
        x = (x*i)%MOD;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    //cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        unordered_map<char,int> vowels;
        unordered_map<char,int> costs;
        int n=(int)s.length();
        for(int i=0;i<n;i++)
        {
            if(checkVowel(s[i]))
                vowels[s[i]]++;
            else
                costs[s[i]]++;
        }
        int n_v=0,n_c = 0;
        for(unordered_map<char,int>::iterator it = vowels.begin();it != vowels.end();it++)
        {
            n_v += it->second;
        }
        for(unordered_map<char,int>::iterator it = costs.begin();it != costs.end();it++)
        {
            n_c += it->second;
        }
        if(n_v != n_c && n_v != n_c-1)
        {
            cout << 0 << "\n";
        }
        else
        {
            lli f = fact(n_v);
            lli s = 1;
            lli consonant=fact(n_c);
            for(unordered_map<char,int>::iterator i = costs.begin();i != costs.end();i++)
            {
                consonant = consonant/fact(i->second);
            }
            for(unordered_map<char,int>::iterator i = vowels.begin();i != vowels.end();i++)
            {
                vowels[i->first]--;
                for(unordered_map<char,int>::iterator j = vowels.begin();j != vowels.end();j++)
                {
                    
                }
            }
        }
    }
    return 0;
}

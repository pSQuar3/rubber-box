#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int MX = 100000;
int mxkq=0;
template<class A>
bool isPrime(A a)
{
    int g = floor(sqrt(a));
    for(int i=2;i<=g;i++)
        if(a%i == 0)
            return false;
    return true;
}
int sieve[MX+1];
inline void buildSieve(int xw) 
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
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    vector<int> k(3);
    while(t--)
    {
        int n;
        cin >> n;
        buildSieve(n);
        bool b = true;
        if(n <= 5)
        {
            cout << -1 << "\n";
            continue;
        }
        for(int i=2;b && i<=n-4;i++)
        {
            if(sieve[i] != 0)
                continue;
            for(int j=i;b && j<=n-2;j++)
            {
                if(sieve[j] == 0 && sieve[n-i-j] == 0)
                {
                    b = false;
                    k[0] = i;
                    k[1] = j;
                    k[2] = n-i-j;
                }
            }
        }
        if(b)
            cout << -1 << "\n";
        else
            cout << k[0] << " " << k[1] << " " << k[2] << "\n";
//        cout << isPrime<int>(k[0]) << " " << isPrime<int>(k[0]) << " " << isPrime<int>(k[0]) << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
// codeforces buy string problem
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    while(t--)
    {
        int n,c0,c1,h;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        int m=0;
        for(int i=0;i<n;i++)
            if(s[i] == '1')
                m++;
        int mn = INT_MAX;
        for(int k=0;k<n-m+1;k++)
        {
            int price = (m+k)*c1 + ((n-m)-k)*c0 + k*h;
            if(price > 0 && price < mn)
                mn = price;
        }
        for(int k=0;k<m+1;k++)
        {
            int price = (m-k)*c1 + ((n-m)+k)*c0 + k*h;
            if(price > 0 && price < mn)
                mn = price;
        }
        cout << mn << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ct = 0;
        while(n > 1)
        {
            int i=2,x = floor(sqrt(n));
            while(n%i != 0 && i < x)
                i++;
            if(n == i)
                n = 1;
            else
                n = i;
            ct++;
        }
        cout << ct << "\n";
    }
    return 0;
}

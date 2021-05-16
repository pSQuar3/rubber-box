// Problem: http://codeforces.com/problemset/problem/1520/C
// Possible error in Codeforces checker. Following code validates the solution I made
#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int INF = 10000;
const int MX = 100;
int a[MX][MX];
bool validate(int n)
{
    // constructing matrix
    int current = 1;
    for(int diag=0;diag<n;diag++)
        a[diag][diag] = current++;
    for(int diag = 1;diag < n;diag++)
    {
        for(int i=0;i<n-diag;i++)
        {
            a[i][i+diag] = current;
            current++;
        }
        for(int i=0;i<n-diag;i++)
        {
            a[i+diag][i] = current;
            current++;
        }
    }
    // validating the matrix
    cerr << "Matrix " << n << "x" << n << " constructed: ";
    bool ch=true;
    for(int i=1;ch && i<n;i++)
    {
        if(abs(a[i][0]-a[i-1][0]) == 1 || abs(a[0][i]-a[0][i-1]) == 1)
            ch = false;
    }
    for(int i=1;i<n && ch;i++)
    {
        for(int j=1;j<n && ch;j++)
        {
            if(abs(a[i][j]-a[i-1][j]) == 1 || abs(a[i][j] - a[i][j-1]) == 1)
                ch = false;
        }
    }
    cout << ((ch == true)? "TRUE":"FALSE") << "\n";
    return ch;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 3;
    while(t <= 100)
    {
        if(t == 1)
            cout << 1 << "\n";
        else if(t == 2)
            cout << -1 << "\n";
        else if(validate(t) == false)
        {
            cout << "ERROR at n = " << t << "\n";
            t = 101;
        }
        t++;
    }
    return 0;
}

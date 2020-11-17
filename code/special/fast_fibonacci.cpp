#include <bits/stdc++.h>
#define lli long long int
using std::cin;
using std::cout;
using std::endl;
int n;
lli F[2][2] = {{1,1},{1,0}};
lli A[2][2] = {{1,1},{1,0}};
void multiply(lli P[2][2], lli B[2][2])
{
    lli w = P[0][0]*B[0][0] + P[0][1]*B[1][0];
    lli x = P[0][0]*B[0][1] + P[0][1]*B[1][1];
    lli y = P[1][0]*B[0][0] + P[1][1]*B[1][0];
    lli z = P[1][0]*B[0][1] + P[1][1]*B[1][1];
    A[0][0] = w;
    A[0][1] = x;
    A[1][0] = y;
    A[1][1] = z;
}
void power(int i)
{
    if(i == 0 || i == 1)
        return;
    power(i/2);
    multiply(A,A);
    if(i%2 == 1)
        multiply(A,F);
}
lli fib_fast(int i)
{
    if(i <= 1)
        return i;
    power(i-1);
    return A[0][0];
}
inline void solve()
{
    cin >> n;
    cout << fib_fast(n) << endl;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t-- > 0)
        solve();
    return 0;
}

#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int n;
const lli M = 1e9 + 9;
const lli M2 = 1e9;
lli F[2][2] = {{10,1},{-1,0}};
lli A[2][2] = {{10,1},{-1,0}};
void multiply(lli P[2][2], lli B[2][2])
{
    lli w = (((P[0][0]%M2)*(B[0][0]%M2))%M2 + ((P[0][1]%M2)*(B[1][0]%M2))%M2);
    lli x = (((P[0][0]%M2)*(B[0][1]%M2))%M2 + ((P[0][1]%M2)*(B[1][1]%M2))%M2);
    lli y = (((P[1][0]%M2)*(B[0][0]%M2))%M2 + ((P[1][1]%M2)*(B[1][0]%M2))%M2);
    lli z = (((P[1][0]%M2)*(B[0][1]%M2))%M2 + ((P[1][1]%M2)*(B[1][1]%M2))%M2);
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
//    cin >> n;
	F[0][0] = 10;
	F[0][1] = 1;
	F[1][0] = -1;
	F[1][1] = 0;
	A[0][0] = 10;
	A[0][1] = 1;
	A[1][0] = -1;
	A[1][1] = 0;
    cout << fib_fast(n+1)%M << "\n";
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while(t-- > 0)
    {
//        int x;
        cin >> n;
//        for(int i=1;i<=x;i++)
//        {
//            n = i;
            solve();
//        }
	}
    return 0;
}

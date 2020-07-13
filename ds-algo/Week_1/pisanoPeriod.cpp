#include <iostream>
using namespace std;

long long int fibN(long long int n)
{
    long long int a=0,b=1,fibnum=1;
    long long int k;
    if(n <= 1)
        fibnum = n;
    else
    {
        while(fibnum < n)
        {
            //cout << b << " ";
            long long int l = b;
            b = a+b;
            a = l;
            fibnum++;
        }
    }
    return b;
}
long long int get_pisano_period(long long int m)
{
    int i;
    long long int a = 0, b = 1, c = a + b;
    for (i = 0; i < m * m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            break;
    }
    return (long long int)i+1;
}
int main()
{
    long long int n,m,k;
    cin >> n >> m;
    k = get_pisano_period(m);
    cout << fibN(n%k)%m;
    return 0;
}

#include <iostream>
using namespace std;
#define lli long long int
lli gcd(lli a, lli b)
{
    lli t;
    // gcd(a,b) = gcd(b,a%b)
    while((a != 0)&&(b != 0))
    {
        t = a%b;
        a = b;
        b = t;
    }
    return a+b;

}

int main()
{
    lli a,b;
    cin >> a >> b;
    if(b > a)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    lli l = (a*b)/gcd(a,b);
    cout << l;
    return 0;
}

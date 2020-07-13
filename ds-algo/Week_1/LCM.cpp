#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    long long int t;
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
    long long int a,b;
    cin >> a >> b;
    if(b > a)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    long long int l = (a*b)/gcd(a,b);
    cout << l;
    return 0;
}

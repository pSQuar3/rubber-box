#include <iostream>
#include <new>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long gcd(long a, long b)
{
    long t;
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
    cout << "Calculation of the GCD of 2 numbers using Eucliden Algorithm" << endl;
    cout << "Enter the 2 numbers: ";
    long a, b;
    cin >> a >> b;
    cout << "GCD = " << gcd(a,b);
    return 0;
}

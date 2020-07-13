#include <iostream>
using namespace std;
int main()
{
    unsigned long long int n;
    cin >> n;
    unsigned long long int a=0,b=1,fibnum=1;
    unsigned long long int k;
    if(n <= 1)
        b = n;
    else
    {
        while(fibnum < n)
        {
            //cout << b << " ";
            unsigned long long int l = b%10;
            b = (a+b)%10;
            a = l;
            fibnum++;
        }
    }
    cout << b;
    return 0;
}

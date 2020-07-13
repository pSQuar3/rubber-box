#include <iostream>
using namespace std;
int main()
{
    unsigned long long int n,m;
    cin >> n >> m;
    unsigned long long int a=0,b=1,fibnum=1,sm=0;
    unsigned long long int k;
    if(n <= 1)
        b = n;
    else
    {
        while(fibnum < n)
        {
            if((fibnum >= m)&&(fibnum <= n))
            {
                //part regarding the calculation of the partial sum
                sm += b;
                sm = sm%10;
            }
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

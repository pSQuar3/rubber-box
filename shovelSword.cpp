#include <iostream>
#include <new>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int modrl(int a)
{
    return (a > 0)? a:-a;
}

int main()
{
    int t,a,b;
    cin >> t;
    int ans[t];
    for(int i=0;i<t;i++)
    {
        int c=0;
        cin >> a >> b;
        int sum = a+b,md = modrl(a-b);
        a = (sum + md)/2;
        b = (sum - md)/2;
        //b = min(c,d);
        while((b >= 1)&&(a >= 2))
        {
            a-=2;
            b-=1;
            sum = a+b;
            md = modrl(a-b);
            a = (sum + md)/2;
            b = (sum - md)/2;
            c++;

        }
        ans[i] = c;
    }
    for(int i=0;i<t;i++)
        cout << ans[i] << " ";
    return 0;
}

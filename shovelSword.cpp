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
        int k,c=0;
        cin >> a >> b;
        int sum = a+b,md = modrl(a-b);
        a = (sum + md)/2;
        b = (sum - md)/2;
        //counting the number of l's
        c = min(a-b,b);
        if((a == b)&&(a%2 == 1)&&((a > 1)||(b > 1)))
            c++;
        a = a - 2*c;
        b = b - c;
        // counting the 3x2 rectangles
        k = b/3;
        c += 2*k;
        a = a - 3*k;
        b = b - 3*k; 
        if(((a == 1)&&(b == 2)) || ((a == 2)&&(b == 1)) || ((a == 2)&&(b == 2)))
            c++;
        ans[i] = c;
    }
    for(int i=0;i<t;i++)
        cout << ans[i] << " ";
    return 0;
    
}

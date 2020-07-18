#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int sols[t];
    for(int i;i<t;i++)
    {
        int n,countfront=0,countback=0;
        cin >> n;
        char a[n];
        for(int j=0;j<n;j++)
            cin >> a[j];
        for(int j=0;j<n/2;j++)
        {
            if(a[j] == 'a')
                countfront++;
            if(a[n/2+j] == 'a')
                countback++;
        }
        countback = (int)countback%(n/2);
        countfront = (int)countfront%(n/2);
        if((countback > 0)&&(countfront > 0))
            sols[i] = min(countback,countfront);
        else
            sols[i] = max(countback,countfront);
    }
    for(int i=0;i<t;i++)
        cout << sols[i] << " ";
    return 0;
}

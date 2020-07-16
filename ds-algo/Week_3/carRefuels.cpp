#include <iostream>
using namespace std;
//assuming that the gas station locations are sorted according to the distance from the starting point
int main()
{
    int n,d,m,current=0,refCount=0;
    cin >> d >> m >> n;
    int a[n+2];
    a[0] = 0;
    a[n+1] = d;
    bool b = true;
    for(int i=1;i<n+1;i++)
    {
        cin >> a[i];
        if(a[i] - a[i-1] > m)
            b = false;   
    }
    if(a[n+1]-a[n] > m)
        b = false;
    n += 2;
    
    if(!b)
        refCount = -1;
    int i=0;
    while((b)&&(i < n))
    {
        if(a[i]-current > m)
        {
            current = a[i-1];
            refCount++;
        }
        else
            i++;
    }
    cout << refCount;
    return 0;
}

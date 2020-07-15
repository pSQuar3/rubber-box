#include <iostream>
using namespace std;
//assuming that the gas station locations are sorted according to the distance from the starting point
int minRefill(int *x, int n, int l)
{
    int numRefill=0,currentRefill=0;
    while((numRefill != -1)&&(currentRefill <= n))
    {
        int lastRefill = currentRefill;
        while((currentRefill <= n)&&(x[currentRefill+1] - x[lastRefill] <= l))
            currentRefill++;
        if(currentRefill == lastRefill)
            numRefill = -1;
        if(currentRefill <= n)
            numRefill++;
    }
    return numRefill;
}

int main()
{
    int n,d,m,current=0,refCount=0;
    cin >> d >> m >> n;
    int a[n+2];
    bool b = true;
    for(int i=1;i<n+1;i++)
    {
        cin >> a[i];
        if(i > 1)
        {
            if(a[i] - a[i-1] > m)
                b = false;
        }
    }
    a[0] = 0;
    a[n+1] = d;
    n += 2;
    int i=0;
    if(!b)
        refCount = -1;
    while((b)&&(i < n))
    {
        if(a[i]-current > m)
        {
            if(a[i] == d)
                refCount = -1;
            else
            {
                current = a[i-1];
                refCount++;
                
            }
        }
        i++;
        //cout << "INF" << endl;
    }
    cout << refCount;
    return 0;
}

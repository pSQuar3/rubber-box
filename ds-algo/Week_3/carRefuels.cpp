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
    int n,l;
    cin >> n >> l;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int k = minRefill(a,n,l);
}

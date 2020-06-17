#include <iostream>
#include <cmath>
using namespace std;

bool checkSorted(int* a)
{
    bool b = true;
    for(int i=1;i<sizeof(a);i++)
    {
        if(a[i] < a[i-1])
            b = false;
    }
    return b;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        //test cases loop begins
        //

        int n,zerocount=0,oin=0,zin=0;
        cin >> n;
        int a[n],b[n],one[n],zero[n];
        for(int j=0;j<n;j++)
            cin >> a[i];
        for(int j=0;j<n;j++)
        {
            cin >> b[i];

            if(b[i] == 0)
            {
                zerocount++;
                zero[zin++] = a[i];
            }
            else
            {
                one[oin++] = a[i];
            }
        }
        if(!checkSorted(a))
        {
            //case when the array is in non-descending order

            
        }
        //acccepted the elements
        /*if(zerocount > n-zerocount)
            zerocount = n-zerocount;
        
        23 21 45 67 87
        0  1  0  1  0
        */
        
    }
}

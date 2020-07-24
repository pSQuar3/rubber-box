#include <iostream>
#include <cmath>
using namespace std;

long int binarysearch(long int *a, long low, long high, long int key)
{
    long int mid = floor((low+high)/2);
    if(high < low)
        return low-1;
    if(key == a[mid])
        return mid;
    else if(key < a[mid])
        return binarysearch(a,low,mid-1,key);
    else
        return binarysearch(a,mid+1,high,key);
}


int main()
{
    long n,m;
    cin >> n;
    long int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> m;
    long int b[m];
    long int key=0;
    //cout << "now initialising the values of b" << endl;
    for(int i=0;i<m;i++)
    {
        b[i] = -1;
        //cout << "Entering the for loop with i = " << i << endl;
        cin >> key;
        if((key > a[n-1])||(key < a[0]))
            b[i] = -1;
        else
        {
            b[i] = binarysearch(a,0,n-1,key);
            if(a[b[i]] != key)
                b[i] = -1;
        }
    }
    for(int i=0;i<m;i++)
        cout << b[i] << " ";
    return 0;
}

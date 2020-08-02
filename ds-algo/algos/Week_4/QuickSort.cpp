#include <iostream>
using namespace std;

int chooseM(int l,int r)
{
    return 0;
}

int partition(int *a, int l,int r)
{
    cout << "partition block" << endl;
    int j = l;
    for(int i=l+1;i<=r;i++)
    {
        if(a[i] <= a[l])
        {
            j++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void qsort(int *a,int l, int r)
{
    cout << "qsort block" << endl;
    int m = partition(a,l,r);
//    if((m-l) < (r-m))
//    {
        cout << "qsort left" << endl;
        qsort(a,l,m-1);
//        l = m+1;
//    }
//    else
//      {
        cout << "qs right" << endl;
        qsort(a,m+1,r);
//        r = m-1;
    
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << "Accepted array" << endl;
    qsort(a,0,n-1);
    cout << "Sorted Array" << endl;
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}

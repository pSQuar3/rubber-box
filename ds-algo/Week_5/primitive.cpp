#include <iostream>
using namespace std;

void findMin(int n)
{
    //operations: 
    //  1. multiply by 2
    //  2. multiply by 3
    //  3. add 1
    int a[n];
    int nums[n];
    int top=0;
    a[0] = 0;
    for(int i=1;i<n;i++)
        a[i] = n;
    for(int i=1;i<=n;i++)
    {
        int s,t,u;
        int rems[] = {n,n,n};
        if(i%3 == 0)
            rems[0] = i/3;
        rems[2] = i-1;
        if(i%2 == 0)
            rems[1] = i/2;
        a[i] = min(a[rems[0]],min(a[rems[1]],a[rems[2]]))+1;

    }
    cout << a[n-1] << endl;
}

int main()
{
    int n;
    cin >> n;
    findMin(n);
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int denoms[] = {10,5,1};
    int mon,ct=0;
    cin >> mon;
    for(int i=0;i<3;i++)
    {
        ct += mon/denoms[i];
        mon = mon%denoms[i];
    }
    cout << ct;
    return 0;
}

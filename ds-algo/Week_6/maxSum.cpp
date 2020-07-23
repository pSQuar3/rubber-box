#include <iostream>
using namespace std;
int d[14];
char op[13];
int main()
{
    int n;
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0)
            cin >> d[i/2];
        else
            cin >> op[i-1];
    }
    return 0;
}

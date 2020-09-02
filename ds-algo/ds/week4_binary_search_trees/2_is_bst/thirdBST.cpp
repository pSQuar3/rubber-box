#include <iostream>
#define epl() cout << endl;
using namespace std;
#define MX 100000

int k[MX];
int l[MX];
int r[MX];
int it[MX];
int n,indx=0;

void in_order(int ind)
{
    if(ind < n)
    {
        if(l[ind] != -1)
            in_order(l[ind]);
        it[indx] = k[ind];
        indx++;
        if(r[ind] != -1)
            in_order(r[ind]);
    }
}
int main()
{
    std::ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> k[i] >> l[i] >> r[i];
    in_order(0);
    bool b=true;
    for(int i=1;b && i<n;i++)
    {
        if(it[i] < it[i-1])
            b = false;
    }
    cout << ((b)? "CORRECT":"INCORRECT") << endl;
}

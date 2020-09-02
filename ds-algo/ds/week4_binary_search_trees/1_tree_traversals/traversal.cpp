#include <iostream>
#define epl() cout << endl;
using namespace std;
#define MX 100000

int k[MX];
int l[MX];
int r[MX];
int n;

void in_order(int ind)
{
    if(ind < n)
    {
        if(l[ind] != -1)
            in_order(l[ind]);
        cout << k[ind] << " ";
        if(r[ind] != -1)
            in_order(r[ind]);
    }
}
void pre_order(int ind)
{
    if(ind < n)
    {
        cout << k[ind] << " ";
        if(l[ind] != -1)
            pre_order(l[ind]);
        if(r[ind] != -1)
            pre_order(r[ind]);
    }
}
void post_order(int ind)
{
    if(ind < n)
    {
        if(l[ind] != -1)
            post_order(l[ind]);
        if(r[ind] != -1)
            post_order(r[ind]);
        cout << k[ind] << " ";
    }
}
void solve()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> k[i] >> l[i] >> r[i];
    in_order(0);
    epl();
    pre_order(0);
    epl();
    post_order(0);
    epl();
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

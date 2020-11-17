#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;
const int MX = 100000;
int *a[MX+1];
int n;
void solve()
{
    //cin >> n;
    n = 9;
    int h = 1;
    int *i = &h;
    while(*i <= n)
    {
        a[*i] = i;
        int k = *i + 1;
        i++;
        *i = k;
    }
    a[2] = a[4];
    a[5] = a[2];
    for(int j=1;j<=n;j++)
        cout << (long)a[j] << "\n";
    cout << "\n";
}
struct Node
{
    Node *sset;
    void init(Node *k)
    {
        sset = k;
    }
};
Node *arr[MX];
unordered_map<int,Node*> mp;
void dJ()
{
    n = 9;
    Node *q;
    for(int i=1;i<=n;i++)
    {
        q = new Node();
        q->init(q);
        arr[i] = q;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}

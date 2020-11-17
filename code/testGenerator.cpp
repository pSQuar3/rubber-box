#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t; // number of testcases
    int n;
    cin >> n; // max limit of integers
    srand(time(NULL));
    cout << t << endl;
    while(t--)
    {
        cout << (int)(rand())%n << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::min;
using std::ios_base;
string a,b;
int findDist()
{
    int n = (int)a.size();
    int m = (int)a.size();
    int edt[n+1][m+1];
    for(int i=1;i<=m;i++)
        edt[0][i] = i;
    for(int i=1;i<=n;i++)
        edt[i][0] = i;
    edt[0][0] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1] == b[i-1])
                edt[i][j] = min(edt[i][j-1]+1,min(edt[i-1][j]+1,edt[i-1][j-1]));
            else
                edt[i][j] = min(edt[i][j-1]+1,min(edt[i-1][j]+1,edt[i-1][j-1]+1));
        }
    }
    return edt[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    cin >> b;
    int k = findDist();
    cout << k << endl;
}

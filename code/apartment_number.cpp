#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long
#define MX 100000

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::max;
int t,n;
int D[1001][3];
int a[1000];

void solve()
{
    int arr[] = {3,5,7};
    bool found;
    int x,y,z;
    for(int i=0;i<=n;i++)
    {
        found = false;
        if(i >= 3)
        {
            for(int j=0;!found && j<3;j++)
            {
                if(i >= arr[j])
                {
                    x = D[i-arr[j]][0];
                    y = D[i-arr[j]][1];
                    z = D[i-arr[j]][2];
                    int akm[] = {0,0,0};
                    if(arr[j] == 3)
                        akm[0] = 1;
                    else if(arr[j] == 5)
                        akm[1] = 1;
                    else if(akm[j] == 7)
                        akm[2] = 1;
                    if(x+y+z > 0 || i == arr[j])
                    {
                        found = true;
                        D[i][0] += x + akm[0];
                        D[i][1] += y + akm[1];
                        D[i][2] += z + akm[2];
                    }
                }
            }
        }
    }
    for(int i=0;i<t;i++)
    {
        if(D[a[i]][0] > 0 || D[a[i]][1] > 0 || D[a[i]][2] > 0)
            cout << D[a[i]][0] << " " << D[a[i]][1] << " " << D[a[i]][2];
        else
            cout << -1;
        cout << endl;
    }
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<3;j++)
            cerr << D[i][j] << " ";
        cerr << endl;
    }
    */
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    n = -1;
    for(int i=0;i<t;i++)
    {
        cin >> a[i];
        n = max(n,a[i]);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<3;j++)
            D[i][j] = 0;
    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<3;j++)
            cerr << D[i][j] << " ";
        cerr << endl;
    }*/
    solve();
    /*
    for(int i=0;i<=n;i++)
    {
        found = false;
        if(i >= 3)
        {
            for(int j=0;!found && j<3;j++)
            {
                x = D[i-arr[j]][0];
                y = D[i-arr[j]][1];
                z = D[i-arr[j]][2];
                int akm[] = {0,0,0};
                if(arr[j] == 3)
                    akm[0] = 1;
                else if(arr[j] == 5)
                    akm[1] = 1;
                else if(akm[j] == 7)
                    akm[2] = 1;
                if(x+y+z > 0 || i == arr[j])
                {
                    found = true;
                    D[i][0] += x + akm[0];
                    D[i][1] += y + akm[1];
                    D[i][2] += z + akm[2];
                }
            }
        }
    }
    for(int i=0;i<t;i++)
    {
        if(D[a[i]][0] + D[a[i]][1] + D[a[i]][2] > 0)
            cout << D[a[i]][0] << " " << D[a[i]][1] << " " << D[a[i]][2];
        else
            cout << -1;
        cout << endl;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<3;j++)
            cerr << D[i][j] << " ";
        cerr << endl;
    }*/
    return 0;
}

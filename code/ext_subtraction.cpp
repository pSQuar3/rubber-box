#include <bits/stdc++.h>
using namespace std;
const int MX = 30000;
int a[MX];
int mx[MX];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        bool b=true;
        mx[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mx[i] = mx[i+1];
            if(a[i] > mx[i+1])
                mx[i] = a[i];
        }
        int m=a[0];
        //debug
        for(int i=0;i<n;i++)
            cerr << mx[i] << " ";
        cerr << "\n";
        for(int i=1;b && i<n-1;i++)
        {
            cerr << "check = " << a[i] << "m = " << m << "\n";
            if(a[i] > m+mx[i+1] || )
                b = false;
            if(a[i] > m)
                m = a[i];
        }
        if(b)
            cout << "YES\n";
        else
            cout << "NO\n";
        /*
         // working solution: java
            int b[n];
            int c[n];
            b[0] = a[0];
            for(i=1;i<n;i++)
            {
                if(a[i]<c[i-1])
                {
                    cout << "NO\n";
                    continue;
                }
                c[i] = c[i-1];
                b[i] = a[i] - c[i];
                if(b[i] > b[i-1])
                {
                    c[i] += b[i] - b[i-1];
                    b[i] = b[i-1];
                }
            }
            pw.println("YES");
            */
    }
    return 0;
}

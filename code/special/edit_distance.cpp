#include <iostream>
#include <string>
//code ready for submission
using namespace std;

int edit(char *a,char *b,int n,int m)
{
    int D[n+1][m+1];
    for(int i=0;i<n+1;i++)
        D[i][0] = i;
    for(int i=0;i<m+1;i++)
        D[0][i] = i;
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i-1] == b[j-1])
                D[i][j] = min(D[i][j-1]+1,min(D[i-1][j]+1,D[i-1][j-1]));
            else
                D[i][j] = min(D[i][j-1]+1,min(D[i-1][j]+1,D[i-1][j-1]+1));
        }
    }
    /*cout << "    ";
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
    for(int j=0;j<=m;j++)
    {
        if(j == 0)
            cout << "  ";
        if(j > 0)
            cout << b[j-1] << " ";
        for(int i=0;i<=n;i++)
        {
            cout << D[i][j] << " ";
        }
        cout << "\n";
    }*/
    return D[n][m];
}
//code finds the number of changes that need to be made to the first string w to convert it to w
int main()
{
    string w,x;
    cin >> w >> x;
    int a = w.length(),b=x.length();
    char p[a];
    for(int i=0;i<a;i++)
        p[i] = w.at(i);
    char q[b];
    for(int i=0;i<b;i++)
       q[i] = x.at(i);
    cout << edit(p,q,a,b) << endl;
    return 0;
}

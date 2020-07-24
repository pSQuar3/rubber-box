#include <iostream>
#include <string>
using namespace std;
int n,d[14];
char op[13];

int M[14][14],m[14][14];
int mx=0,mn=0;
int calculate(int a,int b,int c)
{
    int cal=0;
    if(op[b] == '+')
        cal = a+b;
    if(op[b] == '-')
        cal=a-b;
    if(op[b] == '*')
        cal=a*b;
    if(op[b] == '/')
        cal=a/b;
    return cal;
}
void MinandMax(int i,int j)
{
    int k,mx = 30,mn=-1,a,b,c,d,u[2];
    for(k=i;k<=j-1;k++)
    {
        a = calculate(M[i][k],k,M[k+1][j]);
        b = calculate(M[i][k],k,m[k+1][j]);
        c = calculate(m[i][k],k,M[k+1][j]);
        d = calculate(m[i][k],k,m[k+1][j]);
        mx = max(a,max(b,max(c,d)));
        mn = min(a,max(b,max(c,d)));
    }
}
int parenthesis()
{
    for(int i=0;i<=n-1;i++)
    {
        m[i][i] = d[i];
        M[i][i] = d[i];
    }
    int h[2];
    int j=0;
    for(int s=0;s<n-1;s++)
    {
        for(int i=0;i<n-s;i++)
        {
            j = i+s;
            MinandMax(i,j);
            M[i][j] = mx;
            m[i][j] = mn;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    return M[0][n-1];
}

int main()
{
    string s;
    cin >> s;
    n = s.length();
    char c[n];
    for(int i=0;i<n;i++)
    {
        c[i] = s.at(i);
        cout << c[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0)
            d[i/2] = (int)c[i]-48;
        else
            op[i-1] = c[i];
    }
    //n = (n-1)/2;
    cout << "printing the arrays read:"<<endl;
    for(int i=0;i<=n/2;i++)
        cout << d[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++)
        cout << op[i] << " ";
    //cout << endl;
    cout << parenthesis();
    return 0;
}

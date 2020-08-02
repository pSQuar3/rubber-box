#include <iostream>
#include <bits/c++io.h>
#include <new>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
long int value[10001][301];
int knapsack(int *s,int W,int n)
{
    //long int value[W+1][n+1];
    for(int j=0;j<n+1;j++)
        value[0][j] = 0;
    for(int j=0;j<W+1;j++)
        value[j][0] = 0;
    for(int i=1;i<=n;i++)
    {
        long int val=0;
        for(int w=1;w<=W;w++)
        {
            value[w][i] = value[w][i-1];
            if(s[i-1] <= w)
            {
                val = value[w-s[i-1]][i-1] + s[i-1];
                if(value[w][i] < val)
                    value[w][i] = val;
            }
            
        }
    }
    /*
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            cout << value[w][i] << " ";
        }
        cout << endl;
    }
    */
    return value[W][n];
}
/*int ssd(int *s,int W,int n)
{
    long int v[n+1];
    
}*/
void randNum()
{
    int W,n;
    int g=4;
    W = pow(10,g);
    //W = 4000;
    n = 300;
    srand(time(0));
    int a[n];
    cout << W << " " << n << endl;
    cout << "weights of gold bars: ";
    for(int i=0;i<n;i++)
    {
        a[i] = rand()%((int)pow(10,g));
        cout << a[i] << " ";
    }
    cout << "\ninitialised values\nnow proceeding to the function call\n\nSOLUTION: ";
    cout << knapsack(a,W,n) << endl;
}
int main()
{
    int n,W;
    cin >> W >> n;
    int w[n];
    for(int i=0;i<n;i++)
        cin >> w[i];
    cout << knapsack(w,W,n) << endl;
    //randNum();
    return 0;
}

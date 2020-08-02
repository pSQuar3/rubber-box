#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int n,mx=0,mn=0,mxI=0,mnI=0;
    cin >> n;
    long long int a[n];

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(i == 0)
        {
            mx = a[i];
            mn = a[i];
        }
        else
        {
            
            if(mx < a[i])
            {
                mx = a[i];
                mxI = i;
            }
            if(mn > a[i])
            {
                mn = a[i];
                mnI = i;
            }
        }
    }
    //calculated the maximum and minimum of the elements
    //not find the second highst
    long long int secMax=mn, secMin=mx, answer=0;
    if(n > 2)
    {
        for(long long int i=0;i<n;i++)
        {
            if((i != mnI)&&(i != mxI))
            {
                if(a[i] <= secMin)
                {
                    secMin = a[i];
                }
                if(a[i] >= secMax)
                {
                    secMax = a[i];
                }
            }
        }
        //cout << "maxDiff = " << maxDiff << "; minDiff  = " << minDiff << endl;   
        //cout << "secMax = " << secMax << "; secMin  = " << secMin << endl;
        answer = max(mn*secMin,mx*secMax);
        //cout << "answer = ";
    }
    if((n <= 2)&&(n > 0))
    {
        answer = 1;
        for(long long int i=0;i<n;i++)
            answer *= a[i];
    }
    if(n == 0)
        answer = 0;
    cout << answer << endl;
    return 0;
}

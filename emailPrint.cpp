#include <iostream>
#include <bits/c++io.h>
#include <new>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool checkSame(char *a, char *b, int lna, int lnb)
{
    bool h = true;
    if(lna == lnb)
    {
        int ind = 0;
        while((ind < lna)&&(h == true))
        {
            cout << "checkSame called: a[" << ind << "] = " << a[ind] << " b[" << ind << "]" << endl;
            if(*a != *b)
                h = false;
            ind++;
            a++;
            b++;
            cout << "h = " << h << endl;
        }
    }
    return h;
}
bool checkLess(int *a, int *b, int lna, int lnb)
{
    bool h = true;
    if(lna == lnb)
    {
        int ind = 0;
        while((ind < lna)&&(h == true))
        {
            cout << "checkless called: a[" << ind << "] = " << a[ind] << " b[" << ind << "]" << endl;
            if(*a > *b)
                h = false;
            ind++;
            a++;b++;
            cout << "h = " << h << endl;
        }
    }
    return h;
}

int main()
{
    int n;
    cin >> n;
    string cd[n];
    for(int i=0;i<n;i++)
    {
        string s,t;
        cin >> s >> t;
        char Sc[s.length()];
        char Tc[t.length()];
        int cS[s.length()];
        int cT[s.length()];
        int j=0;
        // inserting the elements of the strings into the arrays
        for(auto i=s.begin();i < s.end();i++)
        {
            if(j > 0)
            {
                if(*i == Sc[j-1])
                {
                    Sc[j] = *i;
                    cS[j] = 1;
                    j++;
                }
                else
                {
                    cS[j-1]++;
                }
            }
            else
                Sc[0] = *i;
        }
        // inserting the elements of the strings into the arrays
        j = 0;
        for(auto i=t.begin();i < t.end();i++)
        {
            if(j > 0)
            {
                if(*i != Tc[j-1])
                {
                    Tc[j] = *i;
                    cT[j] = 1;
                    j++;
                }
                else
                {
                    cT[j-1]++;
                }
            }
            else
                Tc[0] = *i;
        }
        //check arrays Sc[] and Tc[] for equality
        if(checkSame(Sc,Tc,s.length(),t.length()))
        {
            if(checkLess(cS,cT,s.length(),t.length()))
                cd[i] = " YES";
            else
                cd[i] = "NO";
        }
        else
            cd[i] = "NO";
    }
    for(int i=0;i<n;i++)
        cout << cd[i] << " ";
    return 0;
}

#include <iostream>
#include <bits/c++io.h>
#include <new>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string cd[n];
    for(int i=0;i<n;i++)
    {
        cd[i] = "NO";
        string s,t;
        cin >> s >> t;
        char Sc[s.length()];
        char Tc[t.length()];
        int cS[s.length()];
        int cT[s.length()];
        int lenS=0;
        if(s.length() <= t.length())
        {
            // inserting the elements of the strings into the arrays
            for(auto i=s.begin();i < s.end();i++)
            {
                if(lenS > 0)
                {
                    if(*i == Sc[lenS-1])
                    {
                        Sc[lenS] = *i;
                        cS[lenS] = 1;
                        lenS++;
                    }
                    else
                        cS[lenS-1]++;
                }
                else
                    Sc[0] = *i;
            }
            // inserting the elements of the strings into the arrays
            int lenT = 0;
            for(auto i=t.begin();i < t.end();i++)
            {
                if(lenT > 0)
                {
                    if(*i != Tc[lenT-1])
                    {
                        Tc[lenT] = *i;
                        cT[lenT] = 1;
                        lenT++;
                    }
                    else
                        cT[lenT-1]++;
    
                }
                else
                    Tc[0] = *i;
            }
            //check arrays Sc[] and Tc[] for equality
            // if equal then check arrays cT and cS for equality
            if(lenS == lenT)
            {
                cerr << "Entered left if block" << endl;
                int k=0;
                while(Sc[k] == Tc[k])
                {
                    cerr << "first while loop with k = " << k << endl;
                    k++;
                    if(k == lenS)
                        break;
                }
                cerr << "Got out of first while loop with k = " << k << endl;
                if(k == lenS)
                {
                    cerr << "Entered second if block with lenS = " << lenS << endl;
                    k = 0;
                    while(cS[k] <= cT[k])
                    {
                        cerr << "second while block with k = " << k << endl;
                        k++;
                        if(k == lenS)
                            break;
                    }
                    if(k == lenS)
                        cd[i] = "YES";
                }
            }
            cerr << "Exited if statement" << endl;
        }
    }
    cout << "printing" << endl;
    for(int i=0;i<n;i++)
        cout << cd[i] << " ";
    return 0;
}

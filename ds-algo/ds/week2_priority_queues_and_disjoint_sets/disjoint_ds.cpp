#include <iostream>
#include <bits/c++io.h>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct storeSet
{
    vector<int> set;
    int key;
    storeSet()
    {
        key = 0;
    }
    void insertElements(int x)
    {
        if(set.empty())
            key = x;
        else
            key = min(key,x);
        set.push_back(x);
    }

};

int main()
{
    int n,l,x,tot=0;
    cout << "Enter number of sets: ";
    cin >> n;
    vector<storeSet> sets;
    for(int i=0;i<n;i++)
    {
        storeSet ob;
        cout << "Enter length of first set: ";
        cin >> l;
        tot += l;
        for(int k=0;k<l;k++)
        {
            cin >> x;
            ob.insertElements(x);
        }
        sets.push_back(ob);
    }
    return 0;
}

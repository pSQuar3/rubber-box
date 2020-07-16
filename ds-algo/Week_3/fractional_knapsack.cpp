#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,cap,lastStored=0;
    cin >> n >> cap;
    priority_queue<int> pq;
    unordered_map<int,int> mp; //to map the value per unit weight to the total weight of the stuff
    bool isSorted=true;
    int ph[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin >> ph[i] >> val[i];
        ph[i] /= val[i];
        mp[ph[i]] += val[i];
    }
    for(auto i = mp.begin();i != mp.end();i++)
    {
        pq.push(i->first);
    }
    //map<int,int>::iterator it = mp.begin();
    int net=0,count=0;
    while(pq.empty() == false)
    {
        int k = pq.top();
        pq.pop();
        int W = mp[k];
        int h = min(mp[k],cap);
        cap = cap - h;
        net += h*k;
        count++;
        pq.pop();

        cout << "values read = " << k << " " << W << endl;
    }
    cout << count;
    return 0;
}

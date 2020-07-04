/*
 * https://codeforces.com/problemset/problem/1374/D
 */
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int answers[t];
    for(int i=0;i<t;i++)
    {
        int n,k;
        cin >> n >> k;
        int a[n];
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if((a[i]%k != 0)&&(a[i] >= k))
                a[i] = k-(a[i]%k);
            else
                a[i] = (a[i]%k);
            // inserting the elements into the unordered map
            mp[a[i]] += 1;
        }
        int x=0;
        //following is a code snippet:
        int countOps=0;
        /*
        for(auto i=mp.begin();i != mp.end();i++)
        {
            //cout << "Key = " << i->first << "; Value = " << i->second << endl;
            //find the element in mp with the key value i
            i->second -= 1;
            if(i->second > 0)
            {
                mp.insert(make_pair(k+ (i->first),i->second));
            }
            x = i->first;
        }
        */
        for(auto i = mp.begin();i != mp.end();i++)
        {
            
        }
        answers[i] = x;
    }
    for(int p=0;p<t;p++)
        cout << answers[p] << endl;
    return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n,found=0;
    unordered_map<int,int> mp;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    unordered_map<int,int>::iterator it;
    for(it = mp.begin();it != mp.end();it++)
    {
        if(it->second > n/2)
            found = 1;
    }
    cout << found;
    return 0;
}

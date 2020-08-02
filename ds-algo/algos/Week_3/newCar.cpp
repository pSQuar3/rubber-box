#include <iostream>
#include <map>
using namespace std;

int main()
{
    int d,m,n,a,b;
    cin >> d >> m >> n;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        a = a/b;
        mp[a] += b;
    }
    //  mp: hashmap to map the value per unit weight with the corresponding number of items
    return 0;
}

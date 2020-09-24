#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long
#define MX 100000

using std::cin;
using std::cout;
using std::cerr;
using std::floor;
using std::ios_base;
using std::unordered_map;
using std::endl;
using std::priority_queue;
using std::vector;
int n;
long long a[MX];//to hold the prices
long long newA[MX];
void calculate()
{
    auto cmp = [](long long x, long long y){
        return x < y;
    };
    priority_queue<long long, vector<long long>, decltype(cmp)> prq(cmp);
//    priority_queue<long long> prq;
    for(int i=0;i<n;i++)
    { 
        if(prq.size() < floor(n/2))
            prq.push(a[i]);
        if(prq.size() >= floor(n/2) && prq.top() > a[i])
        {
            prq.pop();
            prq.push(a[i]);
        }
    }
    unordered_map<long long, int> mp;
    int i;
    for(i=1;i<n;i = i+2)
    {
        
        newA[i] = prq.top();
        mp[newA[i]] = i;
        prq.pop();
    }
    int srnt = 0;
    i = 0;
    while(i < n)
    {
        while(mp.find(a[i]) != mp.end())
        {
            i++;
        }
        newA[srnt] = a[i];
        srnt++;
        i++;
    }
    for(i=0;i < n;i++)
        cout << newA[i] << " ";
    //partition into halves and merge 2 halves

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    calculate();
    return 0;
}

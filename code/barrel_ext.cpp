#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long
#define MX 100000

using std::cin;
using std::cout;
using std::cerr;
using std::floor;
using std::ceil;
using std::vector;
using std::unordered_map;
using std::map;
using std::endl;
using std::stack;
using std::queue;
using std::max;
using std::min;
using std::deque;
using std::priority_queue;
using std::bitset;
using std::set;
using std::sort;
using std::hash;
using std::pair;
using std::make_pair;
using std::string;
using std::swap;
using std::hash;
int t,n,k;
lli a[2*MX];
void solve()
{
    auto cmp = [](lli left, lli right)
    {
        return(left > right || left == right);
    };
    priority_queue<int,vector<int>, decltype(cmp)> heap(cmp);
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if((int)heap.size() < k+1)
            heap.push(a[i]);
        else
        {
            if(heap.top() < a[i])
            {
                heap.pop();
                heap.push(a[i]);
            }
        }
    }
    lli sum=0;
    while(!heap.empty())
    {
        sum += heap.top();
        heap.pop();
    }
    cout << sum << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int i=0;i<t;i++)
        solve();
    return 0;
}

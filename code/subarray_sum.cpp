#include <bits/stdc++.h>
#define cn cout << "\n"
#define lli long long int
#define ull unsigned long long int
/*
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::floor;
using std::ceil;
using std::vector;
using std::unordered_map;
using std::map;
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
*/
using namespace std;
const int MX = 100000;
int n,k;
//int D[MX+1][MX+1];
//int D[MX+1];
int a[MX];

inline void solve()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    if(n == 0)
        return;
    int current_sum=a[0];
    int left=0;
    int right=1;
    while(right < n && left <= right)
    {
        if(current_sum + a[right] < k)
        {
            current_sum += a[right];
            right = right + 1;
        }
        else if(current_sum +a[right] > k)
        {
            current_sum -= a[left];
            left = left + 1;
        }
        else
            break;
    }
    for(int i=left;i<=right;i++)
        cout << a[i] << " ";
    cn;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t-- > 0)
        solve();
    return 0;
}

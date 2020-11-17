#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long int

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
const int MX = 100000;
int a,b,p;
//int D[MX+1][MX+1];
int D[MX+1];
//int a[MX];
string s;
int solve()
{
    cin >> a >> b >> p;
    cin >> s;
    int n = (int)s.size();
    int i = n-1;
    cerr << "string = " << s << endl;
    cerr << "a = " << a << " b = " << b << " p = " << p << endl;
    D[i] = p;
    cerr << "D[" << i << "] = " << D[i] << endl;
    if(p < min(a,b))
        return n;
    while(i > 0)
    {
        D[i-1] = D[i];
        if(s[i] == 'B' && s[i-1] == 'A')
            D[i-1] -= a;
        if(s[i] == 'A' && s[i-1] == 'B')
            D[i-1] -= b;
        i--;
        cerr << "D[" << i << "] = " << D[i] << endl;
    }
    int j=1;
    while(D[j-1] <= 0)
        j++;
//    if(D[j-2] == 0)
//        return j-1;
    return j;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t-- > 0)
        cout << solve() << endl;
    return 0;
}

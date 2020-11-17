#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long int

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
//using std::floor;
//using std::ceil;
//using std::vector;
//using std::unordered_map;
//using std::map;
//using std::stack;
//using std::queue;
//using std::max;
using std::min;
//using std::deque;
//using std::priority_queue;
//using std::bitset;
//using std::set;
//using std::sort;
//using std::hash;
//using std::pair;
//using std::make_pair;
using std::string;
//using std::swap;
const int MX = 100000;
int a,b,p;
int D[MX+1];
string s;

int solve()
{
    cin >> a >>b >> p;
    cin >> s;
    int i = (int)s.size(),x=min(a,b);
    D[(int)s.size()] = p;
//    cerr << "a = " << a << " b = " << b << " p = " << p << endl;
    if(p < min(a,b) || p == 0)
        return i;
    else if(p == a && i > 0 && s[i-1] == 'A')
        return i-1;
    else if(p == b && i > 0 && s[i-1] == 'B')
        return i-1;
    while(D[i] > 0 && i>1)
    {
//        cerr << "D[" << i << "] = " << D[i] << endl;
        if(s[i-2] == 'A' && s[i-1] == 'B')
            D[i-1] = D[i]-a;
        else if(s[i-2] == 'B' && s[i-1] == 'A')
            D[i-1] = D[i] - b;
        else
            D[i-1] = D[i];
        i--;
    }
    if(D[i] <= 0)
        i++;
    return i;
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

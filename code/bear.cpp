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
int n,q;
bitset<6> cs;

void incrementBitset()
{
    long k = cs.to_ulong()+1;
    cs = bitset<6>(bitset<6>(k).to_string());
}
void call()
{
    for(int i=0;i<7;i++)
    {
        cout << i << " = " << cs << endl;
        incrementBitset();
    }
}


void solve()
{
    cerr << "meow\n";
    call(); 
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

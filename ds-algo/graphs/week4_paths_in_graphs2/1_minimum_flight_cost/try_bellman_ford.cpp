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
using std::ios_base;
using std::unordered_map;
using std::map;
using std::endl;
using std::stack;
using std::queue;
using std::max;
using std::min;
using std::deque;
using std::bitset;
using std::set;
using std::sort;
using std::hash;
using std::pair;
using std::make_pair;
using std::string;
using std::swap;
using std::hash;

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
//currently mapped s: pair<any dt,any dt>->bool with custom hash function as hash_pair
//change data types of pair and mapped value accordingly
int n,m;
unordered_map<pair<int,int>,long long, hash_pair> sep_pair;
unordered_map<int,vector<int>> adj;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        long long w;
        cin >> x >> y >> w;

    }
    return 0;
}

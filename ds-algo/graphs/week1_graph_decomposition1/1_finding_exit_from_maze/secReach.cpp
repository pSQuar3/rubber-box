#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::ios;
using std::unordered_map;
using std::vector;
using std::pair;
using std::make_pair;
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
unordered_map<pair<int,int>,bool,hash_pair> mp;

void solve()
{
    
}
int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

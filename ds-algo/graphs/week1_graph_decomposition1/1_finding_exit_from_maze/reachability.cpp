#include <bits/stdc++.h>
#include <functional>
#include <utility>
#include <iostream>
#define two_space(a,b), cout << a << " " << b << endl;
#define one_line(k), cout << k << endl;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ios;
using std::unordered_map;
using std::pair;
using std::make_pair;
using std::hash;
int n,m,x,y;
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
void solve()
{
    cin >> n >> m;
    unordered_map<pair<int,int>,bool,hash_pair> chk;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        chk[make_pair(x,y)] = true;
    }
    cin >> x >> y;
    if(chk.find(make_pair(x,y)) != chk.end())
        cout << "1" << endl;
    else
        cout << "0" << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

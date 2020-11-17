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
int n;
//int D[MX+1][MX+1];
//int D[MX+1];
//int a[MX];
string s;
struct Node
{
    char c;
    Node *zero,*one;
};

void createTree(vector<pair<int,char>> v)
{
    Node *root;
    root->c = '$';
    unordered_map<char,int> cd;
    for(vector<pair<int,char>>::iterator it = v.begin();it != v.end();it++)
    {
        root->one = new Node();
        root->one->c = it->second;
        cd[it->second]
    }
}


inline void solve()
{
    cin >> s;
    n = s.length();
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++)
        mp[s[i]]++;
    vector<pair<int,char>> p;
    for(unordered_map<char,int>::iterator it = mp.begin();it != mp.end();it++)
    {
        p.push_back(make_pair(it->second,it->second));
    }
    auto cmp = [](pair<int,char> left, pair<int,char> right)
    {
        return(left.first >= right.first);
    };
    sort(p.begin(),p.end());
    
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

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
int n,m;
vector<vector<int>> gph;
vector<vector<int>> cost;
/*
 * what we need in the end: graph -> with some edges removed
 */

void prim(int start)
{
    auto cmp = [](pair<int,ull> left, pair<int,ull> right)
    {
        return(left.second > right.second || left.second == right.second);
    };
    priority_queue<pair<int,ull>, vector<pair<int,ull>>, decltype(cmp)> min_heap(cmp);
    
    /* 
     * select node 0
     * find the smallest node in it
     */
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}

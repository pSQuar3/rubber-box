#include <bits/stdc++.h>
#define sp2(a,b), cout << a << " " << b << endl;
#define sp1(k), cout << k << endl;
using std::cin;
using std::cout;
using std::vector;
using std::ios_base;
using std::unordered_map;
using std::map;
using std::endl;
unordered_map<int, vector<int>> gph;
int n;
bool checkSpruce(int i)
{
    //check with BFS, not DFS. count the number of leaves
    bool b = false;
    if(gph[i].size() == 0 || gph[i].size() >= 3 || (i == 1 && gph[1].size() >= 2))
        b = true;
    for(auto h=gph[i].begin();b && h != gph[i].end();h++)
    {
        b = checkSpruce(*h);
    }
    return b;
}
void solve()
{
    cin >> n;
    int x;
    for(int i=1;i<n;i++)
    {
        cin >> x;
        gph[x].push_back(i+1);
    }
    cout << "output = " << checkSpruce(1) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

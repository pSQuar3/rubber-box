#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long int
/*
    Implementation of the Knuth-Morris-Pratt Algorithm for finding a patters in a string
    Time Complexity: O(|t| + |p|) (linear)
    Space Complexity: O(|t| + |p|)
*/
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
const int MX = 100000;
int n,len_pat;
//int D[MX+1][MX+1];
//int D[MX+1];
//int a[MX];
int s[MX];//contains the prefix function
string p;
string t;
void prefix_function()
{
    s[0] = 0;
    int border = 0;
    int h = (int)p.size();
    //  linear time, not quadratic
    for(int i=1;i<=h-1;i++)
    {
        while(border > 0 && p[i] != p[border])
            border = s[border-1];
        if(p[i] == p[border])
            border++;
        else
            border = 0;
        s[i] = border;
    }
    /*cerr << "Printing the prefix function" << endl;
    for(int i=0;i<n;i++)
        cerr << s[i] << " ";
    cerr << endl;*/
}
vector<int> knuth_morris_pratt()
{
    cin >> t >> p;
    n = (int)p.size();
    p = p + "$" + t;
    prefix_function();
    int tot = (int)p.size();
    vector<int> result;
    for(int i = n+1; i < tot; i++)
    {
        if(s[i] == n)
            result.push_back(i-2*n);
    }
    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int d = 1;
    //cin >> t;
    while(d-- > 0)
    {
        vector<int> res = knuth_morris_pratt();
        for(int i=0;i<(int)res.size();i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

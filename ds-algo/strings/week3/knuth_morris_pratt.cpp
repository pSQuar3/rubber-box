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
const int MX = 2000000;
int n,len_pat;
long long s[MX];
string p;
string t;
inline void prefix_function()
{
    s[0] = 0;
    long long border = 0;
    long long h = (long long)p.size();
    for(long long i=1;i<=h-1;i++)
    {
        while(border > 0 && p[i] != p[border])
            border = s[border-1];
        if(p[i] == p[border])
            border++;
        else
            border = 0;
        s[i] = border;
    }
}
inline void knuth_morris_pratt()
{
    cin >> p >> t;
    n = (long long)p.size();
    p = p + "$" + t;
    prefix_function();
    long long tot = (long long)p.size();
    for(long long i = n+1; i < tot; i++)
    {
        if(s[i] == n)
            cout << (i-2*n) << " ";
    }
    cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int d = 1;
    //cin >> t;
    while(d-- > 0)
    {
        
        knuth_morris_pratt();
        /*
        for(int i=0;i<(int)res.size();i++)
            cout << res[i] << " ";
        cout << endl;
        */
    }
    return 0;
}

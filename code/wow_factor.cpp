#include <bits/stdc++.h>
//eduRev apur payer chaap
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
string s;

void solve()
{
    int vv1_count=0,o_count=0,vv2_count=0;
    int D[s.length()+1];
    D[0] = 0;
    for(int i=1;i<=(int)s.length();i++)
    {
        D[i] = D[i-1];
        char c = s[i-1];
        if(c == 'v')
        {
            if(o_count == 0)
                vv1_count++;
            else
                vv2_count++;
        }
        if(c == 'o')
        {
            if(vv2_count == 0)
                o_count++;
            else
            {
                if(vv2_count <=1)
                    vv2_count = 0;
                else
                {
                    //calculate value
                    D[i] += (vv1_count-1)*o_count*(vv2_count-1);
                    vv1_count = vv2_count;
                    o_count = 0;
                    vv2_count = 0;
                }
            }
        }
        cerr <<  c << "-> i = " << (i-1) << " vv1 = " << vv1_count << " o_count = " << o_count << " vv2 = " << vv2_count << " D[" << i << "] = " << D[i] << endl;
    }
    if(D[s.length()] == 0)
        D[s.length()] = (vv1_count-1)*o_count*(max(0,vv2_count-1));
    cout << D[s.length()];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    solve();
    return 0;
}

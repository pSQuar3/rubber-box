#include <bits/stdc++.h>

#define lli long long int
#define ull unsigned long long int

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::min;
using std::string;
const int MX = 100000;
int a,b,p;
int D[MX+1];
string s;
int solve()
{
     cin >> a >>b >> p;
    cin >> s;
    cerr << "string: " << s << endl;
    int i = (int)s.size();//int x=min(a,b);
    D[(int)s.size()] = p;
    D[0] = 0;
//    cerr << "a = " << a << " b = " << b << " p = " << p << endl;
    if(p < min(a,b) || p == 0)
        return i;
//    else if(p == a && i > 0 && s[i-1] == 'A')
//        return i-1;
//    else if(p == b && i > 0 && s[i-1] == 'B')
//        return i-1;
    cerr << "D[" << i << "] = " << D[i] << endl;
    while(D[i] > min(a,b) && i>1)
    {
        if(s[i-1] == 'A')
        {
            if(s[i-2] == 'A')
                D[i-1] = D[i];
            else if(s[i-2] == 'B')
                D[i-1] = D[i] - b;
        }
        if(s[i-1] == 'B')
        {
            if(s[i-2] == 'A')
                D[i-1] = D[i] - b;
            else if(s[i-2] == 'B')
                D[i-1] = D[i];
        }
        /*
        D[i-1] = D[i];
        if(s[i-2] == 'A' && s[i-1] == 'B')
            D[i-1] -= a;
        else if(s[i-2] == 'B' && s[i-1] == 'A')
            D[i-1] -= b;
            */
        cerr << "D[" << (i-1) << "] = " << D[i-1] << endl;
        i--;
    }
    if(D[i] <= 0)
        i++;
    return i;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t-- > 0)
        cout << solve() << endl;
    return 0;
}

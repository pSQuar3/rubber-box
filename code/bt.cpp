#include <bits/stdc++.h>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::bitset;
bitset<45> kb;
int main()
{
    kb[0] = 1;
    kb[5] = 1;
    cout << (1 << 21) << endl;
    cout << kb.to_ulong() << endl;
    return 0;

}

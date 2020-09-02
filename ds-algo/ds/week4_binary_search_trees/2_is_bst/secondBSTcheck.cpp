#include <bits/stdc++.h>
using namespace std;
#define MX 100001
int k[MX],l[MX],r[MX],it[MX];
static int n, indx=0;
bool hellow(int i, int mn, int mx)
{
    //cout << "node read = " << k[i] << " i = " << i << endl;
    if(i==-1)
        return true;
    if(k[i] < mn || k[i] >= mx)
        return false;
    return hellow(l[i],mn,k[i])&&hellow(r[i],k[i],mx);
}
void in_order(int ind)
{
    if(ind > -1 && ind < n)
    {
        it[indx] = k[indx];
        indx++;
        if(l[ind] != -1)
            in_order(l[ind]);
        if(r[ind] != -1)
            in_order(r[ind]);
    }
}
int left(int i)
{
    return 2*i+1;
}
bool leftCompare()
{
    /*
    if(l[i] != -1 && k[l[i]] == k[i])
        return false;
    if(l[i] == -1 && r[i] == -1)
        return true;
    return leftCompare(l[i])&&leftCompare(r[i]);
    */
    in_order(0);
    for(int i=0;i<floor((double)log(n)/log(2));i++)
    {
        //cout << "read = " << it[i] << endl;
        if(it[left(i)] >= it[i])
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> k[i] >> l[i] >> r[i];
    bool h = (n == 0 || n == 1)? true:hellow(0,INT_MIN,INT_MAX);
    //if(h && n > 1)
    //    h = leftCompare();
    cout << ((h == true)? "CORRECT":"INCORRECT") << endl;
    return 0;
}

#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
//  problem 2: this code prints the number of operations required correctly
//  problem occurred: cannot print the sequence of integers aftter every operation
//  possible solution: can create an unordered map to store sequence of operations needed after each operation:
//  example: 
//
//  mp[1] = "";
//  mp[2] = "2"; <- (1*2)
//  mp[2] = "3"; <- (1*3)
//  mp[4] = "22"; <- (1*2)*2
//  mp[5] = "221"; <- (1*2)*2+1
void findMin(int n)
{
    int a[n+1];
    a[0] = 0;
    a[1] = 0;
    unordered_map<int,string> mp;
    for(int i=2;i<=n;i++)
        a[i] = n;
    for(int i=2;i<=n;i++)
    {
        int rems[] = {n,n,n};
        if(i%3 == 0)
            rems[0] = i/3;
        rems[2] = i-1;
        if(i%2 == 0)
            rems[1] = i/2;
        a[i] = min(a[rems[0]],min(a[rems[1]],a[rems[2]]))+1;
        string k="";
        k = (mp[rems[0]].length() > mp[rems[1]].length())? mp[rems[1]]:mp[rems[0]];
        k = (k.length() > mp[rems[2]].length())? mp[rems[2]]:k;
    }
    cout << a[n] << endl;
}
int main()
{
    int n;
    cin >> n;
    findMin(n);
    return 0;
}

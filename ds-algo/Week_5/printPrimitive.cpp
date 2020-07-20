#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
//complete solution
void findMin(int n)
{
    unordered_map<int,string> m;
    for(int i=1;i<=n;i++)
        m[n] += " ";
    m[0] = "";
    m[1] = "";
    m[2] = "2";
    m[3] = "3";
    m[4] = "22";
    m[5] = "221";
    m[6] = "23";
    for(int i=6;i<=n;i++)
    {
        int k[] = {(i%3 == 0)? i/3:n,(i%2 == 0)? i/2:n};
        string op = "";
        string h = (m[i-1].length() > m[k[0]].length())? m[k[0]]:m[i-1];
        h = (h.length() > m[k[1]].length())? m[k[1]]:h;
        if(h == m[i-1])
            op = "1";
        if(h == m[k[0]])
            op = "3";
        if(h == m[k[1]])
            op = "2";
        m[i] = h + op;
    }
    cout << m[n].length() << endl;
    char ch[m[n].length()];
    for(int i=0;i<m[n].length();i++)
        ch[i] = m[n].at(i);
    int nm=1;
    cout << nm << " ";
    for(int i = 0;(i < m[n].length())&&(nm < n);i++)
    {
        if(ch[i] == '1')
            nm += 1;
        if(ch[i] == '2')
            nm *= 2;
        if(ch[i] == '3')
            nm *= 3;
        cout << nm << " ";
    }
    
}

int main()
{
    int n;
    cin >> n;
    findMin(n);
    return 0;
}

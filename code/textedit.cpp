#include <bits/stdc++.h>
using namespace std;
stack<string> stck;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int choice,k,Q;
    string s="",w="";
    cin >> Q;
    while(Q--)
    {
        cin >> choice;
        switch(choice)
        {
            case 1:
                cin >> w;
                stck.push(s);
                s = s + w;
            break;
            case 2:
                cin >> k;
                stck.push(s);
                while(k--)
                    s.pop_back();
            break;
            case 3:
                cin >> k;
                cout << s[k-1] << "\n";
            break;
            case 4:
                s = stck[stck.size() - 1];
            break;
            default:
                cout << -1 << "\n";
            break;
        }
        cout << "s = " << s << endl;
    }
    return 0;
}

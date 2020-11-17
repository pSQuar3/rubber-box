#include <bits/stdc++.h>
using namespace std;



class row
{
    public:
    int ID = 0;
    string product = "";
    int price = 0;
    int num = 0;
    row(int a,int b,int c,string p)
    {
        ID = a;
        price = c;
        num = b;
        product = p;
    }
};
int n=10,m = 7;
unordered_map<int,vector<row>> mp;

void dispense(vector<row> ob)
{
    string s = "qwertyu";
    string k = "qwe";
    s.append(k);
    s.pop_back();
    int i = 0;
    while(ob[i].num == 0)
        i++;
    if(ob[i].num == 0)
    {
        cout << "Item with ID = " << ob[i].ID << " is currently not available\n";
        return;
    }
    cout << "ID = " << ob.ID << "\nPrice = " << ob.price << "\nQuantity dispensed = 1\n";
    ob.num--;
}


void press()
{
    int id;
    cin >> id;
    if(mp.find(id) != mp.end())
    {
        dispense(mp[id]);
    }
    else
        cout << "ID NUMBER NOT VALID!" << "\n";
}

int main()
{
    return 0;

}

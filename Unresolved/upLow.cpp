#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data;
    cin >> data;
    int C_UP=0,C_DN=0;
    char cd[data.length()];
    int ind = 0;
    //counting the number of capital and small letters in the string
    for(auto i=data.begin();i<data.end();i++)
    {
        int k = (int)(*i);
        cd[ind] = (char)k;
        if((k >= 97)&&(k <= 122))
            C_DN++;
        if((k >= 65)&&(k <= 90))
            C_UP++;
        ind++;
    }
    bool v = (C_DN >= C_UP)? true:false;//if the number of small letters is larger or the number of capital letters is larger
    //  INITIALISE ITERATOR I TO POINT TO THE START OF THE ELEMENT AT THE START OF THE 
    string result = "";
    for(int i=0;i<ind;i++)
    {
        int k = (int)(cd[i]);
        if(v&&(k >= 97)&&(k <= 122))
        {
            cout << (char)(k+32);
        }
        if((!v)&&(k >= 65)&&(k <= 90))
            cout << (char)(k-32);
        //cout << cd[i] << " ";
    }
    /*for(auto i=data.begin();i<data.end();i++)
    {
        cout << *i << " ";
    }*/
    cout << "test charset:\n";
    for(char &c:data)
    {
        //int k = (int)(*c);
        cout << (string)&c << " ";
        c ^= 32;
    }
    cout << "\n";
    cout << data << endl;
    return 0;
}

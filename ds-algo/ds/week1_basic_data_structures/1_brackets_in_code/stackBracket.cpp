#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Bracket
{
    Bracket(char type, int position):
        type(type),
        position(position)
    {}
    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }
    char type;
    int position;
};
int main()
{
    string text;
    cin >> text;e
    int decree=-1;
    stack <Bracket> opb;
    for(int i=0;i<text.length();i++)
    {
        char k = text[i];
        if(k == '(' || k == '{' || k == '[')
        {
            Bracket ob(k,i);
            opb.push(ob);
        }
        if(k == '}' || k == ')' || k == ']')
        {
            if(opb.empty())
            {
                decree = i+1;
                i = text.length();
            }
            else
            {
                if(opb.top().Matchc(k) == false)
                {
                    decree = i+1;
                    i = text.length();
                }
                else
                    opb.pop();
            }
        }
    }
    if(decree == -1)
    {
        if(opb.empty())
            cout << "Success" << endl;
        else
            cout << opb.top().position+1;
    }
    else
        cout << decree << endl;
}

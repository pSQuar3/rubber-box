#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class StackElement
{
    int element;
    int currentMax;
    public:
    StackElement(int el,int m)
    {
        element = el;
        currentMax = m;
    }
    int mmaxx()
    {
        return currentMax;
    }
};

int main()
{
    int n;
    cin >> n;
    int mxCurr=0;
    stack<StackElement> st;
    vector<int> mx;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        
        if(s == "push")
        {
            int k;
            cin >> k;
            mxCurr = max(mxCurr,k);
            StackElement ob(k,mxCurr);
            st.push(ob);
        }
        if(s == "pop")
            st.pop();
        if(s == "max")
            mx.push_back(st.top().mmaxx());
    }
    for(auto i=mx.begin();i != mx.end();i++)
        cout << *i << endl;
}

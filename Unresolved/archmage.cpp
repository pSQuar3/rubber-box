#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        if(n/x < m)
        {
            m = m-n/x;
            n = n%x;
             
        }
        if(m > 0)
        {

        }
           
    }
}

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int findPosition(int i, int j, int n, int m)
{
    int count = 0;
    if((i == 0)||(i == n-1))
    {
        if((j == 0)||(j == m-1))
        {
            count = 2;
        }
        else
            count = 3;
    }
    if((j == 0)||(j == m-1))
    {
        if((i == 0)||(i == n-1))
        {
            count = 2;
        }
        else
            count = 3;
    }
    if((i > 0)&&(i < n-1)&&(j > 0)&&(j < m-1))
        count = 4;
    return count;

}


int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin >> n >> m;
        int a[n][m];
        unordered_map<int,int[2]> mp;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                cin >> a[i][j];
                //if(a[i][j] > 0)
                    
            }
        }

        //accepted input
        

        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(a[i][j] > 0)
                {
                    //statements to be executed for 
                    int f = a[j][k];
                    //check for position on corners
                    if((a[j][k] > 0)&&(findPosition(j,k,n,m) >= a[j][k])
                    {
                        //entering the counting block
                        
                    }
               }
            }
        }
    }
}

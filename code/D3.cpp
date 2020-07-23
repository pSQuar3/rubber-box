#include <iostream>
using namespace std;

int main()
{
    int a[3][3][3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
                for(int l=0;l<3;l++)
                    a[i][j][k][l] = i+j+k+l;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
                for(int l=0;l<3;l++)
                    cout << "a[i][j][k][l] = " << a[i][j][k][l] << "\n";
        }
        cout << endl;
    }

    return 0;
}

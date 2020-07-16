#include <iostream>
using namespace std;

// code to group student into a minimum number of groups such that the difference in age is at most gr

int main()
{
    int n,gr;
    std::cout << "Enter the number of elements in the array and the grouping count: " << '\n';
    cin >> n >> gr;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];

    //  write code to sort array a in ascending order -> merge sort

    int points[n][n];
    int lims[n];
    int firstLim = a[0],x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(a[i] < firstLim+gr)
        {
            points[x][y] = a[i];
            y++;
        }
        if(a[i] >= firstLim+gr)
        {
            firstLim = a[i];
            lims[x] = y;
            x++;
            y = 0;
            points[x][y] = a[i];
            y++;
        }
    }
    lims[x] = y;
    x++;
    cout << "Possible groupings:" << endl;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<lims[i];j++)
            cout << points[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

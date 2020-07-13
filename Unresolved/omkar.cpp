#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int numbers[t];
    int ends[t];
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        numbers[i] = n; 
    }
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<numbers[i];j++)
            cout << numbers[i] << " ";
        cout << endl;
    }
}

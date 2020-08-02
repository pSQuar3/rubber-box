#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{

    long long int n;
    cin >> n;
    vector<long long int> a;
    long long int k=0,sum=0;
    for(long int i=0;i<n;i++)
    {
        //cout << "i = " << i << endl;
        a.push_back(i+1);
        //cout << "initialized a[" << i << "] = " << a[i] << endl;
        sum += i+1;
        //cout << "initialized sum = " << sum << endl;
        k++;
        if(n-sum < i+2)
            break;
        //cout << "reached end of loop segment" << endl;
    }
    a[k-1] += n-sum;
    cout << k << endl;
    for(long int i=0;i<k;i++)
        cout << a[i] << " ";
    return 0;
}

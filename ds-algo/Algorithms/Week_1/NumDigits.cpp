#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    double k = log(n)/log(10);
    long numD = ceil(k);
    cout << numD;
    return 0;
}

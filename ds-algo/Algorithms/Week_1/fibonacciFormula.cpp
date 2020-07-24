#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double f = (1/sqrt(5))*(pow((1+sqrt(5))/2,n) - pow((1-sqrt(5))/2,n));
    cout << f;
    return 0;
}

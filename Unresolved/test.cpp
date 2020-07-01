#include <iostream>
#include <bits/c++io.h>
#include <new>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    string s = "HelloTestMessage";
    for(auto i=s.begin();i<s.end();i++)
        cout << (char)*i << " ";
    return 0;
}

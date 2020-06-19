#include <iostream>
#include <new>
using namespace std;
int main()
{
    //how to allocate an array
    int *p, i;
    try
    {
        p = new int [10]; // allocate 10 integer array
    }
    catch (bad_alloc xa)
    {
        cout << "Allocation Failure\n";
        return 1;
    }
    for(i=0; i<10; i++ )
        p[i] = i;
    for(i=0; i<10; i++)
        cout << p[i] << " ";
    delete [] p; // release the array
    return 0;
}

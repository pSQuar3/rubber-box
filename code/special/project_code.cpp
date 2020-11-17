#include <bits/stdc++.h>
#include <ostream>
#define PI M_PI
using namespace std;
double sigma=0.5;
double initial_radius=0.1;
double rate=0.002;
double epsilon=0.001;
double density=1.1;
int cell_count=1;
double mass(double radius)
{
    return density*(4/3)*PI*pow(radius,3);
}
double nextsize(double size)
{
    return size + rate;
}
double calculate_separation(double d,int n)
{
    
}
int main()
{
   /* 
    *   PROCEDURE:
    *   1. Initialise radius=0.1, separation=0, cell_count=1;
    *   2. push cell_count, radius and separation in csv file
    *   3. increment radius by rate.
    *   4. if radius > sigma/2, then continue; else go to step 7.
    *   5. radius = radius/2;
    *   6. cell_count *= 2;
    *   7. update separation
    *   8. go to step 2
    */
    
    return 0;
}

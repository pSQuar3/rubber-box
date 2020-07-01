//Code is most likely correct: Runs on the test cases specified in the codeforces problem

#include <iostream>
#include <bits/c++io.h>
#include <new>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int lim;
    cin >> lim;
    string decision[lim];
    for(int i=0;i<lim;i++)
    {
        string s,t;
        cin >> s >> t;
        char prev = ' ';
        int cp_s=0,cp_t=0;
        string dec = "YES"; 
        //  MAKE UP A NEW ALGO FOR DOING THIS STUFF
        //      
        //      SOLUTION = TRUE [ASSUME THAT THE STRING S WHEN TYPED OUT CAN BE MISTYPED AS T]
        //      IF LENGTH OF STRING S IS GREATER THAN T:
        //          INITIALIZE SOLUTION WITH FALSE
        //      ELSE
        //          ITERATOR A POINTS TO START OF THE STRING S, ITERATOR B POINTS TO THE START OF SRING T
        //  
        //          BASIC THING TO DO: 
        //  
        //          IF CHARACTER AT B IS THE SAME AS CHARACTER AT A EXECUTE FOLLOWING STEPS:
        //              IF THE CHARACTER AT THE INDEX NEXT TO A, I.E., A+1 IS THE SAME AS THAT OF A, THEN POP ONLY ONE ELEMENT FROM THE STRING T.
        //  
        //              ELSE, MOVE THE POINTER B TILL IT POINTS TO A CHARACTER THAT IS NOT EQUAL TO B.
        //              
        //              MOVE POINTER A TO POINT TO THE NEXT CHARACTER IN THE STRING S
        //  
        //          ELSE
        //              SET SOLUTION WITH FALSE. NO NEED TO COMPUTE ANY FURTHER SINCE MISMATCH HAS BEEN FOUND
        auto iS = s.begin();
        auto iT = t.begin();
        if(s.length() > t.length())
            dec = "NO";
        while((iT < t.end())&&(iS < s.end())&&(dec == "YES"))
        {
            if(*iS == *iT)
            {
                if(*iS == *(iS+1))
                    iT++;
                else
                    while(*iS == *iT)
                        iT++;
                iS++;
            }
            else
            {
                dec = "NO";
            }
        }
        if(iT != t.end())
            dec = "NO";



        
        decision[i] = dec;
    }
    for(int i=0;i<lim;i++)
        cout << decision[i] << " ";

    return 0;
}

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
        string sr,tr;
        //cin >> sr >> tr;
        char s[1000000];
        char t[1000000];
        cin  >> s >> t;
        /*for(auto i = sr.begin();i < sr.end();i++)
        {
            //cout << "Entered loop to push " << sr << endl;
            char k = *i;
            //cout << "Character initialized" << endl;
            s.pushC(*i);
        }
        for(auto j = tr.begin();j < tr.end();j++)
        {
            //cout << "Entered loop to push " << tr << endl;
            char k = *j;
            t.pushC(*j);
        }
        //int ind_s=s.front;ind_t = t.front,rs = s.rear,rt = t.rear;*/
        char prev = ' ';
        int cp_s=0,cp_t=0;
        string dec = "YES";
        /*while((s.front <= s.rear)&&(t.front <= t.rear)&&(dec == "YES"))
        {
            if(s.vct[s.front] == t.vct[t.front])
            {
                while(t.vct[t.front] == s.vct[s.front])
                {
                    
                    char hg = t.popLast();
                    cp_t++;
                    cout << "Character popped from t = " << hg << endl;
                    if((s.front < s.rear)&&(s.vct[s.front+1] == s.vct[s.front]))
                        break;
                }
                prev = s.popLast();
                cp_s=1;
                if(prev == s.vct[s.front])
                    cp_s++;
                cout << "Character popped from s = " << prev << endl;
            }
            if((s.vct[s.front] != t.vct[t.front])&&(prev != s.vct[s.front]))
            {
                dec = "NO";
            }
        }*/
        /*auto is = sr.begin();
        auto it = tr.begin();
        while((is < sr.end())&&(is < tr.end()))
        {

        }*/
        
        //  MAKE UP A NEW ALGO FOR DOING THIS STUFF
        //      
        //
        //      ITERATOR A POINTS TO START OF THE STRING S, ITERATOR B POINTS TO THE START OF SRING T
        //
        //      BASIC THING TO DO: 
        //
        //      IF CHARACTER AT B IS THE SAME AS CHARACTER AT A EXECUTE FOLLOWING STEPS:
        //          IF THE CHARACTER AT THE INDEX NEXT TO A, I.E., A+1 IS THE SAME AS THAT OF A, THEN POP ONLY ONE ELEMENT FROM THE STRING T.
        //
        //          ELSE, MOVE THE POINTER B TILL IT POINTS TO A CHARACTER THAT IS NOT EQUAL TO B.
        //          
        //          MOVE POINTER A TO POINT TO THE NEXT CHARACTER IN THE STRING S
        //
        //      




        
        decision[i] = dec;
    }
    for(int i=0;i<lim;i++)
        cout << decision[i] << " ";

    return 0;
}

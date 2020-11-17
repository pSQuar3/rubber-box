#include <bits/stdc++.h>
/*  Problem Statement:
 *  Given a string of lowercase english letters S of length n. You can perform any number of operations on this string.
 *  
 *  One operation is defined as follows:
 *  Pick a substring of S of size k  
 *      if this sustring is made up of only 1 distinct characterr, then delete those k characters from the string
 *      else, do not change the substring
 *
 *  Find the final string after performing infinite operations on the string
 *
 *  INPUT:  first line contains t, the number of  test cases
 *          for each of the t test cases the inputs contain integers n and k on the first line and a string of size n on the second line.
 *
 *  OUTPUT: Print the final length of  the string after infinite such operations are performed on the string
 *
 *  EXAMPLE: 
 *  
Input:
    
2
9 4
aaabccccc
18 3
qqyyyddjjjjjjasddd

Output:

5
9

 */
#define lli long long int
#define ull unsigned long long
using namespace std;
template<typename A,typename B>
inline A fpow(A x,B y){if(y<=1)return x;A k=fpow(x,y/2);k=k*k;if(y%2==1)k=k*x;return k;}
template<typename A>
inline int gcd(A a,A b){A t;while((a!=0)&&(b!=0)){t=a%b;a=b;b=t;}return a+b;}
template<typename A,typename B>
inline lli ncr(A x,B r){lli top=1,bot=1;while(r>=1){top*=(x-r+1);bot*=r--;}return top/bot;}
template<typename A>
inline pair<A,int> kadane(A x[], int n) {
    A max_so_far = -9999999999999, max_ending_here = 0; int h = 0;
    for(int i=0;i<n;i++) { max_ending_here += x[i];
        if(max_so_far < max_ending_here) { max_so_far = max_ending_here; h = i; }
        if(max_ending_here < 0) max_ending_here = 0;}
    return make_pair(max_so_far,h);
}
struct custom_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    { auto hash1=hash<T1>{}(p.first);auto hash2=hash<T2>{}(p.second);return hash1^hash2;}
};
auto comp = [](pair<int,int> left, pair<int,int> right)
{ return(left.second < right.second); };
const int MX = 100000;
int a[MX];
int sieve[MX+1],mxkq=0;
void buildSieve(int xw) { for(int i=mxkq;i<=max(xw,mxkq);i++) sieve[i] = 0;
    for(int i = max(2,mxkq); i <= xw;i++) { if(sieve[i]) continue;
        for(int j = 2*i;j <= xw;j += i) sieve[j] = i;
    } mxkq = max(mxkq,xw);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        char c[n];
        stack<char> ch;
        stack<int> freq;
        for(int i=0;i<n;i++)
            cin >> c[i];
        ch.push(c[0]);
        freq.push(1);
        for(int i=1;i<n;i++)
        {
            if(ch.top() == c[i])
            {
                int x = freq.top()+1;
                freq.pop();
                freq.push(x);
            }
            else
            {
                if(freq.top() >= k)
                {
                    int x = freq.top()%k;
                    freq.pop();
                    if(x == 0)
                        ch.pop();
                    else
                        freq.push(x);
                }
                ch.push(c[i]);
                freq.push(1);
            }
        }
        int d=0;
        if(freq.top() >= k)
        {
            int x = freq.top()%k;
            freq.pop();
            freq.push(x);
        }
        while(!freq.empty())
        {
            d += freq.top();
            freq.pop();
        }
        cout << d << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
/*
 * Problem Statement:
 * Given a bar graph with heights. Find a set ofbars such that if they are rearranged in non-deacresing
 * order, the maximum difference between the heights of 2 consecutive bars is minimized. You can remove exactly k bars from the graph
 *
 * INPUT: number of test cases t
 *        next t lines contain: an integer n on the first line denoting the size of the bars
 *                              n integers in non-decreasing order on the second line denoting the height of the bars
 * 
 * OUTPUT: Print the max. difference between the heights of 2 consecutive bars after the removal of k bars
 *
INPUT: 

2
9 3
1 1 2 3 4 4 5 6 6
9 4
1 1 2 3 4 4 5 6 6

OUTPUT:
3
2
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
        if(max_ending_here < 0) max_ending_here = 0;} return make_pair(max_so_far,h);}
struct custom_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    { auto hash1=hash<T1>{}(p.first);auto hash2=hash<T2>{}(p.second);return hash1^hash2;}
};
auto comp = [](pair<int,int> left, pair<int,int> right)
{ return(left.second < right.second); };
const int MX = 400000;
int a[MX];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t; int n,k;
    while(t--)
    {
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];// -> linear time O(n)
        int mn=INT_MAX;
        for(int j=0;j < k+1;j++)// -> O(k)
            mn = min(a[j+(n-k-1)] - a[j], mn);
        cout << mn << "\n";
    }
    return 0;
}

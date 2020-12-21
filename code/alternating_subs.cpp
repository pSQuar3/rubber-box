#include <bits/stdc++.h>
/*
Problem Statement: https://codeforces.com/problemset/problem/1343/C
Alternating Subsequence Problem:

Recall that the sequence b is a a subsequence of the sequence a if b can be derived from a by removing zero or more elements without changing the order of the remaining elements. For example, if a=[1,2,1,3,1,2,1], then possible subsequences are: [1,1,1,1], [3] and [1,2,1,3,1,2,1], but not [3,2,3] and [1,1,1,1,2].

You are given a sequence a consisting of n positive and negative elements (there is no zeros in the sequence).

Your task is to choose maximum by size (length) alternating subsequence of the given sequence (i.e. the sign of each next element is the opposite from the sign of the current element, like positive-negative-positive and so on or negative-positive-negative and so on). Among all such subsequences, you have to choose one which has the maximum sum of elements.

In other words, if the maximum length of alternating subsequence is k then your task is to find the maximum sum of elements of some alternating subsequence of length k.

You have to answer t independent test cases.


Input:

The first line of the input contains one integer t (1 ≤ t ≤ 10^4) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1 ≤ n ≤ 2x10^5) — the number of elements in a. The second line of the test case contains n integers a1,a2,…,an (−109≤ai≤109,ai≠0), where ai is the i-th element of a.

It is guaranteed that the sum of n over all test cases does not exceed 2 x 10^5 (∑n ≤ 2 x 10^5).


Output:

For each test case, print the answer — the maximum sum of the maximum by size (length) alternating subsequence of a.

 * 
 */
#define lli long long int
#define ull unsigned long long
using namespace std;
const int MX = 200000;
lli a[MX];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); int t = 1;
    cin >> t;
    while(t--)
    {
        int i,n;
        cin >> n;
        for(i=0;i<n;i++)
            cin >> a[i];
        int mp=INT_MIN,mn=INT_MIN;
        lli c=0;
        i=0;
        while(i < n)
        {
            if(a[i] < 0)
            {
                if(mp != INT_MIN)
                    c += mp;
                mp = INT_MIN;
                if(a[i] > mn)
                    mn = a[i];
            }
            if(a[i] > 0)
            {
                if(mn != INT_MIN)
                    c += mn;
                mn = INT_MIN;
                if(a[i] > mp)
                    mp = a[i];
            }
            i++;
        }
        if(mp != INT_MIN)
            c += mp;
        if(mn != INT_MIN)
            c += mn;
        cout << c << "\n";
    }
    return 0;
}

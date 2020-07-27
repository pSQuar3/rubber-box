#include <iostream>
#include <numeric>
using namespace std;
/*
int main()
{
    int n;
    cin >> n;
    int sm,a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sm += a[i];
    }
    if(sm%3 == 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
*/
// Helper function for solving 3 partition problem
// It return true if there exists three subsets with given sum
bool subsetSum(int S[], int n, int a, int b, int c)
{
	// return true if subset is found
	if (a == 0 && b == 0 && c == 0)
		return true;

	// base case: no items left
	if (n < 0)
		return false;

	// Case 1. current item becomes part of first subset
	bool A = false;
	if (a - S[n] >= 0)
		A = subsetSum(S, n - 1, a - S[n], b, c);

	// Case 2. current item becomes part of second subset
	bool B = false;
	if (!A && (b - S[n] >= 0))
		B = subsetSum(S, n - 1, a, b - S[n], c);

	// Case 3. current item becomes part of third subset
	bool C = false;
	if ((!A && !B) && (c - S[n] >= 0))
		C = subsetSum(S, n - 1, a, b, c - S[n]);

	// return true if we get solution
	return A || B || C;
}

// Function for solving 3-partition problem. It return true if given
// set S[0..n-1] can be divided into three subsets with equal sum
bool partition(int S[], int n)
{
	if (n < 3)
		return false;

	// get sum of all elements in the set
	int sum = std::accumulate(S, S + n, 0);

	// return true if sum is divisible by 3 and the set S can
	// be divided into three subsets with equal sum
	return !(sum % 3) && subsetSum(S, n - 1, sum/3, sum/3, sum/3);
}

// main function for 3-partition problem
int main()
{
	// Input: set of integers
	//int S[] = { 7, 3, 2, 1, 5, 4, 8 };
    int n;
    cin >> n;
    int sm,S[n];
    for(int i=0;i<n;i++)
    {
        cin >> S[i];
        sm += S[i];
    }
	// number of items in S	
	if (partition(S, n))
		std::cout << "1";
	else
		std::cout << "0";

	return 0;
}

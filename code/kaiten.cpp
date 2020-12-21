#include <bits/stdc++.h>
using namespace std;
const int MX = (int)1e5;
int a[MX];

int main()
{
	std::ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		for(int i=0;i<n;i++)
			cin >> a[i];
		k = k%n;
		for(int i=n-k;i<n;i++)
			cout << a[i] << " ";
		for(int i=0;i<n-k;i++)
			cout << a[i] << " ";
        cout << "\n";
	}
}

#include <iostream>
#include <unordered_map>
using namespace std;

void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}

int knapsack(int *s,int W,int n)
{
    int value[W+1][n+1];
    for(int j=0;j<n+1;j++)
        value[0][j] = 0;
    for(int j=0;j<W+1;j++)
        value[j][0] = 0;
    for(int i=1;i<=n;i++)
    {
        int val=0;
        for(int w=1;w<=W;w++)
        {
            value[w][i] = value[w][i-1];
            if(s[i-1] <= w)
            {
                val = value[w-s[i-1]][i-1] + s[i-1];
                if(value[w][i] < val)
                    value[w][i] = val;
            }
            
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            cout << value[w][i] << " ";
        }
        cout << endl;
    }
    return value[W][n];
}
int newknapsack(int *w,int W,int n)
{
    int weight[W+1],taken[n];
    for(int i=0;i<W+1;i++)
        weight[i] = 0;
    for(int i=0;i<n;i++)
        taken[i] = 0;
    bool contains[W][n];
    for(int i=0;i<W;i++)
        for(int j=0;j<n;j++)
            contains[i][j] = false;
    for(int i=1;i<W+1;i++)
    {
        int opt=0;
        for(int j=0;j<n;j++)
            taken[j] = 0;

        for(int j=n-1;j >= 0;j--)
        {
            /*
            if((taken[j] == 0)&&(weight[i-w[j]]+w[j] <= i)&&(w[j] > opt))
            {
                taken[j] = 1;
                opt = w[j];
            }*/
            if(i >= w[j])
            {
                weight[i] = max(weight[i],weight[i-w[j]] + w[j]);
                taken[j] = 1;
            }
        }
        //weight[i] = weight[i-1] + opt;
        cout << weight[i] << " ";
    }
    return weight[W];
}
int main()
{
    int W,n;
    cin >> W >> n;
    int w[n];
    for(int i=0;i<n;i++)
        cin >> w[i];
    MergeSort(w,0,n-1);
    cout << knapsack(w,W,n) << endl;
    return 0;
}

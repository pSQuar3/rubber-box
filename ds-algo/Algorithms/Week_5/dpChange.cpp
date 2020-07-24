#include <iostream>
using namespace std;
//code is correct
int change(int money,int *coins)
{
    int minCoins[money],numCoins;
    minCoins[0] = 0;
    for(int i=1;i<=money;i++)
    {
        minCoins[i] = money+1;
        for(int j=0;j<3;j++)
        {
            if(i >= coins[j])
            {
                numCoins = minCoins[i-coins[j]]+1;
                if(numCoins < minCoins[i])
                    minCoins[i] = numCoins;
            }
        }
    }
    return minCoins[money];
}
int main()
{
    int n;
    int coins[] = {1,3,4};
    cin >> n;
    cout << change(n,coins);
    return 0;
}

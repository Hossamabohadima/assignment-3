#include <iostream>
#include <algorithm>
using namespace std;
int solveDP(int *coins, int coinCount)
{
    int sum = 0;
    for (int i = 0; i < coinCount; i++)
    {
        sum += coins[i];
    }
    // isValidPart[i] indicates if coins could be divided to i and (sum - i)
    bool *isValidPart = new bool[sum];
    // 0 is always possible since one can have all coins and the other person have none
    isValidPart[0] = true;
    for (int i = 1; i < sum; i++)
    {
        isValidPart[i] = false;
    }

    for (int c = 0; c < coinCount; c++)
    {
        int coin = coins[c];
        for (int i = sum - 1; i >= coin; i--)
        {
            // if isValidPart[i - coin] means you can add the coin to (i - coin) and have i
            // i then is valid
            isValidPart[i] = isValidPart[i] || isValidPart[i - coin];
        }
    }
    // minDifference worst case is sum (if one have all and one have nothing)
    int minDifference = sum;
    for (int i = 0; i < sum; i++)
    {
        if (isValidPart[i])
        {
            // one person has i the other has sum - i
            // difference = (sum - i) - i = sum - 2i
            int difference = abs(sum - (2 * i));
            if (difference < minDifference)
            {
                minDifference = difference;
            }
        }
    }

    delete[] isValidPart;
    return minDifference;
}
int main()
{
    int problemCount;
    cin >> problemCount;
    int *answer = new int[problemCount];
    for (int problem = 0; problem < problemCount; problem++)
    {
        int coinCount;
        cin >> coinCount;
        int *coins = new int[coinCount];
        int *minDifference = new int[coinCount];
        for (int i = 0; i < coinCount; i++)
        {
            cin >> coins[i];
        }
        int difference = solveDP(coins, coinCount);
        answer[problem] = abs(difference);
        delete[] coins;
        delete[] minDifference;
    }
    for (int i = 0; i < problemCount; i++)
    {
        cout << answer[i] << endl;
    }

    delete[] answer;
}
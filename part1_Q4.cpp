#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main()
{
    int x, y, t, w, size;
    cin >> t >> w >> size;

    vector<pair<int, int>> treasures;
    for (size_t i = 0; i < size; i++)
    {
        cin >> x >> y;
        treasures.push_back({x, y});
    }
    x = t / 3 / w;
    vector<vector<int>> dp(size + 1, vector<int>(x + 1));

    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < x + 1; j++)
        {
            if (i == 0)
            {

                dp[i][j] = 0;
            }
            else if (j == 0)
            {

                dp[i][j] = 0 + dp[i - 1][j];
            }
            else
            {
                if (j - treasures[i - 1].first < 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                    dp[i][j] = max(dp[i - 1][j], treasures[i - 1].second + dp[i - 1][j - treasures[i - 1].first]);
            }
        }
    }
    w = size;
    y = x;
    int xx = dp[w][y];
    while (xx != 0)
    {
        if (xx == dp[w - 1][y])
        {
            w--;
            xx = dp[w][y];
        }
        else
        {
            treasures.push_back(treasures[w - 1]);
            y = y - treasures[w - 1].first;
            w--;
            xx = dp[w][y];
        }
    }
    cout << dp[size][x] << "\n";
    cout << treasures.size() - size << "\n";
    for (int i = treasures.size() - 1; i >= size; i--)
    {
        cout << treasures[i].first << " " << treasures[i].second << "\n";
    }
}
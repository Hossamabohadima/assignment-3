#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] > v[i])
            {
                dp[i][j] = dp[i][i] + 1;
                for (int temp = i + 1; temp < j; temp++)
                {
                    if (v[temp] < v[j])
                        dp[i][j] = max(dp[i][j], dp[i][temp] + 1);
                }
            }
        }
    }
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            maxLength = max(maxLength, dp[i][j]);
        }
    }
    cout << maxLength << endl;
}

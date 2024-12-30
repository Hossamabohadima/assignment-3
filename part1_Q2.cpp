#include <iostream>
using namespace std;

int calculatePossibilities(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
};

int main()
{
    string s;
    int result = 1;

    cout << "Enter the string: ";
    cin >> s;
    int n = s.length();

    if (n == 0 || n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'm' || s[i] == 'w')
        {
            cout << 0 << endl;
            return 0;
        }

        if (s[i] == 'u')
        {
            int count = 0;
            while (i < n && s[i] == 'u')
            {
                count++;
                i++;
            }
            i--;
            result = (result * calculatePossibilities(count)) % 1000000007;
        }

        if (s[i] == 'n')
        {
            int count = 0;
            while (i < n && s[i] == 'n')
            {
                count++;
                i++;
            }
            i--;
            result = (result * calculatePossibilities(count)) % 1000000007;
        }
    }

    cout << "Number of ways to decode the string: ";
    cout << result << endl;
    return 0;
}
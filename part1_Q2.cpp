#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int calculatePossibilities(int n)
{
    if (dp.size() <= n)
    {
        int currentSize = dp.size();
        dp.resize(n + 1, -1); // extend and initialize with -1

        for (int i = currentSize; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    return dp[n];
}

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

    dp.push_back(1);
    dp.push_back(1);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'm' || s[i] == 'w')
        {
            cout << 0 << endl;
            return 0;
        }

        if (s[i] == 'u' || s[i] == 'n')
        {
            char c = s[i];
            int count = 0;
            while (i < n && s[i] == c)
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
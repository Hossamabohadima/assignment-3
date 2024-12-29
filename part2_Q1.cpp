#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;
        int sSize = s.size();
        int gSize = g.size();
        while (child < gSize && cookie < sSize)
        {
            if (s[cookie] >= g[child])
            {
                child++;
            }
            cookie++;
        }
        return child;
    }
};

int main()
{
    Solution solution;
    int n, m;
    cout << "input size of g\n";
    cin >> n;
    vector<int> g(n);

    cout << "input g\n";
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    cout << "input size of s\n";
    cin >> m;
    vector<int> s(m);

    cout << "input s\n";
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }

    solution.findContentChildren(g, s);
}
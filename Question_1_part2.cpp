#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
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
    // int n, m;
    // cin >> n;
    // vector<int> g (n) ;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> g[i];
    // }
    // cin >> m;
    // vector<int> s (m);
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> s[i];
    // }
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    solution.findContentChildren(g, s);
}
#include <iostream>
#include <algorithm>
#include <climits>
#include "Prim.cpp"
using namespace std;
int main()
{
    int cityCount, roadCount;
    cin >> cityCount >> roadCount;
    int goldPrice, silverPrice;
    cin >> goldPrice >> silverPrice;
    for (int i = 0; i < roadCount; i++)
    {
        int x, y, g, s;
        cin >> x >> y >> g >> s;
        x--;
        y--;
    }
}
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include "Prim.cpp"
using namespace std;
struct Edge
{
    int x;
    int y; 
    int g;
    int s;
};

int main()
{
    int cityCount, roadCount;
    cin >> cityCount >> roadCount;
    int goldPrice, silverPrice;
    cin >> goldPrice >> silverPrice;
    vector<Edge> edges;
    for (int i = 0; i < roadCount; i++)
    {
        Edge edge;
        cin >> edge.x >> edge.y >> edge.g >> edge.s;
        edge.x--;
        edge.y--;
    }
}
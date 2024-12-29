#include <iostream>
#include <algorithm>
#include <climits>
int pickMinimumEdgeWeight(int currentMinimumEdgeWeights[], bool isIncludedVertix[], int numberOfVertices)
{
    int minimumValue = INT_MAX;
    int minimumIndex = -1;
    for (int i = 0; i < numberOfVertices; i++)
    {
        if (currentMinimumEdgeWeights[i] < minimumValue && !isIncludedVertix[i])
        {
            minimumValue = currentMinimumEdgeWeights[i];
            minimumIndex = i;
        }
    }
    return minimumIndex;
}
int getMstCost(int **graph, int numberOfVertices)
{
    int *currentMinimumEdgeWeights = new int[numberOfVertices];
    bool *isIncludedVertix = new bool[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        currentMinimumEdgeWeights[i] = INT_MAX;
        isIncludedVertix[i] = false;
    }
    currentMinimumEdgeWeights[0] = 0;
    for (int i = 0; i < numberOfVertices - 1; i++)
    {
        int currentVertix = pickMinimumEdgeWeight(currentMinimumEdgeWeights, isIncludedVertix, numberOfVertices);
        isIncludedVertix[currentVertix] = true;
        for (int targetVertix = 0; targetVertix < numberOfVertices; targetVertix++)
        {
            const bool edgeExist = graph[currentVertix][targetVertix] != 0;
            const bool isWeightLess = graph[currentVertix][targetVertix] < currentMinimumEdgeWeights[targetVertix];
            if (edgeExist && !isIncludedVertix[targetVertix] && isWeightLess)
            {
                currentMinimumEdgeWeights[targetVertix] = graph[currentVertix][targetVertix];
            }
        }
    }
    int mstCost = 0;
    for (int i = 0; i < numberOfVertices; i++)
    {
        mstCost += currentMinimumEdgeWeights[i];
    }

    delete[] isIncludedVertix;
    delete[] currentMinimumEdgeWeights;
    return mstCost;
}




using namespace std;
int main()
{
    int cityCount, roadCount;
    cin >> cityCount >> roadCount;
    int goldPrice, silverPrice;
    cin >> goldPrice >> silverPrice;
    int **costs = new int *[cityCount];
    for (int i = 0; i < cityCount; i++)
    {
        costs[i] = new int[cityCount];
    }
    for (int i = 0; i < cityCount; i++)
    {
        for (int j = 0; j < cityCount; j++)
        {
            costs[i][j] = 0;
        }
    }
    for (int i = 0; i < roadCount; i++)
    {
        int x, y, g, s;
        cin >> x >> y >> g >> s;
        x--;
        y--;
        int cost = g * goldPrice + s * silverPrice;
        int minCost = costs[x][y];
        if (cost < minCost || minCost == 0)
        {
            costs[x][y] = cost;
            costs[y][x] = cost;
        }
    }
    for (int i = 0; i < cityCount; i++)
    {
        for (int j = 0; j < cityCount; j++)
        {
            cout << costs[i][j] << "  ";
        }
        cout << endl;
    }
    
    int minCost = getMstCost(costs, cityCount);
    cout << minCost;
    for (int i = 0; i < cityCount; i++)
    {
        delete[] costs[i];
    }

    delete[] costs;
}
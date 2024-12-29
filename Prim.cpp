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
